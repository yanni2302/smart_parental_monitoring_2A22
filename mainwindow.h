#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cours1.h>
#include <devoirs.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QMediaPlayer;
class QSqlTableModel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_b_ajoutC_clicked();

    void on_suppCours_3_clicked();

    void on_modif_button_clicked();

   void on_chercher_cours_clicked();

    void on_chercher_clicked();

    void on_trier_cours_clicked();

    void on_pushButton_clicked();

    void on_stat_clicked();

    void on_b_ajout_dev_clicked();

    void on_suppCours_4_clicked();

    void on_lineEdit_chercher_textChanged(const QString &arg1);

    void on_lineEdit_chercher_2_textChanged(const QString &arg1);

    void on_coursView_clicked(const QModelIndex &index);

    void on_coursView_activated(const QModelIndex &index);

    void on_modif_button_3_clicked(bool checked);

    void on_modif_button_3_clicked();

    void on_imprimer_devoirs_clicked();

    void on_coursView_2_activated(const QModelIndex &index);

    void on_coursView_2_clicked(const QModelIndex &index);

    void on_modifier_clicked();

    void on_trier_cours_2_clicked();

    void on_chercher_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);
    bool controleVide(QString test);
    bool controleVideInt(int test);

private:
    Ui::MainWindow *ui;
    Cours1 C;
    Devoirs D;
    QMediaPlayer *player;
    int id_eq=0;
    int id_Dev=0;


};
#endif // MAINWINDOW_H
