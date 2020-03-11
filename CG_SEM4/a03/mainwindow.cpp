#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "iostream"
using namespace std;


/**************Global Variables**************/
QImage image(791,601,QImage::Format_RGB888);
QRgb white=qRgb(255,255,255);
QRgb black=qRgb(0,0,0);
bool start=false;
int i=0,x1,x2,y1,y2;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap::fromImage(image));
    vertices=0;
    start=false;
    ddaLine(395,0,395,600);
    ddaLine(0,300,790,300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *events){
    int x,y;
    if(!start)return;
    if(i<vertices){
        x=events->pos().x();
        y=events->pos().y();
        if(x>=15&&x<=791&&y>=32&&y<=601){
            coordinates[i][0]=x-10;
            coordinates[i][1]=y-30;
            image.setPixel(x-10,y-30,white);
            ui->label->setPixmap(QPixmap::fromImage(image));
            ui->label->show();
            i++;
        }
    }
    if(i==vertices){
        for(int i=0;i<vertices-1;i++){
            x1=coordinates[i][0];
            y1=coordinates[i][1];
            x2=coordinates[i+1][0];
            y2=coordinates[i+1][1];
            ddaLine(x1,y1,x2,y2);
        }
        x1=coordinates[0][0];
        y1=coordinates[0][1];
        ddaLine(x1,y1,x2,y2);
        start=false;
    }
}

void MainWindow::ddaLine(int x1, int y1, int x2, int y2){
    float dx,dy,steps,xinc,yinc;
    dx=x2-x1;
    dy=y2-y1;

    steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    xinc=dx/steps;
    yinc=dy/steps;

    float x=x1;
    float y=y1;

    for(int i=0;i<=steps;i++){
        image.setPixel(x,y,white);
        x=x+xinc;
        y=y+yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_textEdit_textChanged()  //No. of Points
{
    QString str=ui->textEdit->toPlainText();
    vertices=str.toInt();
    start=true;
    i=0;
}

void MainWindow::on_textEdit_2_textChanged()    //Sx
{

}

void MainWindow::on_textEdit_3_textChanged()    //Sy
{

}

void MainWindow::on_textEdit_4_textChanged()    //Tx
{

}

void MainWindow::on_textEdit_5_textChanged()    //Ty
{

}

void MainWindow::on_textEdit_6_textChanged()    //Angle
{

}

void MainWindow::on_pushButton_clicked()    //Scale
{

}

void MainWindow::on_pushButton_2_clicked()      //Transelate
{

}

void MainWindow::on_pushButton_3_clicked()      //Rotate
{

}
