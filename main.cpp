#include "mainwindow.h"

#include <QGraphicsScene>
#include <QObject>
#include <QScreen>
#include <QApplication>

#include "spaceinvaders.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    // we create an instance of the game
    CSpaceInvaders *pGame = new CSpaceInvaders(qApp->screens()[0]->size());
    // display it
    pGame->showFullScreen();
    // run it
    pGame->run();

    return a.exec();
}
