#ifndef HOBO_GIS_MAINWINDOW_H
#define HOBO_GIS_MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
};

#endif // HOBO_GIS_MAINWINDOW_H
