#ifndef HUMANO
#define HUMANO

#include <iostream>
#include <cstring>
#include "propietario.h"

using namespace std;

    class Humano: public Propietario {

        public:

            Humano(string, string, string);
            ~Humano();
            void mostrar();
            void modificar();
            string obtenerid();
            string display();

        private:
            string id;



    };




#endif // HUMANO

