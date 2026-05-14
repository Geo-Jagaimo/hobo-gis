#ifndef HOBO_GIS_MAINWINDOW_H
#define HOBO_GIS_MAINWINDOW_H

#include <QMainWindow>

class MapCanvas; // 前方宣言：classがあることを教える
class LayerPanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void openImage();

private:
    MapCanvas *mCanvas;
    LayerPanel *mLayerPanel;
};

#endif // HOBO_GIS_MAINWINDOW_H
