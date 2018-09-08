#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setMinimumSize(1160, 768);
    //w.showMaximized();
    w.show();
    return a.exec();
}
