#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer> //定时器
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void dealTimeout();//定时器槽函数
    void dealDone();//线程槽函数
    void stopThread();//关闭线程槽函数
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer*  myTimer;
    MyThread* thread;

};
#endif // MAINWINDOW_H
