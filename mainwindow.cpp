#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charts.h"

////////////////////////////////////////////////////////////////////
/// По тех заданию надо было сделать одноконное приложение
/// но мною было принято решение показать работу сигналов и слотов
/// поэтому реализовал два окна в приложении
///////////////////////////////////////////////////////////////////


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog = new charts;

    connect(this,&MainWindow::signal,dialog,&charts::slot);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_graphic_clicked(){
   emit signal(ui->doubleSpinBox_x_min->value(),ui->doubleSpinBox_x_max->value(),ui->doubleSpinBox_e->value(),ui->lineEdit->text());
   charts window;
   window.setModal(true);
   window.exec();
}


