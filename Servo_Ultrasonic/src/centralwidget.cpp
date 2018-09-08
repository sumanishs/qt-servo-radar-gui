#include "centralwidget.h"
#include <QtMath>
#include <QCoreApplication>

CentralWidget::CentralWidget(QWidget *a_Parent) : QWidget(a_Parent)
{
    a_layout = new QGridLayout(this);
    setLayout(a_layout);
    a_view = new QGraphicsView(a_Parent);
    a_view->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    a_scene = new QGraphicsScene();
    a_view -> setScene(a_scene);
    a_layout -> addWidget(a_view);
    a_txt_x = nullptr;
    a_txt_y = nullptr;
    a_radar_line_left = nullptr;
    a_radar_line_mid  = nullptr;
    a_radar_line_right= nullptr;
    bigpie = nullptr;
    smallpie = nullptr;
}

CentralWidget::~CentralWidget(){
    delete a_scene;
    delete a_view;
    delete a_layout;
}

void CentralWidget::resizeEvent(QResizeEvent *event){
    initDrawArea();
    Q_UNUSED(event);
}

void CentralWidget::placeRadarArea(int ang){
    int sw = a_scene->width();
    int sh = a_scene->height();
    float x = 0.0, y = 0.0;
    ang=-ang;
    int ang_left = ang+15;
    int ang_right = ang-15;

    x = (float)(sh * qCos(ang * M_PI / 180.0)) + (float)sw/2;
    y = (float)(sh * qSin(ang * M_PI / 180.0)) + (float)0;
    a_radar_line_mid -> setLine(QLineF(sw/2, sh, sw/2+(sw/2-x),  y+sh));

    x = (float)(sh * qCos(ang_left * M_PI / 180.0)) + (float)sw/2;
    y = (float)(sh * qSin(ang_left * M_PI / 180.0)) + (float)0;
    a_radar_line_left -> setLine(QLineF(sw/2, sh, sw/2+(sw/2-x),  y+sh));

    x = (float)(sh * qCos(ang_right * M_PI / 180.0)) + (float)sw/2;
    y = (float)(sh * qSin(ang_right * M_PI / 180.0)) + (float)0;
    a_radar_line_right -> setLine(QLineF(sw/2, sh, sw/2+(sw/2-x),  y+sh));
}

void CentralWidget::moveRadar(int i){
    placeRadarArea(i);
    QCoreApplication::processEvents();
}

void CentralWidget::resetAll(){
    initDrawArea();
}

void CentralWidget::initDrawArea(){
    int pwidth = a_scene -> width();
    if(pwidth < a_view->width()){
        a_scene->clear();
        a_scene -> setSceneRect(0, 0, a_view->width()-5, a_view->height()-5);
        a_scene -> setBackgroundBrush(Qt::white);
        a_view -> setResizeAnchor(QGraphicsView::AnchorViewCenter);

        int sw = a_scene->width();
        int sh = a_scene->height();

        bigpie = new Pie(0 , 0, sh*2, sh*2);
        a_scene -> addItem(bigpie);
        bigpie->setPos(sw/2-sh, 0);

        smallpie = new Pie(0, 0, 40*2, 40*2);
        a_scene -> addItem(smallpie);
        smallpie->setPos(sw/2-40, sh-40);

        addDottedLines();

        QPen pen;
        pen.setColor(Qt::blue);
        pen.setWidth(3);

        a_radar_line_mid = new DraggableLine();
        a_radar_line_mid -> setPen(pen);
        a_scene -> addItem(a_radar_line_mid);

        a_radar_line_left = new DraggableLine();
        a_radar_line_left -> setPen(pen);
        a_scene -> addItem(a_radar_line_left);

        a_radar_line_right = new DraggableLine();
        a_radar_line_right -> setPen(pen);
        a_scene -> addItem(a_radar_line_right);

        placeRadarArea(90);

        std::cout << "ResizeEvent:Scene:==> Width:" << a_scene -> width() << ", Height:" << a_scene -> height() << std::endl;
        std::cout << "ResizeEvent:View:==> Width:" << a_view -> width() << ", Height:" << a_view -> height() << std::endl;
    }
}

void CentralWidget::addDottedLines(){
    DraggableLine* tmp = nullptr;
    int sw = a_scene->width();
    int sh = a_scene->height();
    float x = 0.0, y = 0.0;
    float ang = 0.0;
    QPen pen;
    pen.setColor(QColor(0, 127, 127, 255));
    pen.setWidth(2);
    pen.setStyle(Qt::DotLine);
    for(int i = 0; i <= 180; i+=30){
        ang=(float)-i;
        x = (float)(sh * qCos(ang * M_PI / 180.0)) + (float)sw/2;
        y = (float)(sh * qSin(ang * M_PI / 180.0)) + (float)0;
        tmp = new DraggableLine();
        tmp -> setPen(pen);
        a_scene -> addItem(tmp);
        tmp -> setLine(QLineF(sw/2, sh, sw/2+(sw/2-x),  y+sh));
    }
}
