#include<QPushButton>
#include <QDebug>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("主要窗口");
    //固定大小
    resize(400,300);
    b.setText("按钮");
    b.setParent(this);
    b2 = new QPushButton(this);
    b2->setText("点我改变文本");
    b2->move(100,100);
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50,50);

    /* connect()函数
     * &b, 信号发出者
     * &QPushButton::pressed, 处理的信号
     * this, 信号接收者
     * &MainWidget::close, 槽函数
    */
    connect(&b, &QPushButton::pressed, this, &MainWidget::close);

    /* 自定义槽
     * Qt5: 任意的成员函数，普通函数或静态函数
     * 槽函数需要与信号一致(参数，返回值)
     * 由于信号无返回值，所以槽函数一定无返回值
     */

    connect(b2, &QPushButton::released,this,&MainWidget::myslot);
    connect(&b3, &QPushButton::clicked, this, &MainWidget::changeWin);
    //Qt4用SIGNAL()和SLOT()宏，一个危险之处在于宏内参数在编辑阶段，不进行检查
    connect(&subWin,SIGNAL(mySignal()),this,SLOT(dealSignal()));
    connect(&subWin,SIGNAL(mySignal(int,QString)),this,SLOT(dealSlot(int,QString)));


    /*
     * Lambda表达式与 信号与槽
     * [] 相当于将外部变量传入, 当不需要传参，不写即可
     * [=] 相当于将所有局部变量，类成员变量以值的方式传入, 默认只读， 当想修改可以改为 [=]()mutable {}
     *
    */
    QPushButton *b4 = new QPushButton(this);
    b4->setText("lambda");
    b4->move(150,150);
    connect(b4,& QPushButton::clicked, [=](bool isCheck)
        {
            qDebug()<<"Lambda, isCheck:"<<isCheck;
            b4->setText("LAMBDA");
        }
    );

}
void MainWidget::myslot()
{
    //修改文本
    b2->setText("123");
}
void MainWidget::changeWin()
{
    subWin.show();
    this->hide();
}
//处理w发送的信号mySignal
void MainWidget::dealSignal()
{
    //主窗口显示
    this->show();
    //子窗口隐藏
    subWin.hide();
}
void MainWidget::dealSlot(int a1, QString a2)
{
    //qDebug用法和cout类似，打印完自动换行
    qDebug()<<a1<<","<<a2;
}

MainWidget::~MainWidget()
{
}

