#include "charts.h"
#include "ui_charts.h"
#include "parser.h"
std::string foo;
double xmax,
        xmin,
        e;
float Y;
void charts::slot(double a,double b,double c,QString text) //слот приема параметров из первого окна
{xmax = b;xmin = a;e=c;foo = text.toStdString();}

charts::charts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charts)
{
    ui->setupUi(this);

 QLineSeries *series = new QLineSeries();//Задаем параметры линии графика
 series->setPointLabelsVisible(true);
 series->setColor(QColor(255,0,0));
 series->setPointLabelsColor(QColor(255,255,255));
 series-> setPointLabelsFont (QFont ("Microsoft Yahei"));
 series->setPointLabelsFormat("(@xPoint,@yPoint)");
 series->setPointsVisible(true);

 while(xmin<xmax){//подсчет значений y относительно Xmin
     Y = parser(foo,xmin);
     series->append(xmin,Y);
     xmin+=e;
   }

 QChart *chart = new QChart();//Задаем параметры графика
 chart->addSeries(series);
 chart->legend()->hide();
 chart-> setTheme (QChart :: ChartThemeBlueCerulean);
 chart->createDefaultAxes();
 chart->setTitle("Line Chart");

 QChartView *chartView = new QChartView(chart); //Прорисовываем график
 chartView->setRenderHint(QPainter::Antialiasing);
 chartView->setParent(ui->linechart);
}

 charts::~charts()
{delete ui;}

