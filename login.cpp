#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QThread>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPixmap>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    //login background
    QPixmap pix3(":/img/login.jpg");
    int w2 = ui->login_2->width();
    int h2 = ui->login_2->height();
    ui->login_2->setPixmap(pix3.scaled(w2,h2,Qt::KeepAspectRatio));
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
