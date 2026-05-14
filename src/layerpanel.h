#ifndef HOBO_GIS_LAYERPANEL_H
#define HOBO_GIS_LAYERPANEL_H

#include <QDockWidget>

class QListWidget;
class QListWidgetItem;
class MapCanvas;

class LayerPanel : public QDockWidget
{
    Q_OBJECT

public:
    explicit LayerPanel(MapCanvas *canvas, QWidget *parent = nullptr);
    ~LayerPanel() override;

private slots:
    void refresh();
    void onItemChanged(QListWidgetItem *item);

private:
    MapCanvas *mCanvas;
    QListWidget *mListWidget;
};

#endif // HOBO_GIS_LAYERPANEL_H
