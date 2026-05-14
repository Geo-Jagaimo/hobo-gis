#include "layerpanel.h"
#include "mapcanvas.h"
#include "rasterlayer.h"

#include <QListWidget>

LayerPanel::LayerPanel(MapCanvas *canvas, QWidget *parent)
    : QDockWidget(tr("Layers"), parent), mCanvas(canvas), mListWidget(new QListWidget(this))
{
    setWidget(mListWidget);

    // キャンバスのレイヤー構成が変わったら表示を更新
    connect(mCanvas, &MapCanvas::layersChanged,
            this, &LayerPanel::refresh);

    // リスト項目のチェック状態変更を捕まえる
    connect(mListWidget, &QListWidget::itemChanged,
            this, &LayerPanel::onItemChanged);
}

LayerPanel::~LayerPanel() = default;

void LayerPanel::refresh()
{
    // refresh中の itemChanged を抑制
    mListWidget->blockSignals(true);
    mListWidget->clear();

    // QGIS方式: 上から順に「奥行きの上から下へ」
    // = mLayers の末尾(最新追加 = 最前面)が、リストの先頭に来る
    const auto &layers = mCanvas->layers();
    for (int i = layers.size() - 1; i >= 0; --i)
    {
        RasterLayer *layer = layers[i];

        auto *item = new QListWidgetItem(layer->name(), mListWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(layer->isVisible() ? Qt::Checked : Qt::Unchecked);
    }

    mListWidget->blockSignals(false);
}

void LayerPanel::onItemChanged(QListWidgetItem *item)
{
    // リストの row → mLayers のインデックス(逆順)
    const int row = mListWidget->row(item);
    const auto &layers = mCanvas->layers();
    const int layerIndex = layers.size() - 1 - row;

    if (layerIndex < 0 || layerIndex >= layers.size())
        return;

    RasterLayer *layer = layers[layerIndex];
    layer->setVisible(item->checkState() == Qt::Checked);
}
