/**
 * @file timer.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * Definice UI prvku pro ovládání simulace
 */

#ifndef TIMER_HPP
#define TIMER_HPP

#include <QWidget>
#include <QTimer>
#include <QTime>

namespace Ui {
class Timer;
}

/**
 * @brief UI třída obsluhující čas a kroky simulace
 */
class Timer : public QWidget
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

    /**
     * @brief Získat aktuální čas simulace
     * @return Aktuální čas simulace
     */
    QTime getTime() const;

public slots:
    /**
     * @brief Vyvolá tik vnitřních hodin (QTimer)
     */
    void timeout();

    /**
     * @brief Spuštění automatického krokování
     */
    void start();

    /**
     * @brief Pozastavení automatického krokování
     */
    void stop();

    /**
     * @brief Provést jeden krok simulace
     */
    void singleStep();

    /**
     * @brief Nastavit čas
     * @param time Čas, na který se simulace nastaví
     */
    void timeSet(QTime time);

    /**
     * @brief Změnit velikost jednoho kroku v simulace
     * @param step Krok simulace (v sekundách)
     */
    void stepSizeSet(int step);

    /**
     * @brief Resetovat časovač, velikost kroku a čas
     */
    void reset();

signals:
    /**
     * @brief tick Má se provést jeden krok simulace
     * @param seconds Délka jednoho kroku simulace
     */
    void tick(int seconds);

    /**
     * @brief reset Změnil se čas simulace
     * @param time Nový čas simulace
     */
    void reset(QTime time);

private:
    /**
     * @brief UI prvky vygenrované QTCreator designerem
     */
    Ui::Timer *ui;

    /**
     * @brief Timer osbsluhující automatické krokování (tiká každou sec)
     */
    QTimer timer;

    /**
     * @brief Aktuální čas simulace
     */
    QTime time;

    /**
     * @brief Je automatické krokování spuštěno
     */
    bool enabled;

    /**
     * @brief Nastala změna času simulace
     */
    bool timeChanged;

    /**
     * @brief Velikost kroku simulace
     */
    int seconds;
};

#endif // TIMER_HPP
