#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
signals:
    //启动子线程得信号
    void startThread();
private slots:
    void on_start_clicked();
    void dealSignal();
    void dealClose();
    void on_stop_clicked();

private:
    Ui::MainWindow *ui;
    MyThread* myT;
    QThread* thread;
};
#endif // MAINWINDOW_H
