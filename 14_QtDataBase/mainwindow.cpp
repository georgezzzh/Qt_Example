#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QDebug>
#include <QMessageBox>
#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //打印Qt支持的数据库驱动
    qDebug()<<QSqlDatabase::drivers();
    //添加SQLLITE数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //数据库文件预先存在
    db.setDatabaseName("../info.db");
    //打开数据库
    if(!db.open()){
        QMessageBox::warning(this,"false",db.lastError().text());
    }

    QSqlQuery query;

    if(!query.exec("drop table student")){
           cout<<query.lastError();
    }
    if(!query.exec("create table student(id int primary key,name varchar(255))")){
        cout<<query.lastError();
    }
    if(!query.exec("insert into student values(1,\"李华\")")){
           cout<<query.lastError();
    }
    query.exec("insert into student values(2,\"张三\")");
    //查询
    query.exec("select * from student");
    while(query.next()){
        int id=query.value(0).toInt();
        QString name = query.value("name").toString();
        qDebug()<<"id:"<<id<<",name:"<<name;
    }
    db.close();

}
MainWindow::~MainWindow()
{
    delete ui;
}

