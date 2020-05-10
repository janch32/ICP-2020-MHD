#ifndef TIMER_HPP
#define TIMER_HPP

#include <QWidget>
#include <QTimer>
#include <QTime>

namespace Ui {
class Timer;
}

class Timer : public QWidget
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

public slots:
    void timeout();
    void start();
    void stop();
    void singleStep();
    void timeSet(QTime time);
    void stepSizeSet(int step);
    void reset();

signals:
    void tick(int seconds);
    void reset(QTime time);

private:
    Ui::Timer *ui;
    QTimer timer;
    QTime time;
    bool enabled;
    bool timeChanged;
    int seconds;
};

#endif // TIMER_HPP
