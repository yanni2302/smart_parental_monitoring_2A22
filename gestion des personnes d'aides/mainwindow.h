#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"personned_aides.h"
#include "reclamation.h"
#include"smtp.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void update_personne_list();

    void update_mail_list();
    bool controleNumTel(int test);

    bool controleVide(QString test);

    bool controleVideInt(int test);

    bool controleEmail(QString test);

private slots:

void sendMail();
 void mailSent(QString);
    void on_ajouter_clicked();

    void on_supprimer_clicked();


    void on_afficher_personne_activated(const QModelIndex &index);

    void on_modifier_clicked();

    void on_afficher_personne_clicked(const QModelIndex &index);


    void on_envoyer_clicked();

    void on_afficher_rec_activated(const QModelIndex &index);

    void on_afficher_rec_clicked(const QModelIndex &index);

    void on_modifier_rec_clicked();

    void on_supprimer_rec_clicked();

    void on_tri_clicked();

    void on_recherche_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
     Personned_aides P;
     int id_personne=0;

     int ref_reclamation=0;
     reclamation R;
};

#endif // MAINWINDOW_H
