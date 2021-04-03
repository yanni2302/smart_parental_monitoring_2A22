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

private:
    Ui::MainWindow *ui;
    Cours1 C;
    Devoirs D;
    QMediaPlayer *player;


};
#endif // MAINWINDOW_H
