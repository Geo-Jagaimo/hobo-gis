#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("example");
    QCoreApplication::setApplicationName("hobo-gis");
    QCoreApplication::setApplicationVersion("1.0");

    MainWindow window;
    window.show();

    return app.exec();
}
