#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QComboBox;
class QString;
class myline;

class mainwindow: public QWidget
{
    Q_OBJECT
public:
    mainwindow(QWidget *parent = 0);


private:
     QPushButton *window1CloseButton;
     QWidget *mainwidget;
     QPushButton *mywindowButton;
     QPushButton *window3Button;
 //    QPushButton *window4Button;
signals:
    // void explains();
     void mywindowClicked();
     void window1Close();
     void lookwindowLooked();

public slots:
     void mainwindowClose();
     void mainwindowShow();
     void jifamywindowClicked();
     void jifawindow1Close();
     void jifalookwindowLooked();


};





#endif // MAINWINDOW_H
