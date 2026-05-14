#ifndef HOBO_GIS_MAPCANVAS_H
#define HOBO_GIS_MAPCANVAS_H

#include <QGraphicsView>

class QGraphicsPixmapItem;

class MapCanvas : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapCanvas(QWidget *parent = nullptr);
    ~MapCanvas() override;

    void loadImage(const QString &filePath);

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    QGraphicsPixmapItem *mPixmapItem = nullptr;
};

#endif // HOBO_GIS_MAPCANVAS_H
