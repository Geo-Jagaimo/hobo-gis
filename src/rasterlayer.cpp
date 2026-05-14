#include "rasterlayer.h"

#include <QFileInfo>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QDebug>

RasterLayer::RasterLayer(const QString &filePath, QObject *parent)
    : QObject(parent), mName(QFileInfo(filePath).fileName()), mItem(nullptr)
{
    QPixmap pixmap(filePath);
    if (pixmap.isNull())
    {
        qWarning() << "Failed to load image:" << filePath;
        return;
    }
    mItem = new QGraphicsPixmapItem(pixmap);
}

RasterLayer::~RasterLayer()
{
    if (mItem)
    {
        if (mItem->scene())
        {
            mItem->scene()->removeItem(mItem);
        }
        delete mItem;
    }
}

void RasterLayer::setVisible(bool visible)
{
    if (mVisible == visible)
    {
        return;
    }
    mVisible = visible;
    if (mItem)
    {
        mItem->setVisible(visible);
    }
    emit visibilityChanged(visible); // setXxx系のメソッドは、変わったときだけ通知
}
