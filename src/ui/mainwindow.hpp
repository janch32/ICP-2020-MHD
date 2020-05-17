/**
 * @file mainwindow.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Definice hlavního okna aplikace spojující zobrazení a simulaci
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../model/street.hpp"
#include "../functions/simulation.hpp"
#include <QMainWindow>
#include <QTime>
#include "map.hpp"

namespace Ui {
class MainWindow;
}

/**
 * @brief Hlavní UI třída reprezentující hlavní okno aplikace
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    /**
     * @brief Ukončit program
     */
    void closeApp();

    /**
     * @brief Zobrazit dialog s výberem nová složky s daty simulace
     *        A načíst danou simulace
     */
    void selectSimulationFolder();

    /**
     * @brief Zobrazit data o dopravě u ulice
     * @param street Ulice, o které se mají informace zobrazit
     */
    void selectStreet(Street *street);

    /**
     * @brief Nastala změna při výběru ulice, aktualizovat UI
     */
    void rerouteSelectionChanged();

    /**
     * @brief Zobrazit informace o spoji
     * @param busId ID spoje v simulaci
     */
    void selectBus(int busId);

    /**
     * @brief Aktualizovat informace o vybraném spoji
     */
    void updateBus();

    /**
     * @brief Provést krok simulace
     * @param seconds Délka kroku simulace v sec
     */
    void simulationStep(int seconds);

    /**
     * @brief Změnit čas simulace
     * @param time Nový čas simulace
     */
    void simulationReset(QTime time);

    /**
     * @brief Načíst data simulace z aktuálně vybrané složky
     */
    void loadSimulationData();

    /**
     * @brief Spustí tvorbu objížďky
     */
    void startRerouteMode();

    /**
     * @brief Zruší tvorbu objížďky
     */
    void cancelRerouteMode();

    /**
     * @brief Potvrdí tvorbu objíždky
     */
    void confirmRerouteMode();

private:
    /**
     * @brief UI prvky vygenrované QTCreator designerem
     */
    Ui::MainWindow *ui;

    /**
     * @brief Scéna pro zobrazení ulic a linek
     */
    Map *mapScene;

    /**
     * @brief Instance simulace pohybu linek
     */
    Simulation simulation;

    /**
     * @brief ID vybraného spoje
     *
     * < 0, pokud není vybrán žádný spoj
     */
    int selectedBus;

    /**
     * @brief Je aktivní režim změny cesty vozidla
     */
    bool inRerouteMode;

    /**
     * @brief Předchozí seznam spojů simulace
     */
    QHash<int, QPoint> prevMoveLog;

    /**
     * @brief Vybraná složka informací o simulaci
     */
    QString lastOpenedPath;
};

#endif // MAINWINDOW_H
