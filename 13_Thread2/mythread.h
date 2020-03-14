#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>


class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    //线程处理函数
    void myTimeOut();
    void setFlag(bool flag=true){ this->isStop=flag; }

signals:
    void mySignal();
private:
    bool isStop;
};

#endif // MYTHREAD_H
