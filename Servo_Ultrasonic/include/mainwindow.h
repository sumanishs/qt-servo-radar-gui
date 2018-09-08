#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QApplication>
#include <QDesktopWidget>

#include "global.h"
#include "centralwidget.h"
#include "servoslider.h"
#include "autoradar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
       QDockWidget* a_bottom;
       QDockWidget* a_central;
       CentralWidget* a_centralWidget;
       ServoSlider*   a_bottomWidget;
       AutoRadar*     a_autoradar;

public:
    MainWindow(QWidget *a_Parent = nullptr);
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent* event);
    void closeEvent(QCloseEvent* event);
};

#endif // MAINWINDOW_H
