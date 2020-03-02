#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //设置ui文件
    ui->setupUi(this);

    /*QLineEdit, 获取内容
     * */
    QString text = ui->lineEdit->text();
    //设置边距
    ui->lineEdit->setTextMargins(3,0,0,0);
    //设置显示方式
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    qDebug()<<text;
    QStringList list;
    list << "hello"<<"how are you"<<"hihi";
    //输入文本自动补全提示, 该控件不加也可以
    QCompleter *com = new QCompleter(list,this);
    //设置不区分大小写
    com->setCaseSensitivity(Qt::CaseSensitivity::CaseInsensitive);
    ui->lineEdit->setCompleter(com);
    /*
     * Qlabel设置加载图片
    */
    //设置图片, 资源文件路径在资源
    ui->labelFigure->setPixmap(QPixmap("://images/img.png"));
    //设置超链接
    ui->labelUrl->setText("<a href=\"www.baidu.com\">百度一下</a>");
    ui->labelUrl->setOpenExternalLinks(true);
    /*
     * 数码管
     */
    ui->lcdNumber->display("123");
    /*
     * 进度条
     */
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    //设置当前的值
    ui->progressBar->setValue(60);

}

MainWindow::~MainWindow()
{
    delete ui;
}


