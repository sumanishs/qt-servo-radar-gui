#ifndef SERVOSLIDER_H
#define SERVOSLIDER_H

#include <iostream>

#include <QGridLayout>
#include <QSlider>
#include <QLabel>
#include <QChar>
#include <QPushButton>

#include "centralwidget.h"

class AutoRadar;
class ServoSlider:public QWidget {
       Q_OBJECT
private:
    QGridLayout* a_grid;
    QSlider*    a_slider;
    QLabel*     a_txt;
    QLabel*     a_val;
    QPushButton* a_start;
    QPushButton* a_stop;
    QPushButton* a_reset;

    CentralWidget*    a_central;
    bool setting_angle;

public:
    explicit ServoSlider(QWidget* a_Parent = nullptr);
    ~ServoSlider();
    void setCentralWidget(CentralWidget* a_cnt);
    void setAngleStr(int i);
    int getCurrentAngle();
    void setAngle(int i);

    QPushButton* getStartButton() { return a_start; }
    QPushButton* getStopButton() { return a_stop; }
    QPushButton* getResetButton() { return a_reset; }



private slots:
    void moveRadar(int i = 0);
    void resetAll(bool i);
};

#endif // SERVOSLIDER_H
