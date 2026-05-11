#include "mainwindow.h"

#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("hobo-gis");
    resize(800, 600);

    menuBar()->addMenu("&File");
    menuBar()->addMenu("&View");

    statusBar()->showMessage("Ready");
}

MainWindow::~MainWindow() = default;
