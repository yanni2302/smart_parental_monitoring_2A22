#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cours1.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QPixmap>
#include <QDebug>
#include <QIntValidator>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->heureD->setValidator(new QIntValidator(0, 99999999, this));
    ui->heureF->setValidator(new QIntValidator(0, 99999999, this));
    ui->coursView->setModel(C.afficher());
    //ajouter de l'image cours_pic
    QPixmap pix(":/img/dev.jpg");
    int w = ui->dev_pic->width();
    int h = ui->dev_pic->height();
    ui->dev_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_b_ajoutC_clicked()
{      int numero=ui->numero->text().toInt();
       QString nomC=ui->nomC->text();
       QString nomE=ui->nomE->text();
       QString heureD=ui->heureD->text();
       QString heureF=ui->heureF->text();
       Cours1 C(nomC,nomE,heureD,heureF,numero);
       bool test=C.ajouter();
       if(test)
       {
           QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("Ajout effectué\n"
                                                "click Cancel to exit"),QMessageBox::Cancel);
           ui->coursView->setModel(C.afficher());
       }
       else
       {
           QMessageBox::information(nullptr,QObject::tr("not ok"),
                                    QObject::tr("Ajout n'est pas effectué\n"
                                                "click Cancel to exit"),QMessageBox::Cancel);
       }
}

void MainWindow::on_suppCours_3_clicked()
{
    QString NomC=ui->suppCours->text();
    bool test=C.supprimer(NomC);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("supprission effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
        ui->coursView->setModel(C.afficher());
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("Not Ok"),
                                 QObject::tr("supprission n'est pas effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
    }
}


void MainWindow::on_modif_button_clicked()
{
    int NUMERO=ui->num_cours->text().toInt();
    QString NOMC=ui->modif_nom_cours->text();
    QString NOME=ui->modif_nom_enseignant->text();
    QString HEURED=ui->modif_heure_debut->text();
    QString HEUREF=ui->modif_heure_fin->text();
    Cours1 C(NOMC,NOME,HEURED,HEUREF,NUMERO);
    bool test=C.modifier(NUMERO);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("Modification effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
        ui->coursView->setModel(C.afficher());
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),
                                 QObject::tr("Modification n'est pas effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
    }
}


/*void MainWindow::on_chercher_clicked()
{
    QString NOMC = ui->lineEdit_chercher->text();
    ui->chercher_cours_2->setModel(C.chercher(NOMC));
}
*/
void MainWindow::on_trier_cours_clicked()
{   if(ui->checkBox_num->isChecked())
   {
        ui->coursView->setModel(C.trier_id());
    }
    else if(ui->checkBox_nom->isChecked())
    {
          ui->coursView->setModel(C.trier_nom());
    }
}

