#include "timer.hpp"
#include "ui_timer.h"

Timer::Timer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
    timeChanged = true;
    seconds = 60;
    time = QTime(15, 30, 0);
    stop();

    ui->simStep->setValue(seconds);
    ui->simTime->setTime(time);

    timer.setInterval(1000);
    timer.start();

    connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));
    connect(ui->simStep, SIGNAL(valueChanged(int)), this, SLOT(stepSizeSet(int)));
    connect(ui->simTime, SIGNAL(timeChanged(QTime)), this, SLOT(timeSet(QTime)));
    connect(ui->btnStart, SIGNAL(pressed()), this, SLOT(start()));
    connect(ui->btnPause, SIGNAL(pressed()), this, SLOT(stop()));
    connect(ui->btnStep, SIGNAL(pressed()), this, SLOT(singleStep()));
}

Timer::~Timer()
{
    delete ui;
}

void Timer::timeout()
{
    if(!enabled) return;

    singleStep();
}

void Timer::start()
{
    enabled = true;
    ui->btnStart->setEnabled(false);
    ui->btnStep->setEnabled(false);
    ui->btnPause->setEnabled(true);
    ui->simTime->setEnabled(false);
    ui->simStep->setEnabled(false);
}

void Timer::stop()
{
    enabled = false;
    ui->btnStart->setEnabled(true);
    ui->btnStep->setEnabled(true);
    ui->btnPause->setEnabled(false);
    ui->simTime->setEnabled(true);
    ui->simStep->setEnabled(true);
}

void Timer::singleStep()
{
    if(timeChanged){
        timeChanged = false;
        emit reset(time);
    }else{
        time = time.addSecs(seconds);
        ui->simTime->setTime(time);
        emit tick(seconds);
    }
}

void Timer::timeSet(QTime time)
{
    if(this->time == time) return;

    timeChanged = true;
    this->time = time;
}

void Timer::stepSizeSet(int step)
{
    seconds = step;
}
