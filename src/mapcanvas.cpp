#include "mapcanvas.h"
#include "rasterlayer.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>

MapCanvas::MapCanvas(QWidget *parent) : QGraphicsView(parent)
{
    // シーンを作ってセット
    auto *scene = new QGraphicsScene(this);
    setScene(scene);

    setRenderHint(QPainter::Antialiasing);          // アンチエイリアス有効化
    setRenderHint(QPainter::SmoothPixmapTransform); // 拡大時の画像補間
    setDragMode(QGraphicsView::ScrollHandDrag);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}

MapCanvas::~MapCanvas() = default;

void MapCanvas::addRasterLayer(const QString &filePath)
{
    auto *layer = new RasterLayer(filePath, this);
    if (!layer->isValid())
    {
        delete layer;
        return;
    }

    mLayers.append(layer);
    scene()->addItem(layer->graphicsItem());

    // 1枚目の画像であれば、シーンの範囲とビューを画像に合わせる
    if (mLayers.size() == 1)
    {
        scene()->setSceneRect(layer->graphicsItem()->boundingRect());
        fitInView(layer->graphicsItem(), Qt::KeepAspectRatio);
    }

    emit layersChanged();
}

void MapCanvas::wheelEvent(QWheelEvent *event)
{
    constexpr double zoomFactor = 1.2;

    // 上限・下限
    constexpr double minScale = 0.05;
    constexpr double maxScale = 50.0;

    // 現在のスケール
    const double currentScale = transform().m11();
    /*
    | m11  m12  m13 |   x方向スケール、せん断、回転
    | m21  m22  m23 |   y方向〜
    | m31  m32  m33 |   平行移動
    */

    if (event->angleDelta().y() > 0)
    {
        // ホイール上 = ズームイン
        if (currentScale < maxScale)
        {
            scale(zoomFactor, zoomFactor);
        }
    }
    else
    {
        // ホイール下 = ズームアウト
        if (currentScale > minScale)
        {
            scale(1.0 / zoomFactor, 1.0 / zoomFactor);
        }
    }

    event->accept();
}
