/*#include "secu.h"
#include "ui_secu.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlQueryModel>
#include <QtCharts>
#include "motcle.h"
QChartView* secu::piechart()
{

    QPieSeries *series = new QPieSeries();
    series->append("4-6", 1);
    series->append("6-10", 2);
    series->append("10-15", 3);



    series->slices().at(0)->setValue(R_BCS1());
    series->slices().at(1)->setValue(R_BCS2());
    series->slices().at(2)->setValue(R_BCS3());

    series->slices().at(0)->setBrush(Qt::darkMagenta);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(" LES SITES INTERDITS ");


    QChartView *chartView1 = new QChartView(chart);
    chartView1->setRenderHint(QPainter::Antialiasing);
    return chartView1;
}

int secu::R_BCS1()
{
    int c21=0;
    QSqlQuery qry21;
    qry21.exec("SELECT site FROM motcle WHERE age > 2 and age < 6");
    while(qry21.next())
    {
        c21++;
    }
    return c21;
}

int secu::R_BCS2()
{
    int c20=0;
    QSqlQuery qry20;
    qry20.exec("SELECT site FROM motcle WHERE age > 6 and age < 10");
    while(qry20.next())
    {
        c20++;
    }
    return c20;
}

int secu::R_BCS3()
{
    int c19=0;
    QSqlQuery qry19;
    qry19.exec("SELECT site FROM motcle WHERE age > 10 and age < 15");
    while(qry19.next())
    {
        c19++;
    }
    return c19;
}
*/
