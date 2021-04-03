#ifndef DEVOIRS_H
#define DEVOIRS_H
#include <QString>
#include <QSqlQueryModel>

class Devoirs
{
    QString nomD;
    QString refDev;
    QString nomC;
    QString deadline;
public:
    Devoirs();
    Devoirs(QString,QString,QString,QString);
    ~Devoirs();
    /*void set_nomC(QString);
    void set_nomE(QString);
    void set_heureD(QString);
    void set_heureF(QString);
    QString get_nomC();
    QString get_nomE();
    QString get_heureD();
    QString get_heureF();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(int);
    QSqlQueryModel* chercher(QString);
    QSqlQueryModel* trier_id();
    QSqlQueryModel * trier_nom();
    */
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
};

#endif // DEVOIRS_H
