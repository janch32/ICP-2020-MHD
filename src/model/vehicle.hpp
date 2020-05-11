#ifndef VEHICLE
#define VEHICLE

#include <QString>
#include <QPoint>
#include <QList>
#include <QTime>

#include "line.hpp"
#include "street.hpp"

using namespace std;

class Vehicle {
    private:
         /**
         * @brief id číslo vozidla
         */
        int number;
        /**
         * @brief číslo linky busu
         */
        QString line_no;
        /**
         * @brief aktuální pozice na mapě
         */
        QPoint map_position;
        /**
         * @brief id příští zastávky
         */
        QString next_stop;
        /**
         * @brief id ulice na které bus aktuálně je
         */
        QString on_street;
        /**
         * @brief počet kroků do další zastávky
         */
        int steps;
        /**
         * @brief aktuální délka kroku
         */
        float step;
        /**
         * @brief aktuální směr, kterým míří vozidlo, pozice dalšího rohu
         */
        QPoint direction;
        /**
         * @brief objekt třídy Line, který odpovídá lince vozidla
         */
        Line rawLine;
        /**
         * @brief vypočítá směr v závislosti na poslední projeté a aktuální ulici
         * @param last poslední projetá ulice
         * @param curr aktuální ulice
         * @return pozice
         */
        QPoint GiveDirection(Street last, Street curr);

    public:

        /**
         * @brief Vrátí id číslo vozidla
         * @return číslo
         */
        int GetIdNumber();
        /**
         * @brief Nastaví aktuální pozici vozidla
         * @param position pozice, bod
         */
        void SetPosition(QPoint position);
        /**
         * @brief Vrátí aktuání pozici vozidla
         * @return pozice, bod
         */
        QPoint GetPosition();
        /**
         * @brief Vrátí id linky busu
         * @return id, string
         */
        QString GetLine();
        /**
         * @brief Započne jízdu busu, nastaví aktuální ulici, příští zastávku a směr
         * @param time Aktuální čas
         */
        void CommenceRide(QTime time);
        /**
         * @brief Zatočí na další ulici ze seznamu, aktualizuje aktuální ulici a příští ulici, přepočítá směr, zvýší počítadlo projetých ulic
         */
        void TurnOnStreet();
        /**
         * @brief Autobus dojede na zastávku, nastaví další zastávku, pokud nesouhlasí id aktuální zastávky s id aktuální ulice, nastaví aktuální ulici,
         * @param time aktuální čas
         */
        void ArriveOnStop(QTime time);
        /**
         * @brief Vrátí id aktuální ulice/zastávky
         * @return id, string
         */
        QString TellStop();
        /**
         * @brief Vrátí id další zastávky
         * @return id, string
         */
        QString TellNextStop();
        /**
         * @brief Nastaví krok pohybu
         * @param step krok, float
         */
        void SetStep(float step);
        /**
         * @brief Vrátí aktuální krok simulace
         * @return krok, float
         */
        float GetStep();
        /**
         * @brief Nastaví počet kroků k další zastávce
         * @param steps kroky, int
         */
        void SetSteps(int steps);
        /**
         * @brief Vrátí počet kroků k další zastávce
         * @return kroky, int
         */
        int GetSteps();
        /**
         * @brief Sníží počet kroků k další zastávce
         */
        void DecrementSteps();
        /**
         * @brief Provede krok pohybu
         */
        void Step();
        /**
         * @brief Vrátí aktuální směr busu
         * @return směr, bod
         */
        QPoint GetDirection();
        /**
         * @brief hodnota signalizující, zda bus již zareagoval na stíženou dopravu v ulici
         */
        int slowed;
        /**
         * @brief Nastaví hodnotu "slowed" na danou hodnotu
         * @param i hodnota, int
         */
        void FlipSlow(int i);


        /**
         * @brief seznam ulic, které vozidlo má projet
         */
        LineRoute journey;
        /**
         * @brief jízdní řad vozidla
         */
        TimetableEntry timetable;
        /**
         * @brief počítadlo projetých ulic
         */
        int journey_no = 0;
        /**
         * @brief délka aktuální cesty k další zastávce
         */
        float curr_journey_lenght;
        /**
         * @brief Vrátí objekt linky náležící k vozidlu
         * @return linka, objekt
         */
        Line getRawLine() const;
        /**
         * @brief nastaví linku áležící k vozidlu
         * @param value linka vozidla
         */
        void setRawLine(const Line &value);

        Vehicle();
        Vehicle(QString l, int n, QPoint position, LineRoute route, TimetableEntry timetable, Line line);
        ~Vehicle();
};

#endif

