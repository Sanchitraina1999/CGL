#include "widget.h"
#include <QApplication>
#include <QPainter>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(300,300);
    w.move(300,300);
    w.show();
    return a.exec();
}
