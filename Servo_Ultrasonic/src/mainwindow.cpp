#include "mainwindow.h"

MainWindow::MainWindow(QWidget *a_Parent)
    : QMainWindow(a_Parent)
{

    setWindowTitle("Servo-Ultrasonic Radar Control !!");
    a_bottom = new QDockWidget("Servo Controller", this);
    a_central = new QDockWidget("Radar", this);

    a_centralWidget = new CentralWidget(this);
    a_bottomWidget  = new ServoSlider(this);
    a_bottomWidget -> setCentralWidget(a_centralWidget);

    a_bottom -> setWidget(a_bottomWidget);
    a_central -> setWidget(a_centralWidget);

    addDockWidget(Qt::BottomDockWidgetArea, a_bottom);
    setCentralWidget(a_central);
    setWindowState(Qt::WindowMaximized);
    a_autoradar = new AutoRadar();
    a_autoradar -> setCentralWidget(a_centralWidget);
    a_autoradar -> setServoSliderWidget(a_bottomWidget);

    QPushButton* a_start = a_bottomWidget -> getStartButton();
    QPushButton* a_stop = a_bottomWidget -> getStopButton();
    connect(a_start, SIGNAL(clicked(bool)), a_autoradar, SLOT(start_rad()));
    connect(a_stop, SIGNAL(clicked(bool)), a_autoradar, SLOT(stop_rad()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::resizeEvent(QResizeEvent *event){
//    std::cout << "MainWindow resize event..." << std::endl;
//    std::cout << "Width:" << width() << ", Height:" << height() << std::endl;
//    QRect rec = QApplication::desktop()->screenGeometry();
//    int height = rec.height();
//    int width = rec.width();
//    std::cout << "Screen:width:" << width << ", height:" << height << std::endl;
//    if(this->width() == width && !reset_done) {
//        std::cout << "Setting maximized...." << std::endl;
//        maximized = true;
//    }
    Q_UNUSED(event);
}

void MainWindow::closeEvent(QCloseEvent* event){
    a_autoradar -> stop_rad();
    Q_UNUSED(event);
}

