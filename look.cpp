#include <QtWidgets>
#include "look.h"
#include <qtextedit.h>

const QString FILE_PATH("名单.csv");

lookwindow::lookwindow (QWidget *parent) : QWidget (parent)//构造函数由QWidget派生
{

    lookwidget = new QWidget;
    lookwidget->setMinimumSize(1200,700);
    lookwidget->setMaximumSize(1200,700);
    lookwidget->setWindowTitle("浏览查找添加");
    lookwidget->move(50,0);
    //lookwidget->showFullScreen();

    lookButton = new QPushButton("关闭",lookwidget);  
    lookButton->move(1070,620);
    lookButton->setMinimumSize(100,50);
    lookButton->setStyleSheet("QPushButton{font: bold 30px 楷体;color:red;}");
   // lookButton->showMaximized();


    lookLabel = new QTextEdit(lookwidget);//以下为部件的定义及属性设置
    lookLabel->move(30,30);
    lookLabel->resize(400,640);
    lookLabel->setTextColor("SlateBlue");
    QPalette pl = lookLabel->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor("Lavender")));
    lookLabel->setPalette(pl);

    xuehao = new QRadioButton(lookwidget);
    xuehao->setText("学号");
    xuehao->move(815,50);

    xingming = new QRadioButton(lookwidget);
    xingming->setText("姓名");
    xingming->move(815,70);

    searchEdit = new QLineEdit(lookwidget);
    searchEdit->move(500,50);
    searchEdit->resize(300,40);
    searchEdit->setStyleSheet("QLineEdit{font: bold 30px 仿宋;color:green;}");

    searchbutton = new QPushButton(lookwidget);
    searchbutton->setText("查找");
    searchbutton->move(900,50);
    searchbutton->resize(80,40);
    searchbutton->setStyleSheet("QPushButton{font: bold 30px 仿宋;color:green;}");

    addLabel = new QLabel(lookwidget);
    addLabel->setText("添加人员");
    addLabel->move(500,200);
    addLabel->resize(180,40);
    addLabel->setStyleSheet("QLabel{font: bold 40px 楷体;color:orange;}");

    numberLabel = new QLabel(lookwidget);
    numberLabel->setText("学号：");
    numberLabel->move(500,300);
    numberLabel->resize(180,40);
    numberLabel->setStyleSheet("QLabel{font: bold 30px 楷体;color:orange;}");

    addnumber = new QLineEdit(lookwidget);
    addnumber->move(580,305);
    addnumber->resize(200,40);
    addnumber->setStyleSheet("QLineEdit{font: bold 30px 楷体;color:orange;}");

    nameLabel = new QLabel(lookwidget);
    nameLabel->setText("姓名：");
    nameLabel->move(500,360);
    nameLabel->resize(180,40);
    nameLabel->setStyleSheet("QLabel{font: bold 30px 楷体;color:orange;}");

    addname = new QLineEdit(lookwidget);
    addname->move(580,365);
    addname->resize(200,40);
    addname->setStyleSheet("QLineEdit{font: bold 30px 楷体;color:orange;}");

    classLabel = new QLabel(lookwidget);
    classLabel->setText("班级：");
    classLabel->move(500,420);
    classLabel->resize(180,40);
    classLabel->setStyleSheet("QLabel{font: bold 30px 楷体;color:orange;}");


    addbox = new QComboBox(lookwidget);
    addbox->move(580,425);
    addbox->resize(80,38);
    addbox->setStyleSheet("QComboBox{font: bold 30px 楷体;color:orange;}");
    QStringList theclass = QStringList()
            <<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"IT1"<<"IT2";
    addbox->addItems(theclass);

    addButton = new QPushButton("添加",lookwidget);
    addButton->setMinimumSize(90,40);
    addButton->move(700,500);
    addButton->setStyleSheet("QPushButton{font: bold 30px 楷体;color:orange;}");



    getdata();



    connect(lookButton,SIGNAL(clicked()),lookwidget,SLOT(close()));
    connect(searchbutton,SIGNAL(clicked()),this,SLOT(searchdata()));
    connect(lookButton,SIGNAL(clicked()),this,SLOT(getdata()));
    connect(addButton,SIGNAL(clicked()),this,SLOT(adddata()));
    //lookwidget->show();
}

void lookwindow::showLookwindow()
{
    lookwidget->show();

}
void lookwindow::closeLookwindow()
{
    lookwidget->close();

}

void lookwindow::adddata()
{
    if((addnumber->text()).isEmpty()||(addname->text()).isEmpty())
   {
        QMessageBox::warning(this,tr("警告"),tr("数据不合法！"),QMessageBox::Yes);
       // QMessageBox::setText(this,"确定")；
       // lookwidget->close();


    }
    else
    {
        QString addtemp;
        addtemp = addnumber->text() + "," + addname->text() + "," + addbox->currentText() + "\n";
       // data.append(addtemp);
        QFile addcsv(FILE_PATH);

        if(addcsv.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
        {
            QTextStream outStream(&addcsv);
            outStream<<addtemp;
            addcsv.close();
            getdata();
            QMessageBox::information (this,tr("提示"),tr("添加成功！"),QMessageBox::Yes);

        }
        else
        {
             QMessageBox::warning(this,tr("警告"),tr("打开文件失败！"),QMessageBox::Yes);
        }

    }
}
void lookwindow::getdata()
{

    QFile csv(FILE_PATH);
    QString list;
    list.clear();

    if(csv.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&csv);
        QStringList strlist;
        QString temp;
        while (!stream.atEnd())
        {
          strlist = stream.readLine().split(",");
            if(strlist.length()>=3)
            {
                temp = "    " + strlist.at(0) + "    " + strlist.at(1) + "\t\t" + strlist.at(2) + "班" + "\n";
                    list.append(temp);
                     strlist.clear();
                     temp.clear();
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
        QMessageBox::warning(this,tr("警告"),tr("无数据！"),QMessageBox::Yes);
        lookwidget->close();
    }
    else
    {
        lookLabel->setText(data);

    }
}







void lookwindow::searchdata()
{
    QString info = searchEdit->text();
    QFile csv(FILE_PATH);
    QString list;
    list.clear();

    if(csv.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&csv);
        QStringList strlist;
        QString temp;
        while (!stream.atEnd())
        {
          strlist = stream.readLine().split(",");
            if(strlist.length()>=3)
            {
                if(strlist.at(0)==info||strlist.at(1)==info)
                {
                temp = "    " + strlist.at(0) + "    " + strlist.at(1) + "\t\t" + strlist.at(2) + "班" + "\n";
                    list.append(temp);
                }
                     strlist.clear();
                     temp.clear();
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
        QMessageBox::warning(this,tr("警告"),tr("无数据！"),QMessageBox::Yes);
        lookwidget->close();
    }
    else
    {
        lookLabel->setText(data);

    }
}
