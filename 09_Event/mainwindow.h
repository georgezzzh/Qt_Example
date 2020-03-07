#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    //键盘按下事件
    void keyPressEvent(QKeyEvent *ev) override;
    //定时器事件
    void timerEvent(QTimerEvent* ev) override;
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *ev) override;
    //关闭窗口事件
    void closeEvent(QCloseEvent *ev) override;

    //bool event(QEvent *event) override;
    //事件过滤器, 给需要用的对象, 安装上即可生效
    bool eventFilter(QObject* obj,QEvent *e) override;

private:
    Ui::MainWindow *ui;
    int timerId;
    int timerId2;
};
#endif // MAINWINDOW_H
