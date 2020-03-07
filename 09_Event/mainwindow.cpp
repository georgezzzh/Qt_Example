#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QTimerEvent>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置计时器
    timerId = this->startTimer(500);
    timerId2 = this->startTimer(1000);
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        qDebug()<<"button clikcked";
    });
    //安装事件过滤器
    ui->label_2->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton){
        qDebug()<<"MainWindow: 鼠标按下左键";
    }
}
void MainWindow::keyPressEvent(QKeyEvent* ev)
{
    qDebug()<<"Key:"<<ev->key();
    if(ev->key()==Qt::Key_Meta){
        qDebug()<<"按下了Windows键";
    }

}
void MainWindow::timerEvent(QTimerEvent *ev)
{
    static int sec =0;
    sec++;
    if(ev->timerId() == this->timerId){
        ui->label->setText(QString("<center><h1>%1</h1></center>").arg(sec));
        if(sec == 10){
            //停止定时器
            this->killTimer(timerId);
        }
    }else if(ev->timerId()==this->timerId2){
        //do not stop timer
        ui->label_2->setText(QString("<center><h1>%1</h1></center>").arg(sec));
    }
}
void MainWindow::closeEvent(QCloseEvent *ev)
{
    int ret = QMessageBox::question(this,"question","需要关闭窗口吗");
    if(ret == QMessageBox::Yes){
        //accept函数, 本事件处理函数接受,不会再传递给父窗口
        //接受事件, 关闭窗口
        ev->accept();
    }else{
        //ignore函数, 本函数不接受，传递给父窗口
        //忽略事件, 不关闭窗口
        ev->ignore();
    }
    qDebug()<<"close the window";
}

/*
bool MainWindow::event(QEvent *ev)
{
    //返回true相当于时间函数处理过了,不会再传播
    if(ev->type()==QEvent::Timer){
        //需要强制类型转换
        QTimerEvent *env = static_cast<QTimerEvent*>(ev);
        //传递给timerEvent()事件函数处理
        timerEvent(env);
        return true;
    }
    else{
        //其他情况, 用到了虚函数机制,直接返回到对应的事件处理函数中
        return QWidget::event(ev);

        //return false;
    }
}
*/

//过滤器不安装时,不生效
bool MainWindow::eventFilter(QObject* obj,QEvent *e)
{
    if(obj == ui->label_2){
        //判断事件
        if(e->type() == QEvent::MouseMove){
            QMouseEvent *me = static_cast<QMouseEvent*>(e);
            ui->label_2->setText(QString("Mouse Move %1 ,%2").arg(me->x()).arg(me->y()));
            //返回true，不让事件继续传播
            return true;
        }
    }
    return QWidget::eventFilter(obj,e);
}
