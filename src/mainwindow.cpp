#include "mainwindow.h"
#include "mapcanvas.h"

#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          mCanvas(new MapCanvas(this))
{
    setWindowTitle("hobo-gis");
    resize(800, 600);

    // 中央ウィジェットとしてキャンバスを表示
    setCentralWidget(mCanvas);

    // メニューバー
    menuBar()->addMenu("&File");
    menuBar()->addMenu("&View");

    // ステータスバー
    statusBar()->showMessage("Ready");
}

MainWindow::~MainWindow() = default;
