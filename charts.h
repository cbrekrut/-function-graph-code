#ifndef CHARTS_H
#define CHARTS_H

#include <QDialog>
#include <QtCharts>
#include <QLineSeries>
#include <QChartView>


namespace Ui {
  class charts;
}

class charts : public QDialog
{
  Q_OBJECT

public:
  explicit charts(QWidget *parent = nullptr);
  ~charts();


private:
  Ui::charts *ui;

public slots:
      void slot(double a,double b,double c,QString text);//слот для принятия сигнала
  };


#endif // CHARTS_H
