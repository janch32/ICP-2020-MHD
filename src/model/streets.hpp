#ifndef STREETS
#define STREETS

#include <QMap>
#include <QString>
#include <QList>

#include "street.hpp"

using namespace std;

class Streets {
    private:
        QMap<QString, Street*> streets;
    public:
        Streets();
        ~Streets();
        void AddStreet(Street *street);
        int RemoveStreet(QString id);
        Street GetStreet(QString id);
        QList<Street> GetAllStreets();
        int GetLenght();

};

#endif
