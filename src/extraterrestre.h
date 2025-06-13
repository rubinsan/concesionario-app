#ifndef EXTRATERRESTRE
#define EXTRATERRESTRE

#include <iostream>
#include <cstring>
#include "propietario.h"

using namespace std;

    class Extraterrestre: public Propietario {

        public:

            Extraterrestre(string, string, string);
            ~Extraterrestre();
            void mostrar();
            void modificar();
            string obtenerid();
            string display();

        private:
            string id;



    };



#endif // EXTRATERRESTRE

