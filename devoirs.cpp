#include "devoirs.h"
#include<QtDebug>
#include <QString>
#include<QSqlQuery>
Devoirs::~Devoirs()
{
    //vide
}
Devoirs::Devoirs()
{
    nomD="";
    refDev="";
    nomC="";
    deadline="";

}
Devoirs::Devoirs(QString nomD,QString RefDev,QString nomC,QString deadline)
{
 this->nomD = nomD;
 this->refDev = RefDev;
 this->nomC = nomC;
 this->deadline = deadline;
}
/*void Cours1::set_nomC(QString nomC)
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
*/
bool Devoirs::ajouter()
{
    QSqlQuery query;
          query.prepare("INSERT INTO DEVOIRS (nomD, refDev,nomC ,deadline) "
                        "VALUES (:nomD, :RefDev,:nomC,:deadline)");
          query.bindValue(":nomD",nomD);
          query.bindValue(":refDev",refDev);
          query.bindValue(":nomC",nomC);
          query.bindValue(":deadline",deadline);
         return query.exec();
}
QSqlQueryModel* Devoirs::afficher()
{
    QSqlQueryModel* model =new QSqlQueryModel();

   model->setQuery("SELECT* FROM DEVOIRS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom de Devoirs"));//ajouter un nouveau nom au  header de tableau
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Reference "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom de Cours"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Deadline"));
   return model;
}
bool Devoirs::supprimer(QString NOMD)
{
    QSqlQuery query;
    QString res = NOMD;
    query.prepare("DELETE FROM DEVOIRS WHERE NOMD = :NOMD");
    query.bindValue(":NOMD",res);
    return query.exec();

}
/*bool Cours1::modifier(int NUMERO)
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
   model->setHeaderData(0, Qt::Horizontal,"Nom de cours ");//ajouter un nouveau nom au  header de tableau
   model->setHeaderData(1, Qt::Horizontal,"Numero ");
   model->setHeaderData(2, Qt::Horizontal,"Nom de l'enseignant");
   model->setHeaderData(3, Qt::Horizontal,"Heure de debut");
   model->setHeaderData(4, Qt::Horizontal,"Heure de fin");
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
QSqlQueryModel * Cours1::trier_nom()
{
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from COURS ORDER BY NOMC");
        model->setHeaderData(0,Qt::Horizontal,"Nom De Cours");
        model->setHeaderData(1,Qt::Horizontal,"Numero De Cours");
        model->setHeaderData(2,Qt::Horizontal,"Nom De L'enseignant");
        model->setHeaderData(3,Qt::Horizontal,"Heure Debut");
        model->setHeaderData(4,Qt::Horizontal,"Heure Fin");
        return model ;
}
*/
