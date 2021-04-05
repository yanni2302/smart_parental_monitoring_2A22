#include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}
bool Dialog1::controleVide(QString test)
{
    if(test=="admin")
        return  true;
    return false;

}
void Dialog1::on_pushButton_clicked()
{
    bool test1;
   QMessageBox msgBox;

     QString login=ui->login->text();
     QString mdp=ui->mdp->text();
     mainwindow1 w;
    test1=(controleVide(login)&&controleVide(mdp));
    if (test1==true)
    {
    w.setModal(true);

    w.exec();
    }
    else
         {msgBox.setText("mot de passe ou login incorrect ");
msgBox.exec();}

}
