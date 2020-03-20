#include "mywidget.h"
#include "ui_form.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
}

void MyWidget::on_pushButton_clicked()
{
    //发送信号
    emit mySignal("hello world");
}
