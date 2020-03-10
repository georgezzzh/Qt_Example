#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QDateTime>
#include <QDataStream>
#include <QTextStream>
#include <QBuffer>
#include <QDebug>
//定义一个调试技巧
#define cout qDebug() << "["<<__FILE__<<":"<<__LINE__<<"]"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //调用二进制写入
    writeBinary();
    readBinary();
    //调用textStream写入读出
    writeText();
    readText();
    //内存buffer
    buffer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//写二进制数据流
void MainWindow::writeBinary()
{
    QFile file("../test.txt");
    //以直写的方式打开
    bool isSuccess = file.open(QIODevice::WriteOnly);
    if(isSuccess){
        //创建数据流, 和file文件流关联
        QDataStream stream(&file);
        stream << QString("二进制文件写入")<<100;
    }
    file.close();
}
void MainWindow::readBinary()
{
    QFile file("../test.txt");
    //以直写的方式打开
    bool isSuccess = file.open(QIODevice::ReadOnly);
    if(isSuccess){
        QDataStream stream(&file);
        //读的时候按照写的时候取数据
        QString str;
        stream >> str;
        int a;
        stream >>a;
        qDebug()<<"str:"<<str<<",num:"<<a;
        cout<<str;
        cout<<a;
    }
    file.close();
}
void MainWindow::writeText()
{
    QFile file;
    file.setFileName("../demo.txt");
    bool isSuccess =file.open(QIODevice::WriteOnly);
    if(isSuccess){
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream<<QString("hello world你好世界,textStream写入");
        stream <<1000;
    }
    file.close();
}
void MainWindow::readText()
{
    QFile file;
    file.setFileName("../demo.txt");
    bool isSuccess =file.open(QIODevice::ReadOnly);
    if(isSuccess){
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        QString str;
        //textStream和dataStream不同,不是数据流，是文本流
        //不能像dataStream一样做到智能分割
        str=stream.readAll();
        cout<<str;
    }
    file.close();
}
void MainWindow::on_pushButton_clicked()
{
    //第三个参数是默认路径
    QString filePath = QFileDialog::getOpenFileName(this,"选择文件","../");
    if(!filePath.isEmpty()){
        //文件对象
        QFile file(filePath);
        bool isSuccess = file.open(QIODevice::ReadOnly);
        //获取文件信息
        QFileInfo info(filePath);
        qDebug()<<"文件名:"<<info.fileName();
        qDebug()<<"文件后缀:"<<info.suffix();
        qDebug()<<"文件大小:"<<info.size();
        //时间的格式,设置为2020-03-10: 19:55:21形式
        qDebug()<<"文件创建时间:"<<info.birthTime().toString("yyyy-MM-dd: hh:mm:ss");

        if(isSuccess){
            //读文件
            QByteArray array;
            while(!file.atEnd()){
                array += file.readLine();
            }

            //显示到编辑区
            ui->textEdit->setText(QString(array));
        }
        file.close();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"save","../","TXT(*.txt)");
    if(!path.isEmpty()){
        QFile file;
        file.setFileName(path);
        //打开文件
        bool isSuccess = file.open(QIODevice::WriteOnly);
        if(isSuccess){
            //获取编辑区的文字
            QString txt = ui->textEdit->toPlainText();
            //QString -> QByteArray  toUtf8()
            file.write(txt.toUtf8());

        }
        file.close();
    }
    /*
     * -----QByteArray -> char*----
     * QByteArray a;
     * char * b =a.data()
     * -----char* ->QString------
     * char * p="abc";
     * QString c = QString(p);
     */

}
void MainWindow::buffer()
{

    QBuffer memFile;
    //写入
    memFile.open(QIODevice::WriteOnly);
    QDataStream stream(&memFile);
    stream<<QString("hello")<<100;
    memFile.close();
    //读出
    memFile.open(QIODevice::ReadOnly);
    QString str;
    int n;
    stream>>str>>n;
    memFile.close();
    cout<<str<<n;


}
