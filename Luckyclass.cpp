#include <QtWidgets>
#include "Luckyclass.h"

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

//#include <QThread>
//#include <time.h>
//#include <stdlib.h>

const QString FILE_PATH("名单.csv");

//QStringList data;

mywindow::mywindow (QWidget *parent) : QWidget (parent)//构造函数由QWidget派生
{
    mywidget = new QWidget;//定义一个主窗口，并设置属性
    mywidget->setMinimumSize(1200,500);
    mywidget->setMaximumSize(1200,500);
    mywidget->move(50,50);
    mywidget->setStyleSheet("QWidget{ background-image: url(back.jpg)}");//用css设置样式
      //  background-image: url(/back.jpg);
    classselect = new QLabel(tr("选择班级"),mywidget);//以下为部件的定义及属性设置
    classselect->move(80,70);
    classselect->resize(200,80);
    classselect->setStyleSheet("QLabel{font: bold 40px 仿宋;color:green}");
    lucky = new QLabel(tr("抽中的是"),mywidget);
    lucky->move(500,70);
    lucky->resize(200,80);
    lucky->setStyleSheet("QLabel{font: bold 40px 仿宋;color:green}");

    classselectbox = new QComboBox(mywidget);
    classselectbox->move(80,200);
    classselectbox->resize(160,80);
    classselectbox->setStyleSheet("QComboBox{font: bold 60px 仿宋}");

    QStringList theclass = QStringList()
            <<"一班"<<"二班"<<"三班"<<"四班"<<"五班"<<"六班"<<"IT1"<<"IT2";
    classselectbox->addItems(theclass);


    lineEdit = new QLineEdit(mywidget);
    lineEdit->move(300,200);
    lineEdit->resize(600,80);
    lineEdit->setStyleSheet("QLineEdit{font: bold 52px 仿宋;color:green;}");

    start = new QPushButton("开始",mywidget);
    start->move(500,300);
    start->resize(180,60);
    start->setStyleSheet("QPushButton{font: bold 50px 楷体;color:green;}");


    closew = new QPushButton("关闭",mywidget);
    closew->move(1000,400);
    closew->resize(100,40);
    closew->setStyleSheet("QPushButton{font: bold 30px 楷体;color:red;}");

     timer = new QTimer(this);//设置定时器


    connect(closew,SIGNAL(clicked()),mywidget,SLOT(close()));  //连接信号与槽
    connect(classselectbox,SIGNAL(currentIndexChanged(int)),this,SLOT(recheck()));
    connect(closew,SIGNAL(clicked()),this,SLOT(recheck()));
    connect(start,SIGNAL(clicked()),this,SLOT(startlucky()));
  //  connect(classselectbox,SIGNAL(textChanged()),this,SLOT(recheck());
    mywidget->setWindowTitle (tr ("抽取窗口"));//设置窗口标题
    enable = 1;



}

//void mywindow::closeEvent(QCloseEvent *event)
//{
//    recheck();
//     QMessageBox::warning(this,tr("警告"),tr("无该班级数据！"),QMessageBox::Yes);
//    //TODO: 在退出窗口之前，实现希望做的操作
//}


void mywindow::recheck()//函数作用为当复选框的班级的值改变时就把复选框的值变为空白
{

    if(timer->isActive())
    {
        enable = 1;
        start->setText("开始");
        timer->stop();
    }
    lineEdit->setText("Ready Start");//初始化编辑框

}

void mywindow::showmywindow()
{

      mywidget->showFullScreen();//显示窗口
}

void mywindow::closewindow()
{
    mywidget->close();

}

int mywindow::random(int sec)//产生一个指定范围的随机数
{
    int re = 1;

     QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    re = (qrand()%sec);
    if(re==0)
    {
     re = 1;
    }
    return (re);
}




void mywindow::getdata(QString whichclass)
{

    QFile csv(FILE_PATH);
    QStringList list = QStringList();
    list.clear();

    if(csv.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&csv);
       // QStringList strlist1;
        QStringList strlist;
        QString temp;
        while (!stream.atEnd())
        {
         // strlist1.push_back(stream.readLine());
          strlist = stream.readLine().split(",");
            if(strlist.length()>=3)
            {
                if(strlist.at(2)==whichclass)//判断所需班级
                {
                    temp = strlist.at(0) + "," + strlist.at(1)+ "," + strlist.at(2) + "\n";
                    list.append(temp);

                     strlist.clear();
                     temp.clear();
                }
            }
            else
                strlist.clear();
        }
    }
    data = list;
    list.clear();
    csv.close();
    if (data.isEmpty())
    {
        QMessageBox::warning(this,tr("警告"),tr("无该班级数据！"),QMessageBox::Yes);
        mywidget->close();
    }
}



QString mywindow::turn(QString x)//读取转换复选框的值
{
    if(x==tr("三班"))
        return "3";
    else if(x==tr("二班"))
        return "2";
    else if(x==tr("四班"))
        return "4";
    else if(x==tr("一班"))
        return "1";
    else if(x==tr("五班"))
        return "5";
    else if(x==tr("六班"))
        return "6";
    else if(x==tr("IT1"))
        return "IT1";
    else if(x==tr("IT2"))
        return "IT2";
    else
    {
        QMessageBox::warning(this,tr("警告"),tr("未定义班级"),QMessageBox::Yes);
        return "1";
    }
}


void mywindow::changetext()//改变编辑框的值
{
    text =data.at(random(data.length())).split(",");
    if(!text.isEmpty())
    {
        if(text.length()!=3)
            mytext = text.at(0);
        else
        {
        mytext1 = text.at(0);
        mytext2 = text.at(1);
        mytext = "\t\t";
        mytext = mytext2.append(mytext).append(mytext1);//处理取出数据
        }

        lineEdit->setText(mytext);
         text.clear();
    }
    else
    {
        lineEdit->setText("No Lucky");
    }
   // data.clear();
}


void mywindow::startlucky()//开始选取的函数
{

    if(enable==1)
    {
        enable = 0;
        start->setText("停止");
        this->getdata(turn(classselectbox->currentText()));
       // lineEdit->setText("Ready Start");//初始化编辑框


        timer->start(80);//设置间隔时间

        connect(timer, SIGNAL(timeout()), this, SLOT(changetext()));
       // QThread::msleep(1000);
    }
    else
    {
        enable = 1;
        start->setText("开始");
        timer->stop();

    }
}

