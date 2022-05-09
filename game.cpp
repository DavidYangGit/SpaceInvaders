#include "game.h"

Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,400,300);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    player = new Player();
    player->setPos(200,200);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
}
