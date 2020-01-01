#include "mainwindow.h"
#include <QApplication>
#include<QtGui>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QImage image(400, 400, QImage::Format_RGB888);
       QRgb value;
       value=qRgb(0,255,0);
       /*draws a line using setPixel() function*/

    /*Circle*/


       for(int x=200;x<=300;x++){
            int y;
            y=10000-(x*x);
            image.setPixel(x,y,value);
      }


       QLabel l;
       l.setPixmap(QPixmap::fromImage(image));
       l.show();
    return a.exec();
}
