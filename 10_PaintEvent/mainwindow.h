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
    //重写绘图事件, 虚函数
    //如何在窗口绘图, 必须放在绘图事件中，绘图事件内部自动调用，窗口需要重绘时
    void paintEvent(QPaintEvent* ev) override;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int beginPos;
};
#endif // MAINWINDOW_H
