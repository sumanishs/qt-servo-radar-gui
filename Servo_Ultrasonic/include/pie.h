#ifndef PIE_H
#define PIE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QLinearGradient>
#include <QConicalGradient>
#include <QBrush>

class Pie : public QGraphicsItem{

private:
    int X, Y, W, H;
public:
    Pie(int x, int y, int w, int h);
    ~Pie();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // PIE_H
