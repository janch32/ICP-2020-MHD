#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP

#include <QStringList>
#include <QFile>

class CsvParser
{
private:
    QFile file;
protected:
    QStringList getLine();
    bool endOfFile();
public:
    ~CsvParser();
    bool openFile(QString fileName);
};

#endif // CSVPARSER_HPP
