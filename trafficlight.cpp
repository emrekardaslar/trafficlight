#include "trafficlight.h"
#include <QDebug>
#include <QTimer>

TrafficLight::TrafficLight(QObject *parent):
    QObject(parent)
{
    m_machine = new QStateMachine(this);

    m_redState = new QState();
    m_yellowState = new QState();
    m_greenState = new QState();

    m_machine->addState(m_redState);
    m_machine->addState(m_yellowState);
    m_machine->addState(m_greenState);

    m_machine->setInitialState(m_redState);

    m_redState->addTransition(this, SIGNAL(sigSwitch()), m_yellowState);
    m_yellowState->addTransition(this, SIGNAL(sigSwitch()), m_greenState);
    m_greenState->addTransition(this, SIGNAL(sigSwitch()), m_redState);

    connect(m_redState, SIGNAL(entered()), this, SLOT(onRedStateEntered()));
    connect(m_redState, SIGNAL(exited()), this, SLOT(onRedStateExited()));
    connect(m_yellowState, SIGNAL(entered()), this, SLOT(onYellowStateEntered()));
    connect(m_yellowState, SIGNAL(exited()), this, SLOT(onYellowStateExited()));
    connect(m_greenState, SIGNAL(entered()), this, SLOT(onGreenStateEntered()));
    connect(m_greenState, SIGNAL(exited()), this, SLOT(onGreenStateExited()));

}

void TrafficLight::start()
{
    if (!m_machine->isRunning())
        m_machine->start();
}

void TrafficLight::stop()
{
    if (m_machine->isRunning())
        m_machine->stop();
}

void TrafficLight::onRedStateEntered()
{
    qDebug() << "RED state entered";
    emit sigRed();

    QTimer::singleShot(10*1000, this, SLOT(onTransitionTimeout()));
}

void TrafficLight::onRedStateExited()
{
     qDebug() << "RED state exited";
}

void TrafficLight::onYellowStateEntered()
{
     qDebug() << "YELLOW state entered";

     emit sigYellow();

     QTimer::singleShot(2*1000, this, SLOT(onTransitionTimeout()));
}

void TrafficLight::onYellowStateExited()
{
    qDebug() << "YELLOW state exited";
}

void TrafficLight::onGreenStateEntered()
{
    qDebug() << "GREEN state entered";

    emit sigGreen();
    QTimer::singleShot(8*1000, this, SLOT(onTransitionTimeout()));
}

void TrafficLight::onGreenStateExited()
{
    qDebug() << "GREEN state exited";
}

void TrafficLight::onTransitionTimeout()
{
    emit sigSwitch();
}


