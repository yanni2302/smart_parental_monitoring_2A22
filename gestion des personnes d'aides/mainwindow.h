#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"personned_aides.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_ajouter_clicked();

    void on_supprimer_clicked();


    void on_afficher_personne_activated(const QModelIndex &index);

    void on_modifier_clicked();

    void on_afficher_personne_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
     Personned_aides P;
     int id_personne=0;
};

#endif // MAINWINDOW_H
