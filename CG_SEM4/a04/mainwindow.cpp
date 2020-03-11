#include "mainwindow.h"
#include "ui_mainwindow.h"

/********Global Variables********/
QImage image(921,591,QImage::Format_RGB888);
QImage pallete(71,31,QImage::Format_RGB888);
QRgb white=qRgb(255,255,255);
QRgb color=white;
int i=0,x1,y1,x2,y2,r,g,b;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pallete.fill(color);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label_3->setPixmap(QPixmap::fromImage(pallete));
    vertices=0;
    start=false;
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
        if(x>=15&&x<=925&&y>=32&&y<=613){
            coordinates[i][0]=x-10;
            coordinates[i][1]=y-30;
            plotPoint(x-10,y-30);
            i++;
        }
    }
}
void MainWindow::on_plainTextEdit_textChanged()
{
    QString str=ui->plainTextEdit->toPlainText();
    vertices=str.toInt();
    start=true;
    i=0;
}

void MainWindow::on_pushButton_2_clicked()
{
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
        image.setPixel(x,y,color);
        x=x+xinc;
        y=y+yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::plotPoint(int x, int y)
{
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            image.setPixel(x+i,y+j,white);

    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    r=value;
    color=qRgb(r,g,b);
    pallete.fill(color);
    ui->label_3->setPixmap(QPixmap::fromImage(pallete));
    ui->label_3->show();
}

void MainWindow::on_verticalSlider_2_valueChanged(int value)
{
    g=value;
    color=qRgb(r,g,b);
    pallete.fill(color);
    ui->label_3->setPixmap(QPixmap::fromImage(pallete));
    ui->label_3->show();
}

void MainWindow::on_verticalSlider_3_valueChanged(int value)
{
    b=value;
    color=qRgb(r,g,b);
    pallete.fill(color);
    ui->label_3->setPixmap(QPixmap::fromImage(pallete));
    ui->label_3->show();
}

void MainWindow::on_pushButton_clicked()
{
    image.fill(qRgb(0,0,0));
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}
