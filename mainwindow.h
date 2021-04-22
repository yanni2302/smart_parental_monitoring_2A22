#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "timeclass.h"
#include "motcle.h"
#include "QtMultimedia/QSound"
#include "arduino_bouton.h"
#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void update ();
    ~MainWindow();

private slots:

     void update_label();
    void on_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_ajouter_2_clicked();

    void on_ajouter_3_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pb_supp_2_clicked();

    void on_ajouter_4_clicked();

    void on_trie_clicked();

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
bool controleVide(QString );
bool controleVideInt(int );
private:
    Ui::MainWindow *ui;
    timeclass T;
    QString id_enfant;
    motcle M;
    int id_site=0;
    QSound *Sound;
QSound *Soundclic;

QByteArray data; // variable contenant les données reçues

Arduino_bouton A; // objet temporaire
};

#endif // MAINWINDOW_H
