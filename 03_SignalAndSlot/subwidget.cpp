#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("子窗口");
    resize(400,300);
    d.setText("切换到主窗口");
    d.setParent(this);
    connect(&d, &QPushButton::clicked,this, &SubWidget::sendSlot);


}
void SubWidget::sendSlot()
{
    //发送信号
    emit mySignal();
    emit mySignal(249,"hello world, 你好世界");
}
