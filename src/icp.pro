QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = icp
TEMPLATE = app

SOURCES += main.cpp\
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
        ui/mapstreet.cpp

HEADERS  += \
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
    ui/mapstreet.hpp

FORMS    += \
    ui/mainwindow.ui
