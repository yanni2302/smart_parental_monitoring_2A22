#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "timeclass.h"
#include <QMainWindow>
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

    void on_pb_supp_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_ajouter_2_clicked();

private:
    Ui::MainWindow *ui;
    timeclass T;
    QString id_enfant;
};

#endif // MAINWINDOW_H
