#include "cargarventas.h"

vector <Ventas> CargarVentas (vector <Ventas> v)
{
    ifstream leerventas("Ventas.txt");

    while (!leerventas.eof()) //carga de los datos de las ventas
    {
        string integer, comprador, producto;
        unsigned int dia, mes, ano;

        leerventas>>integer;
        dia = atoi(integer.c_str());
        leerventas>>integer;
        mes = atoi(integer.c_str());
        leerventas>>integer;
        ano = atoi(integer.c_str());

        Fecha f(dia, mes, ano);

        leerventas>>comprador>>producto;

        if (dia!=0) v.push_back(Ventas(f, comprador, producto));
    }
    return v;
}
