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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(closeApp()));
    connect(ui->actionOpenSim, SIGNAL(triggered()), this, SLOT(selectSimulationFolder()));
    connect(ui->map, &Map::streetSelected, this, &MainWindow::selectStreet);
    connect(ui->streetFlow, SIGNAL(valueChanged(int)), ui->map, SLOT(changeStreetTraffic(int)));
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

    ui->map->setStreets(streets);
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
}

void MainWindow::closeApp()
{
    QCoreApplication::quit();
}
