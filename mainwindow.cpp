#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cours1.h"
#include<QMessageBox>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->heureD->setValidator(new QIntValidator(0, 99999999, this));
    ui->heureF->setValidator(new QIntValidator(0, 99999999, this));
    ui->coursView->setModel(C.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_b_ajoutC_clicked()
{
       QString nomC=ui->nomC->text();
       QString nomE=ui->nomE->text();
       QString heureD=ui->heureD->text();
       QString heureF=ui->heureF->text();
       Cours1 C(nomC,nomE,heureD,heureF);
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

