#ifndef COURS1_H
#define COURS1_H
#include <QString>
#include <QSqlQueryModel>
#include <QTranslator>

class Cours1
{
    void on_b_ajoutC_clicked();
    QString nomC;
    QString nomE;
    QString heureD;
    QString heureF;
    int numero;
public:
    Cours1();
    Cours1(QString,QString,QString,QString,int);
    ~Cours1();
    void set_nomC(QString);
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

};

#endif // COURS1_H

