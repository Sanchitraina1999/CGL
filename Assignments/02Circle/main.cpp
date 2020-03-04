#include "mainwindow.h"
#include <QApplication>
#include<QLabel>
#include<math.h>

QImage ddaLineAlgorithm(int, int, int, int, QImage,QRgb);
QImage bresenhamCircleAlgorithm(int, int, int, QImage,QRgb);
QImage ddaCircleAlgorithm(int,int,int,QImage,QRgb);
QImage drawCircle(int,int,int,int,QImage,QRgb);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Assignment 2 Circle Drawing");

    QImage image(800, 800, QImage::Format_RGB888);
    QRgb value;
    value=qRgb(0,255,0);

    /*Pattern Designing*/
    image.setPixel(400,400,value);
    //outer Circle
    image=ddaCircleAlgorithm(400,400,200,image,value);    //to be done using bresenham's Circle Drawing Algorithm

    //inner Triangle
    image=ddaLineAlgorithm(400,200,575,500,image,value);
    image=ddaLineAlgorithm(400,200,225,500,image,value);
    image=ddaLineAlgorithm(225,500,575,500,image,value);

    //inner Circle
    image=ddaCircleAlgorithm(400,400,100,image,value);

    QLabel l;
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    return a.exec();
}

QImage ddaLineAlgorithm(int x1, int y1, int x2, int y2,QImage image,QRgb value)
{
    float dx,dy,steps,Xinc,Yinc,x,y;
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

QImage bresenhamCircleAlgorithm(int xc, int yc, int r,QImage image,QRgb value)
{
    int x=0,y=r;
    int d=3-2*r;
    drawCircle(xc,yc,x,y,image,value);
    while(y>=x){
        x++;
        if(d>0){
            y--;
            d=d+4*(x-y)+10;
        }
        else
            d=d+4*x+6;
    drawCircle(xc,yc,x,y,image,value);
    }
    return image;
}

QImage drawCircle(int xc, int yc, int x, int y, QImage image,QRgb value){
    image.setPixel(xc+x,yc+y,value);
    image.setPixel(xc-x,yc+y,value);
    image.setPixel(xc+x,yc-y,value);
    image.setPixel(xc-x,yc-y,value);
    image.setPixel(xc+y,yc+x,value);
    image.setPixel(xc-y,yc+x,value);
    image.setPixel(xc+y,yc-x,value);
    image.setPixel(xc-y,yc-x,value);
    image.setPixel(xc,yc,value);
    return image;
}

QImage ddaCircleAlgorithm(int xc, int yc, int r,QImage image,QRgb value)
{
    double xc1,xc2,yc1,yc2,eps,sx,sy;
    int val,i;
     xc1=r;
     yc1=0;
     sx=xc1;
     sy=yc1;
     i=0;
     do{
         val=pow(2,i);
         i++;
         }while(val<r);
     eps = 1/pow(2,i-1);
     do{
         xc2 = xc1 + yc1*eps;
         yc2 = yc1 - eps*xc2;
         image.setPixel(xc+xc2,yc-yc2,value);
         xc1=xc2;
         yc1=yc2;
        }while((yc1-sy)<eps || (sx-xc1)>eps);
    return image;
}
