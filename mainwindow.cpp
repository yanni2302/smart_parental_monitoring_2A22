#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timeclass.h"
#include <time.h>
#include <QSqlQuery>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QDateTimeEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(T.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    int hourdeb=ui->timeEdit->time().hour();
    int minutedeb=ui->timeEdit->time().minute();
    int hourfin=ui->timeEdit_2->time().hour();
    int minutefin=ui->timeEdit_2->time().minute();

    timeclass T("toto",hourdeb,minutedeb,hourfin,minutefin);
    bool test=T.ajouter();
    if (test)
    {
ui->tableView->setModel(T.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

    }
    else    { QMessageBox::critical(nullptr,QObject::tr("not OK"),QObject::tr("Ajout non effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

    }

    /* QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
     Etudiant E(id,nom,prenom);

 bool test=E.ajouter();
 if (test)
 {
     ui->tab_etudiant->setModel(E.afficher());

     QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

 }
 else    { QMessageBox::critical(nullptr,QObject::tr("not OK"),QObject::tr("Ajout non effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

 }*/
}

void MainWindow::on_pb_supp_clicked()
{

    bool test=T.supprimer(id_enfant);
    if (test){

ui->tableView->setModel(T.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectué \n" "Click cancel to exit."), QMessageBox::Cancel);
    }else {
        QMessageBox::critical(nullptr,QObject::tr("not OK"),QObject::tr("Suppression non effectué \n" "Click cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString heuredeb,minutedeb,heurefin,minutefin;
    QString val=ui->tableView->model()->data(index).toString();
          QSqlQuery qry;
          qry.prepare("select * from time where"
                      " enfant='"+val+"' or hourstart='"+val+"' or minutestart='"+val+"' or hourend='"+val+"' or minuteend ='"+val+"' ");
          if(qry.exec())
            {while (qry.next())
           {
                  if (qry.value(1)<10)
                  {
                       heuredeb="0"+qry.value(1).toString()  ;
                  }
                  if (qry.value(2)<10)
                  {
                       minutedeb="0"+qry.value(2).toString()  ;
                  }

                  if (qry.value(3)<10)
                  {
                       heurefin="0"+qry.value(3).toString()  ;
                  }

                  if (qry.value(4)<10)
                  {
                       minutefin="0"+qry.value(4).toString()  ;
                  }


                  QString heure_debut = heuredeb+ ":" + minutedeb;
                  QString heure_fin = heurefin+ ":" + minutefin;
                  //int hourdeb=ui->timeEdit->time().hour();
                 ui->timeEdit_4->setTime(QTime::fromString(heure_debut));
                 ui->timeEdit_3->setTime(QTime::fromString(heure_fin));


              }
        }
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    id_enfant=ui->tableView->model()->data(index).toString();
}

void MainWindow::on_ajouter_2_clicked()
{
     int hourdeb=ui->timeEdit_4->time().hour();
     int minutedeb=ui->timeEdit_4->time().minute();
     int hourfin=ui->timeEdit_3->time().hour();
     int minutefin=ui->timeEdit_3->time().minute();
        timeclass T("toto",hourdeb,minutedeb,hourfin,minutefin);
        bool test=T.modifier();
        if (test)
        {
          ui->tableView->setModel(T.afficher());
        QMessageBox::information(nullptr,QObject::tr("Modification  "),
                                 QObject::tr(" modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }
}
