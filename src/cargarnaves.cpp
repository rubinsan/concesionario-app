#include "cargarnaves.h"


vector <Nave*> CargarNaves (vector <Nave*> n)
{
    ifstream leernaves("Naves.txt");
    ifstream leerprop("Propietarios.txt");
    ifstream leerventas("Ventas.txt");

    while (!leernaves.eof()) //carga de los datos de las naves
    {
        string integer, tipo, idnave, idprop, propulsion;
        unsigned int tripulantes, precio, dia, mes, ano, pasajeros, hangares, canon, misil, rayo, pem, capacidad, velocidad;
        bool escudo;

        leernaves>>tipo;
        leernaves>>idnave;
        leernaves>>idprop;
        leernaves>>propulsion;
        leernaves>>integer;
        tripulantes = atoi(integer.c_str());
        leernaves>>integer;
        precio = atoi(integer.c_str());

        leernaves>>integer;
        dia = atoi(integer.c_str());
        leernaves>>integer;
        mes = atoi(integer.c_str());
        leernaves>>integer;
        ano = atoi(integer.c_str());

        Fecha f(dia, mes, ano);

        if (tipo=="1") //Estacion
        {
            leernaves>>integer;
            pasajeros = atoi(integer.c_str());
            leernaves>>integer;
            hangares = atoi(integer.c_str());
            leernaves>>integer;
            escudo = atoi(integer.c_str());
            n.push_back(new Estacion(tipo, idnave, idprop, propulsion, tripulantes, precio, f, pasajeros, hangares, escudo));
        }
        if (tipo=="2") //destructor
        {
            leernaves>>integer;
            canon = atoi(integer.c_str());
            leernaves>>integer;
            misil = atoi(integer.c_str());
            leernaves>>integer;
            rayo = atoi(integer.c_str());
            leernaves>>integer;
            pem = atoi(integer.c_str());
            Armas armamento(canon,misil,rayo,pem);
            n.push_back(new Destructor(tipo, idnave, idprop, propulsion, tripulantes, precio, f, armamento));
        }
        if (tipo=="3") //carguero
        {
            leernaves>>integer;
            capacidad = atoi(integer.c_str());
            leernaves>>integer;
            velocidad = atoi(integer.c_str());
            leernaves>>integer;
            escudo = atoi(integer.c_str());
            n.push_back(new Carguero(tipo, idnave, idprop, propulsion, tripulantes, precio, f, capacidad, velocidad, escudo));
        }
        if (tipo=="4") //caza
        {
            leernaves>>integer;
            velocidad = atoi(integer.c_str());
            leernaves>>integer;
            canon = atoi(integer.c_str());
            leernaves>>integer;
            misil = atoi(integer.c_str());
            leernaves>>integer;
            rayo = atoi(integer.c_str());
            leernaves>>integer;
            pem = atoi(integer.c_str());
            Armas armamento(canon,misil,rayo,pem);
            n.push_back(new Caza(tipo, idnave, idprop, propulsion, 1, precio, f, velocidad, armamento));
        }
    }
    return n;
}
