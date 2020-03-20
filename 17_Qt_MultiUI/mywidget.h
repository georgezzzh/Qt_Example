#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

//class类名与ui的前缀相同即可
QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
private:
    Ui::Form* ui;
signals:
    void mySignal(QString );
private slots:
    void on_pushButton_clicked();
};

#endif // MYWIDGET_H
