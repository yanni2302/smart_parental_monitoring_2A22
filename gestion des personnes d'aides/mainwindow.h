#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"personned_aides.h"
#include "reclamation.h"
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
private slots:



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

private:
    Ui::MainWindow *ui;
     Personned_aides P;
     int id_personne=0;

     int ref_reclamation=0;
     reclamation R;
};

#endif // MAINWINDOW_H
