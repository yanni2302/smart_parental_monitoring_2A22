#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QDialog>
#include"personned_aides.h"
#include "reclamation.h"
#include"smtp.h"
#include<QtMultimedia/QSound>
#include<QTimer>
namespace Ui {
class mainwindow1;
}

class mainwindow1 : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow1(QWidget *parent = nullptr);
    ~mainwindow1();
    void update_personne_list();

    void update_mail_list();
    bool controleNumTel(int test);

    bool controleVide(QString test);

    bool controleVideInt(int test);

    bool controleEmail(QString test);

private slots:


    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on_tri_clicked();

    void on_afficher_personne_activated(const QModelIndex &index);

    void on_afficher_personne_clicked(const QModelIndex &index);

    void on_envoyer_clicked();

    void on_modifier_rec_clicked();

    void on_supprimer_rec_clicked();

    void on_afficher_rec_activated(const QModelIndex &index);

    void on_afficher_rec_clicked(const QModelIndex &index);

    void on_stop_2_clicked();

    void on_stop_clicked();


private:
    Ui::mainwindow1 *ui;
    Personned_aides P;
    int id_personne=0;

    int ref_reclamation=0;
    reclamation R;
    QSound *sound;
    QTimer *timer_replay;

};

#endif // MAINWINDOW1_H
