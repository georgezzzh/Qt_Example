#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>

MyButton::MyButton(QWidget *parent) :QPushButton(parent)
{

}

void MyButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton){
        qDebug()<<"MyButton: 按下是左键" ;
        //忽略, 该事件会继续传递给父组件
        ev->ignore();

    }
    //调用mousePressEvent，会继续发送信号给该组件，前面定义的信号槽会处理
    //传递给槽函数，就不会传递给父组件了
    //QPushButton::mousePressEvent(ev);
}
