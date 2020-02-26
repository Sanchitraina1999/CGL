#include "mainwindow.h"
#include <QApplication>
#include<QLabel>
#include<math.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Assignment 2 Circle Drawing");

    QImage image(800, 800, QImage::Format_RGB888);
    QRgb value;
    value=qRgb(0,255,0);

    QImage ddaLineAlgorithm(int, int, int, int, QImage,QRgb);
    QImage bresenhamCircleAlgorithm(int, int, int, QImage,QRgb);

    /*Pattern Designing*/

    //outer Circle
    image=bresenhamCircleAlgorithm(400,400,400,image,value);

    //inner Triangle
    image=ddaLineAlgorithm(600,0,800,600,image,value);
    image=ddaLineAlgorithm(800,600,0,600,image,value);
    image=ddaLineAlgorithm(0,600,600,0,image,value);

    //inner Circle
    image=bresenhamCircleAlgorithm(400,400,200,image,value);

    QLabel l;
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    return a.exec();
}

QImage ddaLineAlgorithm(int x1, int y1, int x2, int y2,QImage image,QRgb value)
{
    int dx,dy,steps,Xinc,Yinc,x,y;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    Xinc=dx/steps;
    Yinc=dy/steps;

    x=x1;
    y=y1;

    for(int i=1;i<=steps;i++){
        image.setPixel(x,y,value);
        x+=Xinc;
        y+=Yinc;
    }
    return image;
}

//sanchit raina
//aniartihcnas
//tihcnas aniar
//imsotired
//sortlyf
//unananmouslyyours

QImage bresenhamCircleAlgorithm(int Xc, int Yc, int r,QImage image,QRgb value)
{
        int x=Xc, y=Yc;
        int i=720;
        while(i<=360){
            x=Xc+(r*cos(i));
            y=Yc+(r*sin(i));
            image.setPixel(x+320,-y+240,value);
            i+=(1);
        }
    return image;
}
