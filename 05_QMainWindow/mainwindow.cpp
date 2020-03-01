#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,600);
    //菜单栏
    QMenuBar *mBar = menuBar();
    //添加菜单
    QMenu *pFile = mBar->addMenu("文件");
    //添加菜单项, 添加动作
    QAction* pNew=pFile->addAction("新建");
    connect(pNew,& QAction::triggered,[=](){
        qDebug()<<"新建被按下";
    });
    //添加分割线
    pFile->addSeparator();
    QAction* qNew = pFile->addAction("模态对话框");
    connect(qNew,&QAction::triggered,[](){
        QDialog dialog;
        dialog.exec();
        qDebug()<<"模态对话框退出";

    });
    QAction* q2 = pFile->addAction("非模态对话框");
    connect(q2, &QAction::triggered,[=](){
        //非模态对话框的方法
        QDialog *dialog = new QDialog(this);
        //设置关闭自动释放
        dialog->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
        dialog->show();
        //qDebug()<<"非模态对话框";

    });
    QAction *q3 = pFile->addAction("关于对话框");
    connect(q3, &QAction::triggered, [=](){
        QMessageBox::about(this,"about","Qt关于说明");
    });
    QAction *q4 = pFile->addAction("问题对话框");
    connect(q4,&QAction::triggered,[=](){
       int retn = QMessageBox::question(this,"问题对话框","你想好了吗");
       switch(retn){
        case QMessageBox::Yes:
           qDebug()<<"选择了yes"; break;
        case QMessageBox::No:
           qDebug()<<"选择了No"; break;
        default:
           qDebug()<<"选择了其他";
       }
    });
    QAction *q5 = pFile->addAction("文件对话框");
    connect(q5,&QAction::triggered,[=](){
        //第四个参数，是指定文件类型的
        QString file_name=QFileDialog::getOpenFileName(this,"打开文件","../","source(*.cpp *.h);;Text(*.txt);;all(*.*)");
        qDebug()<<"文件名为:"<<file_name;

    });

    //工具栏
    QToolBar *toolBar = addToolBar("toolBar");
    //工具栏添加快捷键
    toolBar->addAction(pNew);
    QPushButton *btn = new QPushButton(this);
    btn->setText("**");
    toolBar->addWidget(btn);
    connect(btn,& QPushButton::clicked,[=](){
        btn->setText("123");
        qDebug()<<"按钮按下了";
    });

    //状态栏
    QStatusBar *staBar = statusBar();
    QLabel* label = new QLabel(this);
    label->setText("Normal text file");
    staBar->addWidget(label);
    staBar->addWidget(new QLabel("2",this));

    //状态栏从右往左添加
    staBar->addPermanentWidget(new QLabel("3",this));

    //核心控件
    QTextEdit *text = new QTextEdit(this);
    //设置中心控件
    setCentralWidget(text);

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    //给浮动窗口增加控件
    QTextEdit *text1 = new QTextEdit(this);
    dock->setWidget(text1);
    //模态对话框: 只能操作当前对话框，后面的父对话框无法操作
    //非模态对话框: 可以操作后面的父对话框



}

MainWindow::~MainWindow()
{
}

