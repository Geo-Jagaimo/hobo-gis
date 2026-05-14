#include "mapcanvas.h"

#include <QGraphicsScene>
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
    scene->addRect(-100, -100, 200, 200,
                   QPen(Qt::blue, 2),
                   QBrush(Qt::lightGray));

    // アンチエイリアス有効化
    setRenderHint(QPainter::Antialiasing);

    // マウスドラッグでシーンをパン
    setDragMode(QGraphicsView::ScrollHandDrag);
}
