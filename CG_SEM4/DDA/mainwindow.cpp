#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
int x1,x2,y1,y2;
QImage image(771,571,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_textEdit_textChanged()
{
    QString str=ui->textEdit->toPlainText();
    x1=str.toFloat();
}

void MainWindow::on_textEdit_2_textChanged()
{
    QString str=ui->textEdit_2->toPlainText();
    y1=str.toFloat();
}

void MainWindow::on_textEdit_3_textChanged()
{
    QString str=ui->textEdit_3->toPlainText();
    x2=str.toFloat();
}

void MainWindow::on_textEdit_4_textChanged()
{
    QString str=ui->textEdit_4->toPlainText();
    y2=str.toFloat();
}

void MainWindow::on_pushButton_clicked()
{
    float dx,dy,steps,xinc,yinc;
    dx=x2-x1;
    dy=y2-y1;

    steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    xinc=dx/steps;
    yinc=dy/steps;

    QRgb green;
    green=qRgb(0,255,0);
    float x=x1;
    float y=y1;

    for(int i=0;i<=steps;i++){
        image.setPixel(x,y,green);
        x=x+xinc;
        y=y+yinc;
    }

    ui->label_6->setPixmap(QPixmap::fromImage(image));
    ui->label_6->show();

}
