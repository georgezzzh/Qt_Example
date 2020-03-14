#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //动态分配控件，不能指定父对象
    myT = new MyThread();
    //创建子线程
    thread = new QThread(this);
    //把自定义得线程加入到子线程中
    myT->moveToThread(thread);
    connect(myT,&MyThread::mySignal,this,&MainWindow::dealSignal);
    qDebug()<<"主线程号:"<<QThread::currentThread();
    //
    //connect第五个参数，默认的时候，如果是多线程，默认使用队列
    //如果是单线程，默认使用直接方式
    connect(this,&MainWindow::startThread,myT,& MyThread::myTimeOut);
    connect(this,&MainWindow::destroy,this,&MainWindow::dealClose);
    //线程内部不能处理GUI
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dealSignal()
{
    static int i=0;
    i++;
    ui->lcdNumber->display(i);
    //qDebug()<<"slot function";
}
void MainWindow::dealClose()
{
    //调用关闭槽函数
    on_stop_clicked();
    delete myT;
}

void MainWindow::on_start_clicked()
{
    if(thread->isRunning()) return;
    //启动线程，但是没有启动线程处理函数
    myT->setFlag(false);
    thread->start();
    //不能直接调用线程处理函数
    //直接调用导致线程处理函数和主线程是同一个线程
    //myT->myTimeOut();

    //只能通过signal-slot方式调用
    emit startThread();

}

void MainWindow::on_stop_clicked()
{
    //如果线程 没有运行，返回
    if(!thread->isRunning()) return;
    myT->setFlag(true);
    thread->quit();
    thread->wait();
}
