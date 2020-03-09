#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QBitmap>
#include <QPicture>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    beginPos = 0;
    //QPixmap

    //绘图设备, 该绘制出得图片不在窗口显示，用于导出
    QPixmap pixmap(400,300);
    QPainter p(&pixmap);
    //填充背景色
    pixmap.fill(Qt::white);
    p.drawPixmap(0,0,80,80,QPixmap("../images/tmp.png"));
    //保存图片
    pixmap.save("../test.png");

    //QImage
    //创建一个绘图设备，背景为透明

    QImage image(400,300,QImage::Format::Format_ARGB32);
    QPainter p2(&image);
    p2.drawImage(0,0,QImage("../images/tmp.png"));
    //对绘图设备前50个像素点进行修改
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            image.setPixel(QPoint(i,j),qRgb(255,0,0));
        }
    }
    image.save("../test2.png");
    //QPicture 保存一个二进制文件(无法显示)，用的时候加载出来就可以
    QPicture picture;
    QPainter p3(&picture);
    p3.drawPixmap(0,0,80,80,QPixmap("../images/tmp.png"));
    p3.drawLine(50,50,150,50);
    //必须添加end()
    p3.end();
    picture.save("../picture.png");
    /*
     * 加载的方法
    void MainWindow::paintEvent(QPaintEvent *ev)
    {
        QPicture pic;
        pic.load("../picture.png");
        QPainter p(this);

        p.drawPicture(0,0,pic);
    }
    */

}

MainWindow::~MainWindow()
{
    delete ui;
}

//直接显示在屏幕上
void MainWindow::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    //指定背景
    //p.drawPixmap(rect(),QPixmap("://shot.PNG"));
    //设置画笔
    QPen pen;
    pen.setWidth(5);
    pen.setColor(QColor(200,200,200));
    pen.setStyle(Qt::PenStyle::DotLine);
    p.setPen(pen);
    p.drawLine(50,50,150,50);
    p.drawLine(50,50,50,150);
    //画矩形
    p.drawRect(150,150,100,50);
    //圆
    //设置画刷
    QBrush brush;
    brush.setColor(QColor(255,0,255));
    brush.setStyle(Qt::BrushStyle::Dense1Pattern);
    p.setBrush(brush);
    p.drawEllipse(QPoint(150,150),50,50);
    //贴一个图片
    p.drawPixmap(beginPos,250,80,80,QPixmap("../images/tmp.png"));
    //QBitmap()是黑白得灰度图
    //p.drawPixmap(beginPos,250,80,80,QBitmap("../images/tmp.png"));

}

void MainWindow::on_pushButton_clicked()
{
    this->beginPos += 10;
    qDebug()<<"beginPos:"<<beginPos<<",width:"<<width();
    if(beginPos >= width()){
        beginPos = 0;
    }
    //触发painEvent()
    update();
}
