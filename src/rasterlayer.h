#ifndef HOBO_GIS_RASTERLAYER_H
#define HOBO_GIS_RASTERLAYER_H

#include <QObject>
#include <QString>

class QGraphicsPixmapItem;

class RasterLayer : public QObject // シグナルを出すためにQBbjectを継承
{
    Q_OBJECT

public:
    explicit RasterLayer(const QString &filePath, QObject *parent = nullptr);
    ~RasterLayer() override;

    QString name() const { return mName; }
    bool isValid() const { return mItem != nullptr; }
    bool isVisible() const { return mVisible; }

    QGraphicsPixmapItem *graphicsItem() const { return mItem; }

public slots:
    void setVisible(bool visible);

signals:
    void visibilityChanged(bool visible);

private:
    QString mName;
    QGraphicsPixmapItem *mItem;
    bool mVisible = true;
};

#endif // HOBO_GIS_RASTERLAYER_H
