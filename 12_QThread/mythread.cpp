#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}
void MyThread::run()
{
    //很复杂得数据处理，需要耗时五秒
    QThread::sleep(5);
    //发送处理完得信号
    emit isDone();
}
