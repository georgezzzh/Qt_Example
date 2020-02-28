#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    //发送槽函数
    void sendSlot();
private:
    QPushButton d;

signals:
    /*
     *  信号必须由 singal 来声明
     *  信号没有返回值，但可以有参数
     *  信号就是函数得声明，只需声明，无需定义
     *  使用: emit mySignal();
     *  宏，允许重载
     */
    void mySignal();
    void mySignal(int,QString);

};

#endif // SUBWIDGET_H
