#ifndef HOBO_GIS_MAPCANVAS_H
#define HOBO_GIS_MAPCANVAS_H

#include <QGraphicsView>
#include <QList>

class RasterLayer;
class QWheelEvent;

class MapCanvas : public QGraphicsView
{
    Q_OBJECT

public:
    explicit MapCanvas(QWidget *parent = nullptr);
    ~MapCanvas() override;

    void addRasterLayer(const QString &filePath);
    const QList<RasterLayer *> &layers() const { return mLayers; }

signals:
    void layersChanged();

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    QList<RasterLayer *> mLayers;
};

#endif // HOBO_GIS_MAPCANVAS_H
