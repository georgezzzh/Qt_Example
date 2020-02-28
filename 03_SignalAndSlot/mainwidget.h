#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
//槽函数, Qt4必须用slots关键字修饰， Qt可以不用
public slots:
    void myslot();
    void changeWin();
    void dealSignal();
    void dealSlot(int,QString);
private:
    QPushButton b;
    QPushButton* b2;
    QPushButton b3;
    SubWidget subWin;
};
#endif // MAINWIDGET_H
