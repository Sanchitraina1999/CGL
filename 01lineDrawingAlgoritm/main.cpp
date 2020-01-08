#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QImage image(800, 800, QImage::Format_RGB888);
    QRgb value;
    value=qRgb(0,255,0);

    QImage ddaAlgorithm(int, int, int, int, QImage,QRgb);

    //outerRectangle
    image=ddaAlgorithm(100,100,700,100,image,value);
    image=ddaAlgorithm(100,100,100,700,image,value);
    image=ddaAlgorithm(100,700,700,700,image,value);
    image=ddaAlgorithm(700,100,700,700,image,value);

    //inner trapezium
    image=ddaAlgorithm(100,400,400,100,image,value);
    image=ddaAlgorithm(400,100,700,400,image,value);
    image=ddaAlgorithm(700,400,400,700,image,value);
    image=ddaAlgorithm(400,700,100,400,image,value);

    //inner Rectangle
    image=ddaAlgorithm(250,250,550,250,image,value);
    image=ddaAlgorithm(550,250,550,550,image,value);
    image=ddaAlgorithm(550,550,250,550,image,value);
    image=ddaAlgorithm(250,550,250,250,image,value);

    /*
    For display
    */

    QLabel l;
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    return a.exec();
}

QImage ddaAlgorithm(int x1, int y1, int x2, int y2,QImage image,QRgb value)
{
    int dx,dy,steps,Xinc,Yinc,x,y;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    Xinc=(float)dx/steps;
    Yinc=(float)dy/steps;

    x=x1;
    y=y1;

    for(int i=1;i<=steps;i++){
        image.setPixel(x,y,value);
        x+=Xinc;
        y+=Yinc;
    }

    return image;
}
