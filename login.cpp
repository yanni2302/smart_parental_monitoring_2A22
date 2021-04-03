#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QThread>
#include <QMediaPlayer>
#include <QMediaPlaylist>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_connet_clicked()
{
    QString username = ui->lineEdit_username->text();
     QString password = ui->lineEdit_password->text();
     if(username == "jihed" && password =="jihed")
     {
         QMediaPlayer* player;
         player= new QMediaPlayer;
         player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/connected.mp3"));
             player->play();
             qDebug()<<player->errorString();
             QThread::sleep(1);
         QMessageBox::information(this,"LOGIN","WELCOME");
         this->hide();
         MainWindow *newmain=new MainWindow();
         newmain->show();
     }
     else
     {
         QMediaPlayer* player;
         player= new QMediaPlayer;
         player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/failed.mp3"));
         player->play();
         qDebug()<<player->errorString();
         QThread::sleep(1);
         QMessageBox::warning(this,"LOGIN","CONNECTION FAILED");
    }
}
