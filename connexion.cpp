#include "connexion.h"
#include<QSqlDatabase>

Connexion::Connexion()
{

}
bool Connexion::CreateConnection()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_2A");
    db.setUserName("jihed");
    db.setPassword("jihed123");
    if(db.open())
    {test=true;}
    return test;
}
