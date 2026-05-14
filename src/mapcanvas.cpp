#include "mapcanvas.h"

#include <QGraphicsScene>
#include <QWheelEvent>
#include <QPen>
#include <QBrush>

MapCanvas::MapCanvas(QWidget *parent) : QGraphicsView(parent)
{
    // シーンを作ってセット
    auto *scene = new QGraphicsScene(this);
    setScene(scene);

    // シーンの範囲を定義
    // x, y, width, height
    scene->setSceneRect(-500, -500, 1000, 1000);

    // 動作確認用の矩形
    scene->addRect(-100, -100, 200, 200, QPen(Qt::blue, 2), QBrush(Qt::lightGray));

    // アンチエイリアス有効化
    setRenderHint(QPainter::Antialiasing);
    // マウスドラッグでシーンをパン
    setDragMode(QGraphicsView::ScrollHandDrag);
    // ズームの中心をマウス位置にする
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}

MapCanvas::~MapCanvas() = default;

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
