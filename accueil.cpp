#include "accueil.h"
#include "ui_accueil.h"
#include "mainwindow1.h"
#include "activiteloisirs.h"
#include "secu.h"
#include "education.h"
#include "gestionc.h"
#include "produitalimentaire.h"
accueil::accueil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accueil)
{
    ui->setupUi(this);
}

accueil::~accueil()
{
    delete ui;
}

void accueil::on_pushButton_7_clicked()
{mainwindow1 w;

    w.exec();

}

void accueil::on_pushButton_8_clicked()
{
    mainwindow1 w;
        w.exec();

}

void accueil::on_pushButton_clicked()
{secu s;
    s.exec();

}

void accueil::on_securite_clicked()
{
    secu s;
        s.exec();
}

void accueil::on_pushButton_3_clicked()
{
    Education E;
    E.exec();
}

void accueil::on_pushButton_4_clicked()
{
    Education E;
    E.exec();
}

void accueil::on_pushButton_5_clicked()
{ gestionc  G;
    G.exec();


}

void accueil::on_comptes_clicked()
{
    gestionc  G;
        G.exec();
}

void accueil::on_pushButton_9_clicked()
{
    produitalimentaire P;
    P.exec();
}

void accueil::on_pushButton_12_clicked()
{
    produitalimentaire P;
    P.exec();
}

void accueil::on_pushButton_11_clicked()
{
    activiteloisirs m;
  m.exec();
}

void accueil::on_pushButton_10_clicked()
{
    activiteloisirs m;
  m.exec();
}
