#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "vuepartie.h"
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    VuePartie partie;
    partie.show();
    return app.exec();
}

