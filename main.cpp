#include<QApplication>
#include "Luckyclass.h"
#include "mainwindow.h"
#include "look.h"
#include <QDesktopWidget>

int main(int argc,char *argv[])
{
    QApplication myapp (argc,argv);
//    QDesktopWidget *desktop = myapp.desktop();
//    int	screen_number = desktop->primaryScreen();
//    QRect rect = desktop->screenGeometry(screen_number);


//    mainwindow *window1 = new mainwindow();
//    mywindow *window2 = new mywindow();
//    lookwindow *window3 = new lookwindow();



//    QObject::connect(window1,SIGNAL(mywindowClicked()),window2,SLOT(showmywindow()));
//    QObject::connect(window1,SIGNAL(window1Close()),window2,SLOT(closewindow()));
//    QObject::connect(window1,SIGNAL(lookwindowLooked()),window3,SLOT(showLookwindow()));
//    QObject::connect(window1,SIGNAL(window1Close()),window3,SLOT(closeLookwindow()));



//    window1->mainwindowShow();


     //window2->showmywindow();

mywindow *mywindow1 = new mywindow();
mywindow1->showmywindow();


    return myapp.exec();
}

