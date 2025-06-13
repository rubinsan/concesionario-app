#ifndef FECHA
#define FECHA
#include <iostream>
#include <fstream>

using namespace std;

    class Fecha {

        public:

            Fecha(unsigned short, unsigned short, unsigned short);
            Fecha(const Fecha&);
            Fecha();
            ~Fecha();
            void mostrar();
            string display();
            bool operator ==(Fecha);
            int calculo ();

        private:
            unsigned short dia;
            unsigned short mes;
            unsigned short ano;


    };


#endif // FECHA

