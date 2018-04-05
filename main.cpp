#include "mainwindow.h"
#include <QApplication>
#include <QtDataVisualization>



using namespace QtDataVisualization;

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    Q3DScatter scatter;
    scatter.setFlags(scatter.flags() ^ Qt::FramelessWindowHint);
    QScatter3DSeries *series = new QScatter3DSeries;
    QScatterDataArray data;
    for (double j=0;j<=10;j+=0.1)
    {
    for (double i=0;i<=10;i+=0.1)
    data << QVector3D(i, sin(i), j);
    }
    series->dataProxy()->addItems(data);
    scatter.addSeries(series);
    scatter.show();

    return app.exec();
}
