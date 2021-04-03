#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include"mainwindow1.h"
namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();
    bool controleVide(QString test);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
