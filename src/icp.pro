QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = icp
TEMPLATE = app

SOURCES += main.cpp\
        functions/initialize_function_library.cpp \
        functions/move_functions_library.cpp \
    functions/simulate.cpp \
    methods/initialize_library.cpp \
        methods/method.cpp \
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
        model/vehicle.cpp \
        model/vehicles.cpp \
        model/streets.cpp \
        model/lines.cpp \



HEADERS  += \
    functions/initialize_function_library.hpp \
    functions/move_functions_library.hpp \
    functions/simulate.hpp \
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
    model/vehicle.hpp \
    model/vehicles.hpp \
    model/streets.hpp \
    model/lines.hpp \


FORMS    += \
    ui/mainwindow.ui
