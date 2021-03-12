#include "mainwindow.h"
#include<connexion.h>
#include <QApplication>
#include<QMessageBox>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Connexion C;
    bool test=C.CreateConnection();
    if(test)
    {//qDebug() <<"connexion reussite";
    QMessageBox::information(nullptr,QObject::tr("database is open"),
    QObject::tr("connected \n"
                "click ok to exit"),QMessageBox::Ok);}
    else
    {//qDebug() <<"erreur de connexion";
        QMessageBox::information(nullptr,QObject::tr("database is open"),
        QObject::tr("connection failed \n"
                    "click cancel to exit"),QMessageBox::Cancel);}
    return a.exec();
}
