#ifndef HOBO_GIS_MAPCANVAS_H
#define HOBO_GIS_MAPCANVAS_H

#include <QGraphicsView>

class MapCanvas : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapCanvas(QWidget *parent = nullptr);
    ~MapCanvas() override;

protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // HOBO_GIS_MAPCANVAS_H
