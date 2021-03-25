#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cours1.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_b_ajoutC_clicked();

    void on_suppCours_3_clicked();


private:
    Ui::MainWindow *ui;
    Cours1 C;

};
#endif // MAINWINDOW_H
