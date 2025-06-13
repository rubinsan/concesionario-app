#ifndef CARGUERO_H
#define CARGUERO_H

#include <iostream>
#include "nave.h"

using namespace std;

class Carguero: public Nave
{
    public:
        Carguero(string, string, string , string , unsigned short , unsigned short, Fecha, unsigned short, unsigned short, bool);
        ~Carguero();
        void mostrar();
        void modificar();
        string display();        
        int potencia_destructiva();

    private:
        unsigned short capacidad;
        unsigned short velocidad;
        bool escudo;



};

#endif // CARGUERO_H
