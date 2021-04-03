#include "mainwindow.h"
#include<connexion.h>
#include <QApplication>
#include<QMessageBox>
#include<QDebug>
#include <QMediaPlayer>
#include <QThread>
#include <login.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//The QApplication class manages the GUI application's control flow and main settings.
    QMediaPlayer * player = new QMediaPlayer;
    Connexion C;
    bool test=C.CreateConnection();
    MainWindow w;
    //w.show();
    login l;
    l.show();
    if(test)
    {//qDebug() <<"connexion reussite";
        player->setMedia(QUrl::fromLocalFile("C:/cours/projet QT/Gestion des Cours/1.mp3"));
         player->play();
         qDebug()<<player->errorString();
         QThread::sleep(1);
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
