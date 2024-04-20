#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QPushButton btn ("Quitter");
    btn.show();
    QPushButton btn2 ("coucou, ceci est un nouveau bouton à déplacer");
    btn2.show();
    btn2.move(0,0);
    QObject::connect(&btn, SIGNAL(clicked()), &app, SLOT(quit())); // Quitter quand on clique sur le bouton
    return app.exec();
}
