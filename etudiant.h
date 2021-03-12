ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QString>
class Etudiant
{
public:
    Etudiant();
    Etudiant (int,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    void set_id(int);
    void set_nom(QString);
    void set_prenom(QString);

private:
    int id;
    QString nom,prenom;
};

#endif // ETUDIANT_H
