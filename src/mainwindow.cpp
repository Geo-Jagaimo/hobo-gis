#include "mainwindow.h"
#include "mapcanvas.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QMenu>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), mCanvas(new MapCanvas(this))
{
    setWindowTitle("hobo-gis");
    resize(800, 600);
    // 中央ウィジェットとしてキャンバスを表示
    setCentralWidget(mCanvas);

    // メニューバー
    menuBar()->setNativeMenuBar(false); // macOS
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(tr("&Open Image..."), this, &MainWindow::openImage);
    fileMenu->addAction(tr("&Quit"), this, &QWidget::close);

    menuBar()->addMenu(tr("&View"));

    // ステータスバー
    statusBar()->showMessage("Ready");
}

MainWindow::~MainWindow() = default;

void MainWindow::openImage()
{
    const QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("Open Image"),
        QString(),
        tr("Images (*.png *.jpg *.jpeg *.bmp *.tif *.tiff)"));

    if (filePath.isEmpty())
    {
        return;
    }

    mCanvas->loadImage(filePath);
    statusBar()->showMessage(tr("Loaded: %1").arg(filePath), 5000);
}
