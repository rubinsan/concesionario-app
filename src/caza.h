#ifndef CAZA_H
#define CAZA_H

#include <iostream>
#include "nave.h"
#include "armas.h"

using namespace std;

class Caza: public Nave{

    public:
        Caza(string, string, string , string , unsigned short , unsigned short, Fecha, unsigned short, Armas);
        ~Caza();
        void mostrar();
        void modificar();
        string display();
        int potencia_destructiva();

    private:
        unsigned short velocidad;
        Armas armas;

};

#endif // CAZA_H
