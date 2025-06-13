#ifndef NAVE
#define NAVE
#include <iostream>
#include <fstream>
#include <cstring>
#include "fecha.h"
#include <vector>
#include "validaidnave.h"
#include "validarnum.h"

using namespace std;

    class Nave {

        public:

            Nave(string, string, string , string , unsigned short , unsigned short, Fecha);
            void asignar_propietario(string);
            string obtenerid();
            string obtenertipo();
            string obtenerprop();
            virtual ~Nave();
            virtual void mostrar();
            virtual void modificar();
            virtual string display();
            virtual int potencia_destructiva();

        protected:

            string tipo;
            string id_nave;
            string id_propietario;
            string propulsion;
            unsigned short tripulantes;
            unsigned short precio;
            Fecha f;
    };

#endif // NAVE

