#include "accueil.h"
#include "ui_accueil.h"
#include "mainwindow1.h"
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
