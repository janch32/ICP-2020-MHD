#ifndef LINES
#define LINES

#include <QMap>
#include <QString>
#include <QList>

#include "line.hpp"

using namespace std;

class Lines {
    private:
        QMap<QString, Line> lines;
    public:
        Lines();
        ~Lines();
        void AddLine(Line line);
        int RemoveLine(QString id);
        Line GetLine(QString id);
        QList<Line> GetAllLines();
        int GetLenght();

};

#endif
