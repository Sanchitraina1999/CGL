#include "mainwindow.h"
#include<QLabel>
#include<iostream>
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Assignment 1 Line Drawing");

    QImage image(800, 800, QImage::Format_RGB888);
    QRgb value;
    value=qRgb(0,255,0);
    QImage ddaAlgorithm(int, int, int, int, QImage,QRgb);
    QImage bresenhamAlgorithm(int, int, int, int, QImage,QRgb);

    //outerRectangle
    image=bresenhamAlgorithm(100,100,700,100,image,value);
    image=bresenhamAlgorithm(100,100,100,700,image,value);
    image=bresenhamAlgorithm(100,700,700,700,image,value);
    image=bresenhamAlgorithm(700,100,700,700,image,value);

    //inner trapezium
    image=ddaAlgorithm(100,400,400,100,image,value);
    image=ddaAlgorithm(400,100,700,400,image,value);
    image=ddaAlgorithm(700,400,400,700,image,value);
    image=ddaAlgorithm(400,700,100,400,image,value);

    //inner Rectangle
    image=bresenhamAlgorithm(250,250,550,250,image,value);
    image=bresenhamAlgorithm(550,250,550,550,image,value);
    image=bresenhamAlgorithm(550,550,250,550,image,value);
    image=bresenhamAlgorithm(250,550,250,250,image,value);

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

QImage bresenhamAlgorithm(int x1, int y1, int x2, int y2,QImage image,QRgb value)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int x=x1;
    int y=y1;
    bool swapped=false;
    int sx=x2>x1?1:(-1);
    int sy=y2>y1?1:(-1);
    if(abs(dx)<abs(dy)){ //if slope>m
        swap(dx,dy);
        swap(x,y);
        swap(sx,sy);
        swapped=true;
    }
    int pk=2*abs(dy)-abs(dx);
    for(int i=0;i<abs(dx);i++){
        if(swapped)
            image.setPixel(y,x,value);
        else
            image.setPixel(x,y,value);
        x+=sx;
        if(pk<0)
            pk=pk+2*abs(dy);
        else{
            y+=sy;
            pk=pk+2*abs(dy)-2*abs(dx);
        }
    }
    return image;
}
