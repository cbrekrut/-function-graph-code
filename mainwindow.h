#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "charts.h"
#include <QMainWindow>

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
    void on_graphic_clicked();

private:
    Ui::MainWindow *ui;
    charts *dialog;

signals:
    void signal(double,double,double,QString);//сигнал передачи параметров во второе окно
};
#endif // MAINWINDOW_H

