#include "cours1.h"
#include<QtDebug>
#include <QString>
#include<QSqlQuery>
#include <QObject>
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
Cours1::Cours1(QString nomC,QString nomE,QString heureD,QString heureF,int numero)
{
 this->nomC = nomC;
 this->nomE = nomE;
 this->heureD = heureD;
 this->heureF = heureF;
    this->numero = numero;
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
          query.prepare("INSERT INTO COURS (nomC, nomE,heureD ,heureF,numero) "
                        "VALUES (:nomC, :nomE, :heureD,:heureF,:numero)");
          query.bindValue(":numero",numero);
          query.bindValue(":nomC",nomC );
          query.bindValue(":nomE",nomE );
          query.bindValue(":heureD",heureD);
          query.bindValue(":heureF",heureF);
         return query.exec();
}
QSqlQueryModel* Cours1::afficher()
{
    QSqlQueryModel* model =new QSqlQueryModel();

   model->setQuery("SELECT* FROM COURS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom de cours "));//ajouter un nouveau nom au  header de tableau
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom de l'enseignant"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure de debut"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Heure de fin"));
   return model;
}
bool Cours1::supprimer(QString NOMC)
{
    QSqlQuery query;
    QString res = NOMC;
    query.prepare("DELETE FROM COURS WHERE NOMC = :NOMC");
    query.bindValue(":NOMC",res);
    return query.exec();

}
bool Cours1::modifier(int NUMERO)
{
    QSqlQuery query;
    query.prepare("UPDATE COURS SET NOMC=:NOMC,NOME=:NOME,HEURED=:HEURED,HEUREF=:HEUREF WHERE NUMERO=:NUMERO");
    int res=NUMERO;
    query.bindValue(":NUMERO",res);
    query.bindValue(":NOMC",nomC);
    query.bindValue(":NOME",nomE);
    query.bindValue(":HEURED",heureD);
    query.bindValue(":HEUREF",heureF);
    return query.exec();
}
QSqlQueryModel* Cours1::chercher(QString NOMC)
{
   QSqlQueryModel* model =new QSqlQueryModel();
   model->setQuery("SELECT * FROM COURS WHERE NOMC='"+NOMC+"'");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom de cours "));//ajouter un nouveau nom au  header de tableau
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'enseignant"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Heure de debut"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure de fin"));
   return model;
}
QSqlQueryModel * Cours1::trier_id()
{
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from COURS ORDER BY NUMERO");
        model->setHeaderData(0,Qt::Horizontal,"Nom De Cours");
        model->setHeaderData(1,Qt::Horizontal,"Numero De Cours");
        model->setHeaderData(2,Qt::Horizontal,"Nom De L'enseignant");
        model->setHeaderData(3,Qt::Horizontal,"Heure Debut");
        model->setHeaderData(4,Qt::Horizontal,"Heure Fin");
        return model ;
}
