#include "csvparser.hpp"
#include <QtDebug>
#include <QException>

CsvParser::~CsvParser()
{
    file.close();
}

bool CsvParser::openFile(QString fileName)
{
    file.setFileName(fileName);

    return file.open(QIODevice::ReadOnly);
}

QStringList CsvParser::getLine()
{
    QStringList list;
    if(endOfFile()) return list;

    QByteArray line = file.readLine();
    return QString::fromUtf8(line).split(',');
}

bool CsvParser::endOfFile()
{
    return file.atEnd();
}
