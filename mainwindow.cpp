#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_traficLight = new TrafficLight(this);

    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(onStartButtonClicked(bool)));
    connect(ui->stopButton, SIGNAL(clicked(bool)), this, SLOT(onStopButtonClicked(bool)));

    connect(m_traficLight, SIGNAL(sigRed()), this, SLOT(onRed()));
    connect(m_traficLight, SIGNAL(sigYellow()), this, SLOT(onYellow()));
    connect(m_traficLight, SIGNAL(sigGreen()), this, SLOT(onGreen()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStartButtonClicked(bool)
{
    m_traficLight->start();
}

void MainWindow::onStopButtonClicked(bool)
{
    m_traficLight->stop();
}

void MainWindow::onRed()
{
    ui->redButton->setChecked(true);
}

void MainWindow::onYellow()
{
    ui->yellowButton->setChecked(true);
}

void MainWindow::onGreen()
{
    ui->greenButton->setChecked(true);
}
