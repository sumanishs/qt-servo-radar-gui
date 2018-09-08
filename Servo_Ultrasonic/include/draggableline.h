#ifndef DRAGGABLELINE_H
#define DRAGGABLELINE_H

#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QGraphicsSceneHoverEvent>
#include <QObject>
#include <QGraphicsLineItem>


class DraggableLine : public QGraphicsLineItem {
public:
    DraggableLine(QGraphicsItem* parent = 0);
    ~DraggableLine();
};


#endif // DRAGGABLELINE_H
