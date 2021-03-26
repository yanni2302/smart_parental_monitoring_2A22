#include "enfant.h"
#include "ui_enfant.h"

Enfant::Enfant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Enfant)
{
    ui->setupUi(this);
}

Enfant::~Enfant()
{
    delete ui;
}
