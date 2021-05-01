#include "compte.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include <QString>

compte::compte()
{
    idc=0;
    login="";
    mdp="";
    enfant="";

}
compte::compte(int idc,QString login,QString mdp,QString enfant)
{

    this->idc=idc;
    this->login=login;
    this->mdp=mdp;
    this->enfant=enfant;
}

bool compte::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO compte (idc,login,mdp,enfant) VALUES (:idc,:login,:mdp,:enfant)");
    query.bindValue(":idc",idc);
    query.bindValue(":login",login);
    query.bindValue(":mdp",mdp);
    query.bindValue(":enfant",enfant);

    return query.exec();
}
bool compte::supprimer(int idc )
{
    QSqlQuery query;
    query.prepare("delete from compte where idc = :idc") ;

    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel* compte::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM compte");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("login"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("mdp"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("enfant"));

    return model;

}

bool compte::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE compte SET idc =:idc,login =:login,mdp =:mdp,enfant =:enfant WHERE idc =:idc ");
    query.bindValue(":idc",idc);
    query.bindValue(":login",login);
    query.bindValue(":mdp",mdp);
    query.bindValue(":enfant",enfant);

    return query.exec();
}

QSqlQueryModel * compte::Find_compte()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT idc,login,mdp,enfant FROM compte");

    query.exec();
    model->setQuery(query);
    return model;
}
QString compte:: apercu_pdf()
 {
    QString text="          **** les comptes ****      \n \n " ;
     QSqlQuery query ;
     QString i,x,z,a;


      query.exec("select * from compte ");
      while (query.next())
      {
         i=query.value(0).toString();
         x=query.value(1).toString();
         z=query.value(2).toString();
         a=query.value(3).toString();

        text += "\n idc : "+i+"\n\n - login : "+ x+"\n - mdp : "+ z+"\n - enfant:"+a+"\n  " ;


     }
      return text;
}
QSqlQueryModel* compte::recherche_avance(QString text,QString choix)
{
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery* qry = new QSqlQuery;

    if ( text == "")

    {
        return model;
    }
    else
    {
        if ( choix == "idc")
        {
            qry->prepare("SELECT * FROM compte WHERE idc LIKE :idc");
            qry->bindValue(":idc",("%" + text + "%")); //securité pour eviter la faille de sqlinjection

            qry->exec();
            model->setQuery(*qry);
            return model;

        }
        if ( choix == "login")
        {
            qry->prepare("SELECT * FROM compte WHERE login LIKE :idc");
            qry->bindValue(":idc",("%" + text + "%")); //securité pour eviter la faille de sqlinjection

            qry->exec();
            model->setQuery(*qry);
            return model;
        }
        if ( choix == "mdp")
        {
            qry->prepare("SELECT * FROM compte WHERE mdp LIKE :idc");
            qry->bindValue(":idc",("%" + text + "%")); //securité pour eviter la faille de sqlinjection

            qry->exec();
            model->setQuery(*qry);
            return model;
        }
        if ( choix == "enfant")
        {
            qry->prepare("SELECT * FROM compte WHERE enfant LIKE :idc");
            qry->bindValue(":idc",("%" + text + "%")); //securité pour eviter la faille de sqlinjection

            qry->exec();
            model->setQuery(*qry);
            return model;
        }
    }
    return model;

}

