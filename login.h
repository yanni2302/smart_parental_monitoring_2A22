#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>
#include <QWidget>
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_connet_clicked();

private:
    Ui::login *ui;
    MainWindow *m;
};

#endif // LOGIN_H
