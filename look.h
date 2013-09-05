#ifndef LOOK_H
#define LOOK_H

#include <QWidget>
#include <qtextedit.h>
class QLabel;
class QPushButton;
class QRadioButton;
class QLineEdit;
class QComboBox;

class lookwindow: public QWidget
{
    Q_OBJECT
public:
    lookwindow(QWidget *parent = 0);

public slots:
    void showLookwindow();
    void closeLookwindow();
    void searchdata();

private slots:
    void getdata();
    void adddata();

private:
    QTextEdit *lookLabel;
    QWidget *lookwidget;
    QPushButton *lookButton;
    QString data;
    QRadioButton *xuehao;
    QRadioButton *xingming;
    QLineEdit *searchEdit;
    QPushButton *searchbutton;
    QLabel *addLabel;
    QLabel *numberLabel;
    QLabel *nameLabel;
    QLabel *classLabel;
    QLineEdit *addname;
    QLineEdit *addnumber;
    QComboBox *addbox;
    QPushButton *addButton;


};

#endif // LOOK_H
