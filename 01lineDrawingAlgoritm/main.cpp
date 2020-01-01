#include "mainwindow.h"
#include <QApplication>

void ddaAlgorithm(int, int, int, int);
void bresenhamAlgorithm(int, int, int, int);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;\

    QImage image(800, 800, QImage::Format_RGB888);
    QRgb value;
    value=qRgb(0,255,0);

    /*
        For showing pixel on screen
    */
    QLabel l;
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    return a.exec();
}

void ddaAlgorithm(int, int, int, int)
{

}

void bresenhamAlgorithm(int, int, int, int)
{

}
