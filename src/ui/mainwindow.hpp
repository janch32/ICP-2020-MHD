#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../model/street.hpp"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void closeApp();
    void selectSimulationFolder();
    void selectStreet(Street *street);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
