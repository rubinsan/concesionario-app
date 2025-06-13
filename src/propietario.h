#ifndef PROPIETARIO
#define PROPIETARIO
#include <iostream>
#include <cstring>
#include <vector>
#include "validaidhumano.h"
#include "validaidextra.h"

using namespace std;

class Propietario {

    public:

        Propietario(string,string);
        string obtenertipo();
        virtual ~Propietario();
        virtual void mostrar();
        virtual void modificar();
        virtual string obtenerid();
        virtual string display();    

    protected:
        string origen;
        string tipo;
};


#endif // PROPIETARIO
