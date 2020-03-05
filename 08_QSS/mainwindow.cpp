#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //对整个类而言，设置的CSS属性
    this->setStyleSheet("QWidget{background-color:white;}");
    //对这个label而言，设置的CSS属性
    ui->label->setStyleSheet("QLabel{color:black;"
                             "font-size:20px;"
                             "border-radius:5px;"
                             "border-width:5px;"
                             "border-image:url(://lana.png);}");
    //QSS也可以写伪类
    /*
     * 伪类有
     * :checked button部件被选中
     * :disabled 部件被金庸
     * :focus 部件获得焦点
     * :hover 鼠标位于部件上
     * :indeterminate checkbox或radiobutton被部分选中
     * :pressed 部件被鼠标按下
     * :unchecked button部件未被选中
    */
    ui->pushButton->setStyleSheet("QPushButton{"
                                  "background-color:blue;}"
                                  "QPushButton:hover{background-color:red;}"
                                  );

}


MainWindow::~MainWindow()
{
    delete ui;
}

