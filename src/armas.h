#ifndef ARMAS_H
#define ARMAS_H

#include <iostream>
#include <fstream>
using namespace std;

class Armas
{
    public:
        Armas(unsigned short, unsigned short, unsigned short, unsigned short);
        Armas(const Armas&);
        Armas();
        ~Armas();
        void mostrar();
        string display();
        bool operator==(Armas);
        int calcularpotencia ();

    private:
        unsigned short canon;
        unsigned short misil;
        unsigned short rayo;
        unsigned short pem;
};

#endif // ARMAS_H
