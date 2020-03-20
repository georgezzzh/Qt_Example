#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QByteArray>
#include <QString>

#define cout qDebug().noquote()<<"["<<__FILE__<<":"<<__LINE__<<"]: "

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myWidget = new MyWidget();
    myWidget->resize(400,300);
    //设置为非模态, 不退出该窗口时，父窗口无法操作
    myWidget->setWindowModality(Qt::WindowModality::ApplicationModal);
    connect(myWidget,SIGNAL(mySignal(QString)),this,SLOT(mySlot(QString)));
}
void MainWindow::mySlot(QString str){
    cout<<"槽函数接受:"<<str;
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    myWidget->show();
}
