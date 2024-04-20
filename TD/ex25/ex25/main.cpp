#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget fenetre;
    fenetre.setFixedSize(250, 120);

    QLabel* etqNom = new QLabel ("Nom", &fenetre);
    QLabel* etq = new QLabel ("OK", &fenetre);
    // etqNom->move(10, 10);
    QLineEdit* zone = new QLineEdit (&fenetre);
    zone->setFixedWidth(180);
    // zone->move(50, 10);
    QHBoxLayout* cnom = new QHBoxLayout;
    cnom->addWidget(etqNom);
    cnom->addWidget(zone);

    QVBoxLayout* couche = new QVBoxLayout;
    couche->addLayout(cnom);
    couche->addWidget(etq);

    fenetre.setLayout(couche);
    fenetre.show();
    return app.exec();
}
