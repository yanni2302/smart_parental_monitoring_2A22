#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personned_aides.h"
#include "reclamation.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include "smtp.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->lineEdit_id_a->setValidator(new QIntValidator(0, 99999, this));
    ui->afficher_personne->setModel(P.afficher());
    ui->afficher_rec->setModel(R.afficher_reclamtion());
    update_personne_list();
    update_mail_list();

    connect(ui->envoyer, SIGNAL(clicked()),this, SLOT(sendMail()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::controleNumTel(int test)
{
    QString tel= QString::number(test);
    for(int i=0;i<tel.length();i++)
    {
        if (tel.length()==8)
        {
            return true;
        }
    }
    return false;
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

bool MainWindow::controleEmail(QString test)
{
    for(int i=0;i<test.length();i++)
    {
        if (test.at(i)=='@')
        {
            return true;
        }
    }
    return false;
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

      bool test2;
         test2=(controleEmail(email)&& controleNumTel(num_tel)&&controleVide(nom)&&controleVide(prenom)&&controleVide(email)&&controleVide(adresse)&&controleVideInt(num_tel)&&controleVideInt(prix_heure)&&controleVideInt(identifiant) );

Personned_aides P1(identifiant,nom,prenom,adresse,email,metier,num_tel,prix_heure);
bool test=P1.ajouter();
QMessageBox msgBox;
if(test2)
 {

if(test)
   { msgBox.setText("Ajout avec succes.");
ui->afficher_personne->setModel(P.afficher());
update_personne_list();
update_mail_list();
msgBox.exec();
}
else
   { msgBox.setText("Echec d'ajout");
msgBox.exec();}
}
else

  {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel "),
                                 QObject::tr("personne d'aides non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


  }




}


void MainWindow::on_supprimer_clicked()
{

    bool test=P.supprimer(id_personne);
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("Suppresion avec succes.");
    ui->afficher_personne->setModel(P.afficher());}
    else
        msgBox.setText("Echec de suppresion");
    msgBox.exec();
    update_personne_list();
    update_mail_list();

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
        QMessageBox::information(nullptr,QObject::tr("Modification Personnes"),
                                 QObject::tr("personne modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_afficher_personne_clicked(const QModelIndex &index)
{
    id_personne=ui->afficher_personne->model()->data(index).toInt();
}


void MainWindow::on_envoyer_clicked()
{
    int identifiant=ui->lineedit_ref->text().toInt();
    QString mail_destinataire=ui->comboBo_3->currentText();
    QString sujet=ui->lineedit_sujet->text();
    QString message=ui->lineedit_msg->text();
      int personne_aide =ui->comboBo_2->currentText().toInt();
reclamation R1(identifiant,mail_destinataire,sujet,message,personne_aide);
bool test=R1.ajouter_reclamtion();
QMessageBox msgBox;
if(test)
   { msgBox.setText("Ajout de la reclamation avec succes.");
ui->afficher_rec->setModel(R.afficher_reclamtion());
}
else
    msgBox.setText("Echec d'ajout");
msgBox.exec();

}

void MainWindow::on_afficher_rec_activated(const QModelIndex &index)
{
    QString val=ui->afficher_rec->model()->data(index).toString();
      QSqlQuery qry;
      qry.prepare("select * from reclamation where"
                  " identifiant='"+val+"' or mail_destinataire='"+val+"' or sujet='"+val+"' or message='"+val+"' or personne_aide ='"+val+"'");
      if(qry.exec())
        {while (qry.next())
       { ui->lineedit_ref_2->setText(qry.value(0).toString());
         ui->comboBo_3->setCurrentText(qry.value(1).toString());
         ui->lineedit_sujet_2->setText(qry.value(2).toString());
         ui->lineedit_msg_2->setText(qry.value(3).toString());
         ui->lineedit_personne_2->setText(qry.value(4).toString());

          }
    }
}

void MainWindow::on_afficher_rec_clicked(const QModelIndex &index)
{
    ref_reclamation=ui->afficher_rec->model()->data(index).toInt();

}

void MainWindow::on_modifier_rec_clicked()
{
    int id =ui->lineedit_ref_2->text().toInt();
    QString mail=ui->comboBo_3->currentText();
    QString sujet=ui->lineedit_sujet_2->text();
    QString msg=ui->lineedit_msg_2->text();
    int personne=ui->comboBo_2->currentText().toInt();
    reclamation R1(id,mail,sujet,msg,personne);
    bool test=R1.modifier_reclamtion();
    if (test)
    {
       ui->afficher_rec->setModel(R.afficher_reclamtion());
    QMessageBox::information(nullptr,QObject::tr("Modification Reclamation "),
                             QObject::tr("Reclamatin modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_supprimer_rec_clicked()
{
    bool test=R.supprimer_reclamtion(ref_reclamation);
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("Suppresion avec succes.");
    ui->afficher_rec->setModel(R.afficher_reclamtion());}
    else
        msgBox.setText("Echec de suppresion");
    msgBox.exec();
}

void MainWindow::update_personne_list(){
    QSqlQueryModel *m=new QSqlQueryModel();
    QSqlQuery *querry=new QSqlQuery();
    querry->prepare("SELECT identifiant FROM personne");
    querry->exec();
    m->setQuery(*querry);


    ui->comboBo_2->setModel(m);

}
void MainWindow::update_mail_list(){
    QSqlQueryModel *m=new QSqlQueryModel();
    QSqlQuery *querry=new QSqlQuery();
    querry->prepare("SELECT email FROM personne");
    querry->exec();
    m->setQuery(*querry);


    ui->comboBo_3->setModel(m);

}

void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("soumaya99.bensassi@gmail.com","Sb50607010", "smtp.gmail.com");
    connect(smtp,SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


      smtp->sendMail("soumaya99.bensassi@gmail.com", ui->comboBo_3->currentText(),ui->lineedit_sujet->text(),ui->lineedit_msg->text());
}

void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Réclamation " ), tr( "Réclamation envoyée par mail!\n\n" ) );
    ui->comboBo_3->clear();
    ui->lineedit_sujet->clear();
    ui->lineedit_msg->clear();

}

void MainWindow::on_tri_clicked()
{
    ui->afficher_personne->setModel(P.AfficherTrieNom());
}

void MainWindow::on_recherche_textChanged(const QString &arg1)
{
    ui->afficher_personne->setModel(P.rechercherNom(arg1));
}
