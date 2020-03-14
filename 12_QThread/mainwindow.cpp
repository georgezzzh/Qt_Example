#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    //只要定时器启动，自动触发timeout信号
    connect(myTimer,&QTimer::timeout,this, &MainWindow::dealTimeout);
    thread = new MyThread(this);
    connect(thread,& MyThread::isDone,this,&MainWindow::dealDone);
    //当按窗口右上角x时，触发该信号
    connect(this,&MainWindow::destroyed,this,&MainWindow::stopThread);
}
void MainWindow::dealDone()
{
    qDebug()<<"is over";
    //关闭定时器
    myTimer->stop();
}
void MainWindow::stopThread()
{
    //线程关闭
    thread->quit();
    //等待线程处理完资源
    thread->wait();
}
void MainWindow::dealTimeout()
{
    static int i=0;
    i++;
    //设定lcd得值
    ui->lcdNumber->display(i);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //如果定时器没有工作才启动
    if(myTimer->isActive() == false){
        myTimer->start(100);
    }
    //启动线程处理
    thread->start();

}
