#ifndef ENFANT_H
#define ENFANT_H

#include <QWidget>

namespace Ui {
class Enfant;
}

class Enfant : public QWidget
{
    Q_OBJECT

public:
    explicit Enfant(QWidget *parent = nullptr);
    ~Enfant();

private:
    Ui::Enfant *ui;
};

#endif // ENFANT_H
