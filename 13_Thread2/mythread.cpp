#include "mythread.h"
#include <QThread>
#include <QDebug>
MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop = false;
}

void MyThread::myTimeOut()
{
    while(!isStop){
        QThread::sleep(1);
        //每隔一秒发送一个信号
        emit mySignal();

        qDebug()<<"子线程号:"
               <<QThread::currentThread();
    }
}
