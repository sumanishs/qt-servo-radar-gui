#include "autoradar.h"
#include "stdlib.h"
#include <QCoreApplication>


AutoRadar::AutoRadar(): m_start(false), m_stop(false){
    //Constructor
}

AutoRadar::~AutoRadar(){
    //Destructor
}


void AutoRadar::setCentralWidget(CentralWidget* a_central ){
    m_central = a_central;
}

void AutoRadar::setServoSliderWidget(ServoSlider *a_servo){
    m_servo = a_servo;
}

void AutoRadar::start_rad() {
    m_start=true;
    m_stop = false;
    this -> scan();
}

void AutoRadar::stop_rad() {
    m_stop=true;
    m_start = false;
}

void AutoRadar::scan() {
    int curr_ang = m_servo -> getCurrentAngle();
    bool inc = false;
    bool dec = false;
    while (m_start) {
       if (m_stop) {
            m_start = false;
            break;
        }
        if(!inc && !dec){
            dec = true;
        }
        if(dec){
            curr_ang--;
            if(curr_ang < 0){
                dec = false;
                inc = true;
            }
            else{
                m_servo -> setAngle(curr_ang);
                m_central -> moveRadar(curr_ang);
            }
        }
        if(inc){
            curr_ang++;
            if(curr_ang > 180){
                inc = false;
                dec = true;
            }
            else{
                m_servo -> setAngle(curr_ang);
                m_central -> moveRadar(curr_ang);
            }
        }
        QCoreApplication::processEvents();
        QThread::msleep(10);
    }
}


