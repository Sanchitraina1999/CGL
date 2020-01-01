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


       /*Outer Rectangle*/


       //line PRLL to X axis
       for(int x=100;x<=300;x++){
       image.setPixel(x,200,value);
       image.setPixel(x,300,value);
      }


       //line PRLL to Y axis
       for(int y=200;y<=300;y++){
       image.setPixel(100,y,value);
       image.setPixel(300,y,value);
      }


       /*Inner Trapezium*/


       //INNER LEFT UPPER
       for(int x=200;x>=100;x--){
           int y=(600-x)/2;
         image.setPixel(x,y,value);
         image.setPixel(x,y,value);
      }

       //INNER RIGHT UPPER
       for(int x=200;x<=300;x++){
           int y=(200+x)/2;
         image.setPixel(x,y,value);
         image.setPixel(x,y,value);
      }
       //INNER LEFT BOTTOM
       for(int x=200;x>=100;x--){
           int y=(x+400)/2;
         image.setPixel(x,y,value);
         image.setPixel(x,y,value);
      }

       //INNER RIGHT BOTTOM
       for(int x=200;x<=300;x++){
           int y=(800-x)/2;
         image.setPixel(x,y,value);
         image.setPixel(x,y,value);
      }

       /*Innermost Rectangle*/

       //line PRLL to X axis
       for(int x=150;x<=250;x++){
       image.setPixel(x,225,value);
       image.setPixel(x,275,value);
      }

       //line PRLL to Y axis
       for(int y=225;y<=275;y++){
       image.setPixel(150,y,value);
       image.setPixel(250,y,value);
      }


       QLabel l;
       l.setPixmap(QPixmap::fromImage(image));
       l.show();
    return a.exec();
}
