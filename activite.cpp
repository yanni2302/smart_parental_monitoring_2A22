#include "activite.h"
#include<QSqlQuery>
Activite::Activite()
{
    //numero=0;
    cours="";
    activite="";
    etat="";

}
Activite::~Activite()
{
    //vide
}
Activite::Activite(int numero,QString cours,QString activite,QString etat)
{
 this->numero = numero;
 this->cours = cours;
 this->activite = activite;
 this->etat = etat;
}

bool Activite::ajouter()
{
    QSqlQuery query;
          query.prepare("INSERT INTO ACTIVITE (numero, cours ,activite ,etat) "
                        "VALUES (:numero, :cours, :activite,:etat)");
          query.bindValue(":numero",numero);
          query.bindValue(":cours",cours );
          query.bindValue(":activite",activite);
          query.bindValue(":etat",etat);
         return query.exec();
}
QSqlQueryModel* Activite::afficher()
{
    QSqlQueryModel* model =new QSqlQueryModel();

   model->setQuery("SELECT* FROM ACTIVITE");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero "));//ajouter un nouveau nom au  header de tableau
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de cours"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Activite"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
   //model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero "));
   return model;
}
/*bool Cours1::supprimer(QString NOMC)
{
    QSqlQuery query;
    QString res = NOMC;
    query.prepare("DELETE FROM COURS WHERE NOMC = :NOMC");
    query.bindValue(":NOMC",res);
    return query.exec();

}
bool Cours1::modifier()
{
    QSqlQuery query;
    QString res=QString::number(NUMERO);
    query.prepare("UPDATE COURS SET NOMC=:NOMC,NOME=:NOME,HEURED=:HEURED,HEUREF=:HEUREF,NUMERO=:NUMERO WHERE NUMERO=:NUMERO");
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
   model->setQuery("SELECT * FROM COURS WHERE NOMC='"+NOMC+"'"   );
   model->setHeaderData(0, Qt::Horizontal,"Nom de cours ");//ajouter un nouveau nom au  header de tableau
   model->setHeaderData(1, Qt::Horizontal,"Nom de l'enseignant");
   model->setHeaderData(2, Qt::Horizontal,"Heure de debut");
   model->setHeaderData(3, Qt::Horizontal,"Heure de fin");
   model->setHeaderData(4, Qt::Horizontal,"Numero ");
   return model;
}
*/QSqlQueryModel * Activite::trier_toDo()
{
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from ACTIVITE WHERE ETAT = 'TO DO'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero "));//ajouter un nouveau nom au  header de tableau
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de cours"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Activite"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
        return model ;
}
QSqlQueryModel * Activite::trier_done()
{
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from ACTIVITE WHERE ETAT = 'Done'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero "));//ajouter un nouveau nom au  header de tableau
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de cours"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Activite"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
        return model ;
}

