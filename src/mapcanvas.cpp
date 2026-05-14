#include "mapcanvas.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWheelEvent>
#include <QDebug>

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

void MapCanvas::loadImage(const QString &filePath)
{
    QPixmap pixmap(filePath);
    if (pixmap.isNull())
    {
        qWarning() << "Failed to load image:" << filePath;
        return;
    }

    scene()->clear();
    mPixmapItem = nullptr; // clear()で削除されたので参照クリア

    mPixmapItem = scene()->addPixmap(pixmap);

    scene()->setSceneRect(pixmap.rect()); // シーン範囲を画像に合わせる

    fitInView(mPixmapItem, Qt::KeepAspectRatio);
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
