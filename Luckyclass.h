#ifndef LUCKYCLASS_H
#define LUCKYCLASS_H



#include <QWidget>
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QComboBox;
class QString;
class myline;
class mywindow: public QWidget
{
    Q_OBJECT
public:
    mywindow(QWidget *parent = 0);
    QString turn(QString);


public slots:
    void showmywindow();
    void closewindow();
    void changetext();
    void recheck();
    void startlucky();
private:
    int random(int);
    void getdata(QString);

    QStringList data;
    QStringList text;
    QString mytext;
    QString mytext1;
    QString mytext2;
    QTimer *timer;

    QWidget *mywidget;
    QLabel *classselect;
    QLabel *lucky;
    QComboBox *classselectbox;
    QLineEdit *lineEdit;
    QPushButton *closew;
    QPushButton *start;
    bool enable;

};



#endif
