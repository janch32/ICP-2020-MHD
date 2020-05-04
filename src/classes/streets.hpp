#ifndef STREETS
#define STREETS

#include <map>
#include <string>
#include <list>

#include "street.hpp"

using namespace std;

class Streets {
    private:
        map<string, Street> streets;
        int lenght;
    public:
        Streets();
        ~Streets();
        void AddStreet(Street street);
        int RemoveStreet(string id);
        Street GetStreet(string id);
        list<Street> GetAllStreets();
        int GetLenght();

};

#endif
