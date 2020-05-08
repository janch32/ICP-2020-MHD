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

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(closeApp()));
    connect(ui->actionOpenSim, SIGNAL(triggered()), this, SLOT(selectSimulationFolder()));

    connect(ui->timer, SIGNAL(tick(int)), this, SLOT(simulationStep(int)));
    connect(ui->timer, SIGNAL(reset(QTime)), this, SLOT(simulationReset(QTime)));

    selectSimulationFolder();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectSimulationFolder()
{
    //auto baseDirPath = QFileDialog::getExistingDirectory(this, "Vybrat složku simulace...");
    //if(baseDirPath.isEmpty()) return;
    QString baseDirPath = "../examples";

    qDebug() << baseDirPath;
    QDir baseDir(baseDirPath);

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

    /**
      * Toto je pro debugovaci ucely, pak si to udelej jinak

    Simulation simulation;
    simulation.InitializeSimulation(streets,lines, 15, 30);
    simulation.Simulate(3000);
*/

    mapScene = new Map(streets);
    ui->mapView->setScene(mapScene);

    connect(mapScene, &Map::streetSelected, this, &MainWindow::selectStreet);
    connect(ui->streetFlow, SIGNAL(valueChanged(int)), mapScene, SLOT(changeStreetTraffic(int)));

    // Ukázka přidání busu
    mapScene->addBus(1, "42");
}

void MainWindow::selectStreet(Street *street)
{
    if(street == nullptr){
        ui->streetParams->setEnabled(false);
        ui->streetName->setText("Nastavení průjezdnosti");
        ui->streetFlow->setValue(100);
    }else{
        ui->streetParams->setEnabled(true);
        ui->streetName->setText(street->getName());
        ui->streetFlow->setValue(street->getTrafficFlow()*100);
    }

    // Ukázka busu, kdžy se vybere ulice, změní pozici, jinka je odstraněn
    if(street == nullptr){
        mapScene->removeBus(1);
    }else{
        mapScene->updateBus(1, QPoint(10, 10));
    }
}

void MainWindow::simulationStep(int seconds)
{
    qDebug() << "Simulation fired!" << seconds;
}

void MainWindow::simulationReset(QTime time)
{
    qDebug() << "Simulation time set:" << time;
}

void MainWindow::closeApp()
{
    QCoreApplication::quit();
}
