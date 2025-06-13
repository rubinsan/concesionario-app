#ifndef ESTACION_H
#define ESTACION_H

#include <iostream>
#include "nave.h"

using namespace std;


class Estacion: public Nave{

    public:
        Estacion(string, string, string , string , unsigned short , unsigned short, Fecha, unsigned int, unsigned short, bool);
        ~Estacion();
        void mostrar();
        void modificar();
        string display();
        int potencia_destructiva();

    private:
        unsigned int pasajeros;
        unsigned short hangares;
        bool escudo;


};

#endif // ESTACION_H
