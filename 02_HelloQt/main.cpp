#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication a(argc,argv);

    //我们写的代码, 开启一个窗口
    QWidget w;
    w.setWindowTitle("我的应用");

    QPushButton b;
    b.setText("我的按钮");
    /*如果不指定父对象，对象和对象(窗口) 独立
     * b设置父对象，为w，则b显示在w上
     * 指定父对象，有2种方式，可以通过构造对象，传参
     * 指定完父对象之后，只用调用parent.show()即父子都显示出来了
     */
    b.setParent(&w);
    //移动坐标
    b.move(100,100);
    w.show();
    return a.exec();
}
