#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <iostream>
#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsTextItem>
#include <QMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>

#include "global.h"
#include "draggableline.h"
#include "pie.h"

class CentralWidget : public QWidget
{
    Q_OBJECT
private:
    QGridLayout*    a_layout;
    QGraphicsView*  a_view;
    QGraphicsScene* a_scene;
    QGraphicsTextItem* a_txt_x;
    QGraphicsTextItem* a_txt_y;
    DraggableLine*     a_radar_line_mid;
    DraggableLine*     a_radar_line_left;
    DraggableLine*     a_radar_line_right;
    Pie*               bigpie;
    Pie*               smallpie;



public:
    explicit CentralWidget(QWidget *parent = nullptr);
    ~CentralWidget();
    void initDrawArea();
    void addDottedLines();
    void moveRadar(int i);
    void placeRadarArea(int ang);
    void resetAll();

protected:
    void resizeEvent(QResizeEvent* event);

signals:

public slots:
};

#endif // CENTRALWIDGET_H
