#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    QRect geometry = QApplication::desktop()->availableGeometry();

    w.setGeometry(geometry.x() - geometry.width() / 2, geometry.y() - geometry.height() / 2, w.width(), w.height());

    w.show();

    return a.exec();
}







