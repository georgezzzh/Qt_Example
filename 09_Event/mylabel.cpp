#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>
#include <QString>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

    //设置某人追踪鼠标,不设置该属性，移动鼠标默认不计入事件
    this->setMouseTracking(true);

}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    QString btn;
    if(ev->button()==Qt::LeftButton)
        btn = "left Button";
    if(ev->button()==Qt::RightButton)
        btn = "right Button";
    QString msg = QString("<center><h1>x:%1, y:%2, %3</h1></center>").arg(i).arg(j).arg(btn);
    this->setText(msg);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{

}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    //qDebug()<<"Mouse Move.x:"<<ev->x()<<",y:"<<ev->y();
}
void MyLabel::enterEvent(QEvent *ev)
{
    qDebug()<<"The Mouse enter Window";
}

void MyLabel::leaveEvent(QEvent *ev)
{
    qDebug()<<"The mouse leave window";
}
