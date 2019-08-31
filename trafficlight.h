#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H
#include <QStateMachine>
#include <QState>

class TrafficLight : public QObject
{
    Q_OBJECT
public:
    TrafficLight(QObject *parent = nullptr);
    void start();
    void stop();
private:
    QStateMachine* m_machine;
    QState* m_redState;
    QState* m_yellowState;
    QState* m_greenState;
signals:
    void sigSwitch();
    void sigRed();
    void sigYellow();
    void sigGreen();
private slots:
    void onRedStateEntered();
    void onRedStateExited();
    void onYellowStateEntered();
    void onYellowStateExited();
    void onGreenStateEntered();
    void onGreenStateExited();

    void onTransitionTimeout();

};

#endif // TRAFFICLIGHT_H
