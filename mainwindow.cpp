#include <Qtwidgets>
#include"mainwindow.h"

//#include <QLabel>
//#include <QPushButton>
//#include <QComboBox>
//#include <QTextStream>
//#include <QLineEdit>
//#include <QMessageBox>
//#include <QTimer>
//#include <QDateTime>
//#include <QFile>
//#include <QTextStream>



mainwindow::mainwindow (QWidget *parent) : QWidget (parent)
{
    mainwidget = new QWidget;//定义一个主窗口，并设置属性
    mainwidget->setMinimumSize(400,500);
    mainwidget->setMaximumSize(400,500);
    mainwidget->setStyleSheet("QWidget{ background-image: url(back.jpg)}");//用css设置样式

    mywindowButton = new QPushButton("开始抽取",mainwidget);
    mywindowButton->move(100,100);
    mywindowButton->resize(200,60);
    mywindowButton->setStyleSheet("QPushButton{font: bold 30px 仿宋;color:blue;}");

    window3Button = new QPushButton("浏览查找添加",mainwidget);
    window3Button->move(100,200);
    window3Button->resize(200,60);
    window3Button->setStyleSheet("QPushButton{font: bold 30px 仿宋;color:blue;}");

  //  window4Button = new QPushButton("添加人员",mainwidget);
  //  window4Button->move(300,100);
  //  window4Button->resize(100,40);

    window1CloseButton = new QPushButton("退出",mainwidget);
    window1CloseButton->move(100,300);
    window1CloseButton->resize(200,60);
    window1CloseButton->setStyleSheet("QPushButton{font: bold 30px 仿宋;color:blue;}");

    connect(mywindowButton,SIGNAL(clicked()),this,SLOT(jifamywindowClicked()));
    connect(window1CloseButton,SIGNAL(clicked()),mainwidget,SLOT(close()));
    connect(window1CloseButton,SIGNAL(clicked()),this,SLOT(jifawindow1Close()));
    connect(window3Button,SIGNAL(clicked()),this,SLOT(jifalookwindowLooked()));

    mainwidget->setWindowTitle (tr ("随机抽取"));//设置窗口标题


}

void mainwindow::jifalookwindowLooked()
{
     emit lookwindowLooked();

}

void mainwindow::mainwindowShow()
{
    mainwidget->show();

}

void mainwindow::mainwindowClose()
{
    mainwidget->close();

}

void mainwindow::jifawindow1Close()
{
    emit window1Close();

}


void mainwindow::jifamywindowClicked()
{
    emit mywindowClicked();

}

