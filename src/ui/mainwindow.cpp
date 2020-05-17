/**
 * @file mainwindow.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Implemenetace metod hlavního okna aplikace spojující zobrazení a simulaci
 */

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtDebug>
#include <QFileInfo>
#include <QDir>
#include "../parser/parsestreets.hpp"
#include "../parser/parseroutes.hpp"
#include "../parser/parselines.hpp"
#include "../parser/parsetimetables.hpp"
#include "../functions/simulation.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mapScene = nullptr;
    selectedBus = -1;
    inRerouteMode = false;
    lastOpenedPath = "./examples";

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(closeApp()));
    connect(ui->actionOpenSim, SIGNAL(triggered()), this, SLOT(selectSimulationFolder()));
    connect(ui->actionReload, SIGNAL(triggered()), this, SLOT(loadSimulationData()));

    connect(ui->buttonCancel, SIGNAL(pressed()), this, SLOT(cancelRerouteMode()));
    connect(ui->buttonReroute, SIGNAL(pressed()), this, SLOT(startRerouteMode()));

    connect(ui->timer, SIGNAL(tick(int)), this, SLOT(simulationStep(int)));
    connect(ui->timer, SIGNAL(reset(QTime)), this, SLOT(simulationReset(QTime)));

    loadSimulationData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeApp()
{
    QCoreApplication::quit();
}

// Načítání dat ze složky simulace ============================================

void MainWindow::selectSimulationFolder()
{
    auto baseDirPath = QFileDialog::getExistingDirectory(this, "Vybrat složku simulace...");
    if(baseDirPath.isEmpty()) return;
    lastOpenedPath = baseDirPath;

    loadSimulationData();
}

void MainWindow::loadSimulationData()
{
    ui->actionReload->setEnabled(true);
    QDir baseDir(lastOpenedPath);

    // Zíksat cesty
    ParseStreets parseStreets;
    if(!parseStreets.openFile(baseDir.filePath("streets.csv"))){
        qDebug() << "Cannot open file streets.csv";
        return;
    }
    auto streets = parseStreets.getStreets();

    // Získat cesty linek
    ParseRoutes parseRoutes;
    if(!parseRoutes.openFile(baseDir.filePath("routes.csv"))){
        qDebug() << "Cannot open file routes.csv";
        return;
    }
    auto routes = parseRoutes.getRoutes(streets);

    // Získat jizdní řády
    ParseTimetables parseTimetables;
    if(!parseTimetables.openFile(baseDir.filePath("timetable.csv"))){
        qDebug() << "Cannot open file timetable.csv";
        return;
    }
    auto timetables = parseTimetables.getTimetables(routes);

    // Získat linky
    ParseLines parseLines;
    if(!parseLines.openFile(baseDir.filePath("lines.csv"))){
        qDebug() << "Cannot open file lines.csv";
        return;
    }
    auto lines = parseLines.getLines(routes, timetables);

    for(const auto l: lines){
        qDebug() << l.getID() << " " << l.getDisplayNumber() << " " << l.getDestination() << " " << l.getRoute();
    }

    ui->timer->reset();
    selectStreet(nullptr);

    if(mapScene != nullptr){
        disconnect(mapScene, &Map::streetSelected, this, &MainWindow::selectStreet);
        disconnect(mapScene, &Map::busSelected, this, &MainWindow::selectBus);
        disconnect(ui->streetTraffic, SIGNAL(valueChanged(int)), mapScene, SLOT(changeStreetTraffic(int)));
        delete mapScene;
    }

    mapScene = new Map(streets);
    ui->mapView->setScene(mapScene);

    connect(mapScene, &Map::streetSelected, this, &MainWindow::selectStreet);
    connect(mapScene, &Map::busSelected, this, &MainWindow::selectBus);
    connect(mapScene, &Map::streetListChanged, this, &MainWindow::rerouteSelectionChanged);
    connect(ui->streetTraffic, SIGNAL(valueChanged(int)), mapScene, SLOT(changeStreetTraffic(int)));
    simulation.Restart();
    simulation.InitializeSimulation(streets,lines);
    simulation.SetStepTime(10);
    ui->timer->reset();
}

// Práce s vybranou ulicí =====================================================

void MainWindow::startRerouteMode()
{
    if(mapScene == nullptr) return;

    if(inRerouteMode){
        confirmRerouteMode();
        return;
    }

    inRerouteMode = true;
    mapScene->setMultiStreetSelectMode(true);
    ui->buttonCancel->setEnabled(true);
    ui->buttonReroute->setEnabled(false);
    ui->buttonReroute->setText("Potvrdit objížďku");
}

void MainWindow::cancelRerouteMode()
{
    if(mapScene == nullptr) return;

    inRerouteMode = false;
    ui->buttonCancel->setEnabled(false);
    ui->buttonReroute->setEnabled(true);
    ui->buttonReroute->setText("Vytvořit objížďku");
    ui->rerouteDelay->setValue(5);
    mapScene->setMultiStreetSelectMode(false);
}

void MainWindow::confirmRerouteMode()
{
    if(mapScene == nullptr) return;

    auto ss = mapScene->getSelectedStreets();
    auto mainSt = mapScene->getSelectedStreet();
    simulation.CloseStreet(mainSt, ss, ui->rerouteDelay->value());
    mapScene->closeSelectedStreet();
    cancelRerouteMode();
}

void MainWindow::rerouteSelectionChanged()
{
    ui->buttonReroute->setEnabled(mapScene->getSelectedStreets().count() > 1);
}

void MainWindow::selectStreet(Street *street)
{
    cancelRerouteMode();
    if(street == nullptr){
        ui->streetParams->setEnabled(false);
        ui->streetName->setText("Nastavení průjezdnosti");
        ui->streetTraffic->setValue(0);
    }else{
        ui->streetParams->setEnabled(true);
        ui->streetName->setText(street->getName());
        ui->streetTraffic->setValue(street->getTraffic());
    }
}

// Zobrazení informace o vybreném busu ========================================

void MainWindow::selectBus(int busId)
{
    selectedBus = busId;

    if(selectedBus >= 0 && simulation.HasVehicleById(selectedBus)){
        auto veh = simulation.GetVehicleById(busId);
        for(auto street: veh.journey){
            mapScene->highlightStreet(street->getID());
        }
    }

    updateBus();
}

void MainWindow::updateBus()
{
    if(selectedBus < 0 || !simulation.HasVehicleById(selectedBus)){
        selectedBus = -1;
        ui->busRoute->removeBusData();
        return;
    }

    ui->busRoute->displayBusData(
        ui->timer->getTime(),
        simulation.GetVehicleById(selectedBus)
    );
}

// Ovládání simulace ==========================================================

void MainWindow::simulationStep(int seconds)
{
    if(mapScene == nullptr) return;

    qDebug() << "Simulation fired!" << seconds;

    simulation.Simulate(seconds);
    auto currMoveLog = simulation.move_log;
    qDebug() << currMoveLog;

    for(auto busId: currMoveLog.keys()){
        if(!prevMoveLog.contains(busId)){
            auto bus = simulation.GetVehicleById(busId);
            mapScene->addBus(busId, bus.getRawLine().getDisplayNumber());
        }

        mapScene->updateBus(busId, currMoveLog[busId]);
    }

    for(auto prevBusId: prevMoveLog.keys()){
        if(!currMoveLog.contains(prevBusId)){
            mapScene->removeBus(prevBusId);
        }
    }

    prevMoveLog = currMoveLog;
    if(selectedBus >= 0) updateBus();
}

void MainWindow::simulationReset(QTime time)
{
    qDebug() << "Simulation time set:" << time;
    simulation.SetTime(time.hour(), time.minute());
}
