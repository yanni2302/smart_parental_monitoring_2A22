#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cours1.h"
#include "smtp.h"
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
#include <QFileDialog>
#include <QFile>



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
    update();
    //combobox
   /* ui->comboBox->addItem("Anglais");
     ui->comboBox->addItem("Français");
      ui->comboBox->addItem("Maths");
       ui->comboBox->addItem("Programmation");
        ui->comboBox->addItem("Physiques");
         ui->comboBox->addItem("Music");
          ui->comboBox->addItem("");
          */
          //background
          QPixmap pix5(":/img/background3.jpg");
          int w4 = ui->background->width();
          int h4 = ui->background->height();
          ui->background->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
          ui->background_2->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
           ui->background_3->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
            ui->background_4->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
             ui->background_5->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
              ui->background_6->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
              ui->background_7->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));
    //ajouter de l'image cours_pic
    QPixmap pix(":/img/dev.jpg");
    int w = ui->dev_pic->width();
    int h = ui->dev_pic->height();
    ui->dev_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //logo
    QPixmap pix1(":/img/logo.jpg");
    int w1 = ui->logo->width();
    int h1 = ui->logo->height();
    ui->logo->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
     ui->logo_2->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
    //devoirs
    QPixmap pix2(":/img/devoir1.jpg");
    int w2 = ui->devoirs->width();
    int h2 = ui->devoirs->height();
    ui->devoirs->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
    //icons
    QPixmap pix3(":/img/home.png");
    QPixmap pix4(":/img/profil.png");
    int w3 = ui->home->width();
    int h3 = ui->home->height();
    ui->home->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));
    ui->profile->setPixmap(pix4.scaled(w3,h3,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// COURS
void MainWindow::on_b_ajoutC_clicked()
{      int numero=ui->numero->text().toInt();
       QString nomC=ui->nomC->text();
       QString nomE=ui->nomE->text();
       QString heureD=ui->heureD->text();
       QString heureF=ui->heureF->text();
       Cours1 C(nomC,nomE,heureD,heureF,numero);
          bool test1;
             test1 = (controleVide(nomC) && controleVide(nomE) && controleVide(heureD) && controleVide(heureF));
       bool test=C.ajouter();
          QMessageBox msgBox;
          if(test1)
          {
       if(test)
       {
           QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("Ajout effectué\n"
                                                "click Cancel to exit"),QMessageBox::Cancel);
           ui->coursView->setModel(C.afficher());
         update();
}
          else
          {msgBox.setText("Echec");
              msgBox.exec();
          }
       }
       else
       {
           QMessageBox::information(nullptr,QObject::tr("not ok"),
                                    QObject::tr("Ajout n'est pas effectué\n"
                                                "click Cancel to exit"),QMessageBox::Cancel);
       }
}
  void MainWindow::update()
  {
          QSqlQueryModel *m=new QSqlQueryModel();
          QSqlQuery *querry=new QSqlQuery();
          querry->prepare("SELECT NOMC FROM COURS");
          querry->exec();
          m->setQuery(*querry);
          ui->comboBox->setModel(m);
  }
void MainWindow::on_suppCours_3_clicked()
{
    QString NomC=ui->suppCours->text();
    bool test=C.supprimer(NomC);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
        ui->coursView->setModel(C.afficher());
        update();
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("Not Ok"),
                                 QObject::tr("suppression n'est pas effectué\n"
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
        update();
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
{   if(ui->radioButton_numero->isChecked())
   {
        ui->coursView->setModel(C.trier_id());
    }
    else if(ui->radioButton_nom->isChecked())
    {
          ui->coursView->setModel(C.trier_nom());
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
                          "NOMC='"+val+"' or NUMERO ='"+val+"' NOME='"+val+"' or HEURED='"+val+"' or HEUREF='"+val+"'");
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

//DEVOIRS
void MainWindow::on_b_ajout_dev_clicked()
{
    QString nomD=ui->nomD_lineEdit->text();
    int RefDev=ui->numD_lineEdit->text().toInt();
    QString NomC=ui->comboBox->currentText();
    QString Deadline=ui->deadline_lineEdit->text();
    Devoirs D(nomD,RefDev,NomC,Deadline);
    bool test=D.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("Ajout effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
         ui->coursView_2->setModel(D.afficher());
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
           ui->coursView_2->setModel(D.afficher());
        }
        else
        {
            QMessageBox::information(nullptr,QObject::tr("Not Ok"),
                                     QObject::tr("supprission n'est pas effectué\n"
                                                 "click Cancel to exit"),QMessageBox::Cancel);
        }
}


void MainWindow::on_imprimer_devoirs_clicked()
{
    QPrinter printer;
    printer.setPrinterName("printer");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->coursView->render(&printer);
}

void MainWindow::on_coursView_2_activated(const QModelIndex &indexx)
{
    QString vall=ui->coursView_2->model()->data(indexx).toString();
              QSqlQuery qry;
              qry.prepare("select * from DEVOIRS where"
                          "NOMD ='"+vall+"' or REFDEV='"+vall+"' or DEADLINE='"+vall+"' or NOMC='"+vall+"' ");
              if(qry.exec())
                {while (qry.next())
               { ui->nomD_modif->setText(qry.value(0).toString());
                 ui->numD_modif->setText(qry.value(1).toString());
                 ui->deadline_modif->setText(qry.value(2).toString());
                 ui->nomC_modif->setText(qry.value(3).toString());
               }
            }
}

void MainWindow::on_coursView_2_clicked(const QModelIndex &indexx)
{
    id_Dev=ui->coursView_2->model()->data(indexx).toInt();
}

void MainWindow::on_modifier_clicked()
{
    QString NOMD=ui->nomD_modif->text();
    QString DEADLINE=ui->deadline_modif->text();
    QString NOMC=ui->nomC_modif->text();
    Devoirs D(NOMD,id_Dev,DEADLINE,NOMC);
    bool test=D.modifier();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("Modification effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
        ui->coursView->setModel(D.afficher());
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),
                                 QObject::tr("Modification n'est pas effectué\n"
                                             "click Cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_trier_cours_2_clicked()
{
    if(ui->radioButton_numero_2->isChecked())
    {
         ui->coursView_2->setModel(D.trier_id());
    }
    else if(ui->radioButton_nom_2->isChecked())
    {
        ui->coursView_2->setModel(D.trier_nom());
    }

}

void MainWindow::on_chercher_2_clicked()
{
    ui->coursView_2->setModel(D.afficher());
    QString NOM = ui->lineEdit_chercher_2->text();
    ui->chercher_cours_3->setModel(D.chercher(NOM));
}
void MainWindow::on_lineEdit_chercher_2_textChanged(const QString &arg1)
{
    ui->coursView_2->setModel(D.afficher());
    ui->chercher_cours_3->setModel(D.chercher(arg1));

}
void MainWindow::on_pushButton_2_clicked()
{   QString filter = "All File (*.*)";
    QString file_name=QFileDialog::getOpenFileName(this,"Open a file","C:/cours/projet QT/Gestion des Cours/Supports/",filter);
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
         QMessageBox::warning(this,"title","file not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
     file.flush();
     file.close();
}
bool MainWindow::controleVide(QString test)
{
    if(test!="")
        return  true;
    return false;

}

bool MainWindow::controleVideInt(int test)
{
    if(test!=0)
        return  true;
    return false;

}
void MainWindow::on_envoyer_clicked()
{
    QString mail_destinataire=ui->Destinataire->text();
    QString objet=ui->objet->text();
    QString message=ui->Message->text();
Smtp* smtp = new Smtp("jihedca111@gmail.com","Jiji@jiji123", "smtp.gmail.com");
smtp->sendMail("jihedca111@gmail.com",ui->Destinataire->text(),ui->objet->text(),ui->Message->text());


 ui->Destinataire->clear();
 ui->objet->clear();
 ui->Message->clear();
}

