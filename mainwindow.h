#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trafficlight.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TrafficLight* m_traficLight;
private slots:
    void onStartButtonClicked(bool);
    void onStopButtonClicked(bool);
    void onRed();
    void onYellow();
    void onGreen();
};

#endif // MAINWINDOW_H
