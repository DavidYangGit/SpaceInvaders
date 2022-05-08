#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Space Invaders");
    QWidget widget;
    widget.setMinimumSize(400, 300);
    w.setCentralWidget(&widget);
    w.show();
    return a.exec();
}
