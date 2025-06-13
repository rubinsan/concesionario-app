#ifndef VENTAS_H
#define VENTAS_H

#include <iostream>
#include <vector>
#include "nave.h"
#include "fecha.h"
#include "propietario.h"
using namespace std;

class Ventas
{
    public:
        Ventas(Fecha, string, string);
        Ventas();
        Fecha obtenerFecha();
        string obtenerComprador();
        void mostrar();
        string display();
        int calculo ();


    private:
        Fecha fecha;
        string comprador;
        string producto;

};

#endif // VENTAS_H
