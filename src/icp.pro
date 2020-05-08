QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = icp
TEMPLATE = app

SOURCES += main.cpp \
    functions/simulation.cpp \
    methods/initialize_library.cpp \
    methods/move_library.cpp \
    model/eventtable.cpp \
    model/line.cpp \
    parser/csvparser.cpp \
    model/street.cpp \
    model/timetable.cpp \
    parser/parselines.cpp \
    parser/parseroutes.cpp \
    parser/parsestreets.cpp \
    parser/parsetimetables.cpp \
    ui/mainwindow.cpp \
    ui/map.cpp \
    ui/mapbus.cpp \
    ui/mapstreet.cpp \
    model/vehicle.cpp \
    model/vehicles.cpp \
    model/streets.cpp \
    model/lines.cpp \
    ui/mapview.cpp


HEADERS += \
    functions/simulation.hpp \
    methods/initialize_library.hpp \
    methods/move_library.hpp \
    model/eventtable.hpp \
    model/line.hpp \
    parser/csvparser.hpp \
    model/street.hpp \
    model/timetable.hpp \
    parser/parselines.hpp \
    parser/parseroutes.hpp \
    parser/parsestreets.hpp \
    parser/parsetimetables.hpp \
    ui/mainwindow.hpp \
    ui/map.hpp \
    ui/mapbus.hpp \
    ui/mapstreet.hpp\
    model/vehicle.hpp \
    model/vehicles.hpp \
    model/streets.hpp \
    model/lines.hpp \
    ui/mapview.hpp


FORMS += \
    ui/mainwindow.ui
