#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <fstream>
#include "nave.h"
#include "estacion.h"
#include "carguero.h"
#include "destructor.h"
#include "caza.h"
#include "armas.h"
#include "fecha.h"
#include "propietario.h"
#include "humano.h"
#include "extraterrestre.h"
#include "ventas.h"
#include "validarnum.h"
#include "validaidnave.h"
#include "validaidhumano.h"
#include "validaidextra.h"
#include "permitirventa.h"
#include "cargarnaves.h"
#include "cargarpropietarios.h"
#include "cargarventas.h"
#include "introducirfecha.h"
#include "altanaves.h"
#include "altapropietarios.h"
#include "mostrarnaves.h"
#include "mostrarpropietarios.h"


using namespace std;

class Sistema{

    public:
        Sistema(Fecha);
        ~Sistema();
        void bienvenida();
        void menu();

    private:
        Fecha f;
};

#endif // SISTEMA_H
