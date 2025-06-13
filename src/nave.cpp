#include <iostream>
#include "nave.h"
#include "fecha.h"

using namespace std;

Nave::Nave(string _tipo, string _id_nave, string _id_propietario, string _propulsion, unsigned short _tripulantes, unsigned short _precio, Fecha _f)
{
    tipo=_tipo;
    id_nave=_id_nave;
    id_propietario=_id_propietario;
    propulsion=_propulsion;
    tripulantes=_tripulantes;
    precio=_precio;
    f=_f;
}

Nave::~Nave() {}

void Nave::mostrar()
{
    if (propulsion[0]=='1')cout<<id_nave<<"\t"<<id_propietario<<"\t"<<"Motor de curvatura"<<"\t"<<tripulantes<<"\t\t"<<precio<<"\t";
    if (propulsion[0]=='2')cout<<id_nave<<"\t"<<id_propietario<<"\t"<<"Compresor de traza"<<"\t"<<tripulantes<<"\t\t"<<precio<<"\t";
    if (propulsion[0]=='3')cout<<id_nave<<"\t"<<id_propietario<<"\t"<<"Motor FTL"<<"\t\t"<<tripulantes<<"\t\t"<<precio<<"\t";
    if (propulsion[0]=='4')cout<<id_nave<<"\t"<<id_propietario<<"\t"<<"Velas solares"<<"\t\t"<<tripulantes<<"\t\t"<<precio<<"\t";
    if (propulsion[0]=='5')cout<<id_nave<<"\t"<<id_propietario<<"\t"<<"Motor iónico"<<"\t\t"<<tripulantes<<"\t\t"<<precio<<"\t";
    f.mostrar();
}
void Nave::modificar(){}

string Nave::obtenerid()
{
    return id_nave;
}

void Nave::asignar_propietario(string id_comprador)
{
    id_propietario=id_comprador;
}

string Nave::obtenertipo()
{
    return tipo;
}

string Nave::obtenerprop()
{
    return id_propietario;
}

string Nave::display()
{
    return tipo+" "+id_nave+" "+id_propietario+" "+propulsion+" "+to_string(tripulantes)+" "+to_string(precio)+" "+f.display()+" ";
}
int Nave::potencia_destructiva()
{
    return 0;
}
