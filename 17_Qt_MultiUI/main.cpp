#include "mainwindow.h"

#include <QApplication>
#define cout qDebug().noquote()<<"["<<__FILE__<<":"<<__LINE__<<"]:"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
