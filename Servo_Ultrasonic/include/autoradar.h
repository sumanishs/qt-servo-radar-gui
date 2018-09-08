#ifndef AUTORADAR
#define AUTORADAR

#include "centralwidget.h"
#include "servoslider.h"

#include <QThread>

class AutoRadar:public QObject {
    Q_OBJECT

private:
    CentralWidget*  m_central;
    ServoSlider*    m_servo;

    bool m_start;
    bool m_stop;

public:
        AutoRadar();
        ~AutoRadar();

        void setCentralWidget(CentralWidget* a_central);
        void setServoSliderWidget(ServoSlider* a_servo);

private:
        void scan();

public slots:
        void start_rad();
        void stop_rad();
};

#endif // AUTORADAR

