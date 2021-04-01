#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "timeclass.h"
#include "motcle.h"

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

private:
    Ui::MainWindow *ui;
    timeclass T;
    QString id_enfant;
    motcle M;
    int id_site=0;
};

#endif // MAINWINDOW_H
