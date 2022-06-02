#include "mainwindow.h"
#include "logindialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog l;
    l.show();
    l.exec();
    if(l.correct){
        w.show();
    }
    return a.exec();
}
