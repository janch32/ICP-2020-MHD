#ifndef STREET_HPP
#define STREET_HPP

#include <QString>
#include <QHash>
#include <QPoint>

class Street
{
private:
    QString id;
    QString name;
    QPoint begin;
    QPoint end;
    float stopPos;
    int traffic;

public:
    Street();
    Street(QString id);
    Street(QString id, QString name, QPoint beginPos, QPoint endPos, float stopPos);

    bool operator==(const Street& rhs) const;
    bool operator==(const QString& rhs) const;

    QString getID() const;

    QString getName() const;
    void setName(const QString &value);

    QPoint getBegin() const;
    void setBegin(const QPoint &value);

    QPoint getEnd() const;
    void setEnd(const QPoint &value);

    float getStopPos() const;
    void setStopPos(float value);

    int getTrafficFlow() const;
    void setTrafficFlow(int value);
};

class StreetList : public QHash<QString, Street*>{

};

#endif // STREET_HPP
