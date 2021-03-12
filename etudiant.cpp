#include "etudiant.h"
#include <QString>
Etudiant::Etudiant()
{
  id = 0;
  nom = "";
  prenom = "";
}
Etudiant::Etudiant(int id,QString nom,QString prenom)
{
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;

}
void Etudiant::set_id(int id)
{
    this->id=id;
}
void Etudiant::set_nom(QString nom)
{
    this->nom=nom;
}
void Etudiant::set_prenom(QString prenom )
{
    this->prenom=prenom;
}
int Etudiant::get_id()
{
   return id;
}
QString Etudiant::get_nom()
{
    return nom;
}
QString Etudiant::get_prenom(  )
{
    return prenom;
}
