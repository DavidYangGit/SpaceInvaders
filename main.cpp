#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.cpp"
#include "alien.cpp"
#include "projectile.cpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.setWindowTitle("Space Invaders");

    // set window size
//    QWidget widget;
//    widget.setMinimumSize(400, 300);
//    w.setCentralWidget(&widget);

    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    Player *player = new Player;

    scene.addItem(player);
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);

    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "SpaceInvaders"));
    view.resize(400, 300);
    view.show();

    view.show();
    return a.exec();
}
