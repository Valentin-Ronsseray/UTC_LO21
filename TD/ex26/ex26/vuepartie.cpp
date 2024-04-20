#include "vuepartie.h"
#include "vuecarte.h"

VuePartie::VuePartie(QWidget *parent) : QWidget(parent), vuecartes(20, nullptr) {
    for (int i = 0; i < 20; ++i) {
        vuecartes[i] = new VueCarte;
    }
    controleur.distribuer();
    size_t i=0;
    for (auto it=controleur.getPlateau().begin(); it != controleur.getPlateau().end(); ++it, i++){
        vuecartes[i]->setCarte(*it);
    }
};
