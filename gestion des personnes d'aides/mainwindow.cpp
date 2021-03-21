#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personned_aides.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->lineEdit_id_a->setValidator(new QIntValidator(0, 99999, this));
    ui->afficher_personne->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    int identifiant=ui->lineEdit_id_a->text().toInt();
    QString nom=ui->lineEdit_nom_a->text();
    QString prenom=ui->lineEdit_pernom_a->text();
    QString adresse=ui->lineEdit_adresse_a->text();
     QString email=ui->lineEdit_email_a->text();
      QString metier=ui->lineEdit_metier_a->text();
      int prix_heure =ui->lineEdit_prix_heure_a->text().toInt();
      int num_tel =ui->lineEdit_num_tel_a->text().toInt();
Personned_aides P1(identifiant,nom,prenom,adresse,email,metier,num_tel,prix_heure);
bool test=P1.ajouter();
QMessageBox msgBox;

if(test)
   { msgBox.setText("Ajout avec succes.");
ui->afficher_personne->setModel(P.afficher());
}
else
    msgBox.setText("Echec d'ajout");
msgBox.exec();
}



void MainWindow::on_supprimer_clicked()
{Personned_aides P1;
    P1.Setidentifiant(ui->lineEdit_id_a_3->text().toInt());
    bool test=P1.supprimer(P1.Getidentifiant());
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("Suppresion avec succes.");
    ui->afficher_personne->setModel(P.afficher());}
    else
        msgBox.setText("Echec de suppresion");
    msgBox.exec();
}








void MainWindow::on_afficher_personne_activated(const QModelIndex &index)
{
    QString val=ui->afficher_personne->model()->data(index).toString();
      QSqlQuery qry;
      qry.prepare("select * from personne where"
                  " identifiant='"+val+"' or nom='"+val+"' or prenom='"+val+"' or adresse='"+val+"' or email ='"+val+"' or metier='"+val+"' or num_tel ='"+val+"' or prix_heure='"+val+"'");
      if(qry.exec())
        {while (qry.next())
       { ui->lineEdit_id_a_2->setText(qry.value(0).toString());
         ui->lineEdit_nom_a_2->setText(qry.value(1).toString());
         ui->lineEdit_pernom_a_2->setText(qry.value(2).toString());
         ui->lineEdit_adresse_a_2->setText(qry.value(3).toString());
         ui->lineEdit_email_a_2->setText(qry.value(4).toString());
         ui->lineEdit_metier_a_2->setText(qry.value(5).toString());
         ui->lineEdit_num_tel_a_2->setText(qry.value(6).toString());
         ui->lineEdit_prix_heure_a_2->setText(qry.value(7).toString());
          }
    }
}

void MainWindow::on_modifier_clicked()
{
        int id =ui->lineEdit_id_a_2->text().toInt();
        QString nom=ui->lineEdit_nom_a_2->text();
        QString prenom=ui->lineEdit_pernom_a_2->text();
        QString adresse=ui->lineEdit_adresse_a_2->text();
        QString email=ui->lineEdit_email_a_2->text();
        QString metier=ui->lineEdit_metier_a_2->text();
        int num=ui->lineEdit_num_tel_a_2->text().toInt();
        int prix=ui->lineEdit_prix_heure_a_2->text().toInt();
        Personned_aides P1(id,nom,prenom,adresse,email,metier,num,prix);
        bool test=P1.modifier();
        if (test)
        {
           ui->afficher_personne->setModel(P.afficher());
        QMessageBox::information(nullptr,QObject::tr("Modification Employé"),
                                 QObject::tr("Employé modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_afficher_personne_clicked(const QModelIndex &index)
{
    id_personne=ui->afficher_personne->model()->data(index).toInt();
}
