#include "mainwindow.h"
#include <QApplication>
#include <QRegExp>
#include <QFile>
#include <QDebug>
#include <QList>
#define cout qDebug().noquote()<<"["<<__FILE__<<":"<<__LINE__<<"]:"
typedef struct lyricPhrase{
    double time;
    QString lyric;
} lyricPhrase;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QString lyric="";
    QFile file("test.txt");
    file.open(QIODevice::ReadOnly);
    lyric = file.readAll();
    //为了最后一次匹配换行符
    lyric += "\n";
    lyric.replace(QRegExp("[\r]"),"");
    QRegExp rx("\\[([\\d]{2}):([\\d|\\.]+)\\](.*)\n");
    //设置最小匹配
    rx.setMinimal(true);
    int pos=0;
    QList<lyricPhrase> list;
	//indexIn()返回匹配的第一个字符的位置,第二个参数是开始匹配的位置
    while((pos = rx.indexIn(lyric,pos))!=-1){
		//返回匹配的长度
        pos += rx.matchedLength();
        double t = rx.cap(1).toInt()*60+ rx.cap(2).toDouble();
        lyricPhrase tmp;
        tmp.time=t;
        tmp.lyric=rx.cap(3);
        list.append(tmp);
        //cout<<"cap1:"<<rx.cap(1)<<"cap2:"<<rx.cap(2)<< rx.cap(3)<<"pos:"<<pos;
    }
    for(int i=0;i<list.length();i++){
        cout<<list[i].time<<list[i].lyric;
    }
    w.show();
    return a.exec();
}
