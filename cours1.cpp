#include "cours1.h"
#include<QtDebug>
#include <QString>
#include<QSqlQuery>
Cours1::~Cours1()
{
    //vide
}
Cours1::Cours1()
{
    nomC="";
    nomE="";
    heureD="";
    heureF="";

}
Cours1::Cours1(QString nomC,QString nomE,QString heureD,QString heureF)
{
 this->nomC = nomC;
 this->nomE = nomE;
 this->heureD = heureD;
 this->heureF = heureF;
}
void Cours1::set_nomC(QString nomC)
{
  this->nomC=nomC;
}
void Cours1::set_nomE(QString nomE)
{
    this->nomE=nomE;
}
void Cours1::set_heureD(QString heureD)
{
    this->heureD=heureD;
}
void Cours1::set_heureF(QString heureF)
{
    this->heureF=heureF;
}
QString Cours1::get_nomC()
{
    return nomC;
}
QString Cours1::get_nomE()
{
    return nomE;
}
QString Cours1::get_heureD()
{
    return heureD;
}
QString Cours1::get_heureF()
{
    return heureF;
}
bool Cours1::ajouter()
{
    QSqlQuery query;
          query.prepare("INSERT INTO COURS (nomC, nomE,heureD ,heureF) "
                        "VALUES (:nomC, :nomE, :heureD,:heureF)");
          query.bindValue(":nomC",nomC );
          query.bindValue(":nomE",nomE );
          query.bindValue(":heureD",heureD);
          query.bindValue(":heureF",heureF);
         return query.exec();
}
