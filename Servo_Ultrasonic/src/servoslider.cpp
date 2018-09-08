#include "servoslider.h"

ServoSlider::ServoSlider(QWidget *a_Parent):QWidget(a_Parent), setting_angle(false){
    const QChar degreeChar(0260);
    a_grid = new QGridLayout(this);
    a_slider = new QSlider(Qt::Horizontal, this);
    a_txt    = new QLabel("Angle:", this);
    a_val    = new QLabel("0 " + QString(degreeChar) , this);

    a_slider -> setMinimum(0);
    a_slider -> setMaximum(180);
    a_slider -> setTickInterval(1);
    a_slider -> setTickPosition(QSlider::TicksAbove);
    a_slider -> setValue(90);
    setAngleStr(90);

    a_txt -> setAlignment(Qt::AlignRight);
    a_val -> setAlignment(Qt::AlignLeft);

    const QSize btnSize = QSize(50, 30);
    a_start = new QPushButton("Start", this);
    a_start -> setFixedSize(btnSize);
    a_stop = new QPushButton("Stop", this);
    a_stop -> setFixedSize(btnSize);
    a_reset = new QPushButton("Reset", this);
    a_reset -> setFixedSize(btnSize);

    a_grid -> addWidget(a_txt, 0, 0, 1, 1);
    a_grid -> addWidget(a_val, 0, 1, 1, 1);
    a_grid -> addWidget(a_start, 0, 2, 1, 1);
    a_grid -> addWidget(a_stop, 0, 3, 1, 1);
    a_grid -> addWidget(a_reset, 0, 4, 1, 1);

    a_grid -> addWidget(a_slider, 1, 0, 1, 5);
    setLayout(a_grid);

    connect(a_slider, SIGNAL(valueChanged(int)), this, SLOT(moveRadar(int)));
    connect(a_reset, SIGNAL(clicked(bool)), this, SLOT(resetAll(bool)));

    std::cout << "Slider Widget --> Width:" << width() << ", Height:" << height() << std::endl;
}

ServoSlider::~ServoSlider(){
    delete a_val;
    delete a_txt;
    delete a_slider;
    delete a_grid;
}

void ServoSlider::setCentralWidget(CentralWidget *a_cnt){
    a_central = a_cnt;
}


void ServoSlider::setAngleStr(int i){
    const QChar degreeChar(0260);
    a_val -> setText(QString::number(i) + " " + degreeChar);
}


void ServoSlider::moveRadar(int i){
    if(!setting_angle){
    setAngleStr(i);
    a_central -> moveRadar(i);
    }
}

void ServoSlider::resetAll(bool i){
    a_central -> resetAll();
    a_slider -> setValue(90);
    setAngleStr(90);
    Q_UNUSED(i);
}

int ServoSlider::getCurrentAngle(){
    return a_slider -> value();
}

void ServoSlider::setAngle(int i){
    setting_angle = true;
    a_slider -> setValue(i);
    setAngleStr(i);
    setting_angle = false;
}
