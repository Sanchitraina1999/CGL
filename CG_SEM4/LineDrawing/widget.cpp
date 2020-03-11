#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<iostream>
#include<math.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}
Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter qp(this);
    dda(&qp);
    bresenhams(&qp);
}
void Widget::dda(QPainter *qp)
{
    float x1=100,y1=100,x2=200,y2=100,dx,dy,len,i;
    QPen pen(Qt::blue,5,Qt::SolidLine);
    qp->setPen(pen);
    float x,y,xinc,yinc;
    dx=(x2-x1);
    dy=(y2-y2);
    if(abs(dx)>=abs(dy))
        len=dx;
    else
        len=dy;
    xinc=float(dx)/len;
    yinc=float(dy/len);
    x=x1;
    y=y1;
    qp->drawPoint(x,y);
    for(i=1;i<=len;i++)
    {
        x=x+xinc;
        y=y+yinc;
        qp->drawPoint(x,y);
    }
}
void Widget::bresenhams(QPainter *qp)
{
    int x1=200;
    int y1=200;
    int x2=300;
    int y2=300;
    int i,x,y,steps,dx,dy,G;
    QPen pen(Qt::black,2,Qt::SolidLine);
    qp->setPen(pen);
    dx=x2-x1;
    dy=y2-y1;
    x=x1;
    y=y1;
    if(abs(dx)>abs(dy))
    {
        steps=dx;
    }
    else
    {
        steps=dy;
    }
qp->drawPoint(x,y);
G= 2*dy-dx;
for(i=0;i<steps;i++)
{
    if(G>=0)
    {
        x=x+1;
        y=y+1;
        qp->drawPoint(x,y);
        G=G+2*(dy-dx);
    }
    else
    {
        x=x+1;
        qp->drawPoint(x,y);
        G=G+2*dy;
    }
    }
}

