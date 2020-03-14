#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
protected:
    //线程处理函数
    void run() override;
signals:
    //线程任务处理完毕，发送信号
    void isDone();

};

#endif // MYTHREAD_H
