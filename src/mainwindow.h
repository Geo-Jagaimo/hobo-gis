#ifndef _HOBO_GIS_MAINWINDOW_H_
#define _HOBO_GIS_MAINWINDOW_H_

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
};

#endif // _HOBO_GIS_MAINWINDOW_H_
