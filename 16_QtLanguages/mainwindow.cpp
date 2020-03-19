#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTranslator>
#include <QDebug>
/*
 * 制作国际化的步骤:
 * 0. 在project.pro中写,写入要翻译的语言文件`TRANSLATIONS = Translate_EN.ts Translate_CN.ts`
 * 1. Qt工具->外部->Qt语言家->更新翻译
 * 2. 打开Qlinguist，打开Translate_CN.ts文件。并翻译好，然后点击 文件->发布
 * 3. 将生成的Translate_CN.qm文件，放到项目中，并写代码载入
 * 在项目路径生成了
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->trans = new QTranslator(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_activated(int index)
{
    qDebug()<<"change ";
    switch (index) {
        case 0:
            trans->load("Translate_CN.qm");
            break;
        case 1:
            trans->load("Translate_EN.qm");
            break;
        default:
            ;
    }
    //加载翻译器
    qApp->installTranslator(trans);
    ui->retranslateUi(this);
}
