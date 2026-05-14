#include "mainwindow.h"
#include "mapcanvas.h"
#include "layerpanel.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QFileDialog>
#include <QMenu>
#include <gdal.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          mCanvas(new MapCanvas(this)),
                                          mLayerPanel(new LayerPanel(mCanvas, this))
{
    setWindowTitle("hobo-gis");
    resize(800, 600);
    // 中央ウィジェットとしてキャンバスを表示
    setCentralWidget(mCanvas);

    // レイヤパネル
    addDockWidget(Qt::LeftDockWidgetArea, mLayerPanel);

    // メニューバー
    menuBar()->setNativeMenuBar(false); // macOS
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(tr("&Open Image..."), this, &MainWindow::openImage);
    fileMenu->addAction(tr("&Quit"), this, &QWidget::close);

    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(mLayerPanel->toggleViewAction());

    // ステータスバーにGDALバージョンを表示
    GDALAllRegister();
    const QString gdalVersion = QString::fromUtf8(GDALVersionInfo("RELEASE_NAME"));
    statusBar()->showMessage(tr("Ready  |  GDAL %1").arg(gdalVersion));
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

    mCanvas->addRasterLayer(filePath);
    statusBar()->showMessage(tr("Added: %1").arg(filePath), 5000);
}
