#include "pie.h"

Pie::Pie(int x, int y, int w, int h):X(x), Y(y), W(w), H(h), QGraphicsItem(){

}

Pie::~Pie(){

}

QRectF Pie::boundingRect() const {
    return (QRectF(X, Y, W, H));
}

void Pie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //QRectF rectangle(100.0, 200.0, 80.0, 60.0);
    QRectF rectangle(X, Y, W, H);

    QConicalGradient conGrad( QPointF(100, 100), 40.0 );
    conGrad.setColorAt( 0, Qt::black );
    conGrad.setColorAt( 1, Qt::white );


    QBrush pen_brush(QColor(127, 127, 127, 127));
    QBrush brush(conGrad);
    QPen pen;
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(5);
    pen.setBrush(pen_brush);
    painter -> setPen(pen);
    painter -> setBrush(brush);
    painter->setBackgroundMode(Qt::OpaqueMode);
    painter -> setRenderHint(QPainter::Antialiasing);


    int startAngle = 0 * 16;
    int spanAngle = 180 * 16;
    //painter->drawRect(rectangle);
    painter->drawPie(rectangle, startAngle, spanAngle);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
