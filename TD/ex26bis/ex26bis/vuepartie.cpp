#include "vuepartie.h"
#include "vuecarte.h"
#include "set.h"

VuePartie::VuePartie(QWidget *parent) : QWidget(parent), vuecartes(20, nullptr) {
    for (int i = 0; i < 20; ++i) {
        vuecartes[i] = new VueCarte;
    }
    controleur.distribuer();

    size_t i=0;
    for (auto it=controleur.getPlateau().begin(); it != controleur.getPlateau().end(); ++it, i++){
        vuecartes[i]->setCarte(*it);
    }

    setWindowTitle("Set !");
    pioche = new QLabel("Pioche");
    score = new QLabel("Score");

    nbCartesPioche = new QProgressBar;
    nbCartesPioche->setRange(0, Set::Jeu::getInstance().getNbCartes());
    nbCartesPioche->setValue(controleur.getPioche().getNbCartes());
    nbCartesPioche->setFixedHeight(30);
    nbCartesPioche->setTextVisible(true);

    scoreJoueur = new QLCDNumber;
    scoreJoueur->display(0);
    scoreJoueur->setFixedHeight(30);

    layoutInformations = new QHBoxLayout;
    layoutInformations->addWidget(pioche);
    layoutInformations->addWidget(nbCartesPioche);
    layoutInformations->addWidget(score);
    layoutInformations->addWidget(scoreJoueur); // Bloc horizontal

    layoutCartes = new QGridLayout;
    for (unsigned int i = 0; i < vuecartes.size(); ++i) {
        layoutCartes->addWidget(vuecartes[i], i/4, i%4);
        connect(vuecartes[i], SIGNAL(carteClicked(VueCarte*)), this, SLOT(carteClique(VueCarte*)));
    }

    couche = new QVBoxLayout;
    couche->addLayout(layoutInformations);
    couche->addLayout(layoutCartes);
    setLayout(couche);

};

void VuePartie::carteClique(VueCarte* vc){
    if(vc->cartePresente()){
        if(vc->isChecked()){
            selectionCartes.insert(&vc->getCarte());
            if(selectionCartes.size() == 3){
                vector<const Set::Carte*> v(selectionCartes.begin(), selectionCartes.end());
                Set::Combinaison comb(*v[0], *v[1], *v[2]);
                if(comb.estUnSET()){
                    controleur.getPlateau().retirer(*v[0]);
                    controleur.getPlateau().retirer(*v[1]);
                    controleur.getPlateau().retirer(*v[2]);
                    selectionCartes.clear();
                    if (controleur.getPlateau().getNbCartes()<12) controleur.distribuer();
                    scoreValue++;
                    scoreJoueur->display(scoreValue);
                    for (int i = 0; i < vuecartes.size(); ++i) vuecartes[i]->setNoCarte();

                    size_t i = 0;
                    for(auto it=controleur.getPlateau().begin(); it!=controleur.getPlateau().end(); ++it, i++){
                        vuecartes[i] ->setCarte(*it);
                    }
                }
                else{
                    QMessageBox message (QMessageBox::Icon::Warning, "Attention", "Ce n'est pas un set !");
                    message.exec();
                    for (unsigned int i = 0; i < vuecartes.size(); ++i) {
                        vuecartes[i] -> setChecked(false);
                        selectionCartes.clear();
                    }
                }
            }
        }
        else{
            selectionCartes.erase(&vc->getCarte());
        }
    }
    else{
        size_t n = controleur.getPioche().getNbCartes();
        if (n==0){
            QMessageBox message(QMessageBox::Icon::Warning, "Attention", "La pioche est vide !"); message.exec();
        }
        nbCartesPioche->setValue(n);
        controleur.distribuer();
        Set::Plateau pl = controleur.getPlateau();
        size_t i = 0;
        for (auto it=pl.begin(); it != pl.end(); ++it, i++){
            vuecartes[i]->setCarte(*it);
        }
        update();
    }
}
