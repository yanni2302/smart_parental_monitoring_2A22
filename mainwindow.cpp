#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cours1.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QPixmap>
#include <QDebug>
#include <QIntValidator>
#include <QSqlQuery>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    ui->heureD->setValidator(new QIntValidator(0, 99999999, this));
    ui->heureF->setValidator(new QIntValidator(0, 99999999, this));
    ui->coursView->setModel(C.afficher());
    ui->coursView_2->setModel(D.afficher());
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

//CRUD COURS
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


void MainWindow::on_modif_button_3_clicked()
{
    QString NOMC=ui->nomC_4->text();
    QString NOME=ui->nomE_3->text();
    QString HEURED=ui->heureD_3->text();
    QString HEUREF=ui->heureF_3->text();
    Cours1 C(NOMC,NOME,HEURED,HEUREF,id_eq);
    bool test=C.modifier();
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


void MainWindow::on_chercher_clicked()
{
    ui->coursView->setModel(C.afficher());
    QString NOM = ui->lineEdit_chercher->text();
    ui->chercher_cours_2->setModel(C.chercher(NOM));
}
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
//CRUD DEVOIRS
void MainWindow::on_b_ajout_dev_clicked()
{
    QString nomD=ui->nomD_lineEdit->text();
    QString RefDev=ui->numD_lineEdit->text();
    QString NomC=ui->nomC_lineEdit->text();
    QString Deadline=ui->deadline_lineEdit->text();
    Devoirs D(nomD,RefDev,NomC,Deadline);
    bool test=D.ajouter();
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



void MainWindow::on_suppCours_4_clicked()
{
        QString NomD=ui->suppCours_6->text();
        bool test=D.supprimer(NomD);
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

void MainWindow::on_lineEdit_chercher_textChanged(const QString &arg1)
{
    ui->chercher_cours_2->setModel(C.chercher(arg1));

}
void MainWindow::on_coursView_activated(const QModelIndex &index)
{
    QString val=ui->coursView->model()->data(index).toString();
              QSqlQuery qry;
              qry.prepare("select * from COURS where"
                          "  NUMERO ='"+val+"'  ");
              if(qry.exec())
                {while (qry.next())
               { ui->nomC_4->setText(qry.value(0).toString());
                 ui->numC->setText(qry.value(4).toString());
                 ui->nomE_3->setText(qry.value(1).toString());
                 ui->heureD_3->setText(qry.value(2).toString());
                 ui->heureF_3->setText(qry.value(3).toString());
               }
            }
}
void MainWindow::on_coursView_clicked(const QModelIndex &index)
{
    id_eq=ui->coursView->model()->data(index).toInt();
}
void MainWindow::on_pushButton_clicked()
{
    QPrinter printer;
    printer.setPrinterName("printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->coursView->render(&printer);
}
