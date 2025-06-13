#ifndef DESTRUCTOR_H
#define DESTRUCTOR_H

#include <iostream>
#include "armas.h"
#include "nave.h"
#include "fecha.h"

using namespace std;

class Destructor: public Nave
{
    public:
        Destructor(string, string, string , string , unsigned short , unsigned short, Fecha, Armas);
        ~Destructor();
        void mostrar();
        void modificar();
        string display();
        int potencia_destructiva();

    private:
        Armas armas;
};

#endif // DESTRUCTOR_H
