#include <propietario.h>

Propietario::Propietario(string _origen, string _tipo)
{
    origen=_origen;
    tipo=_tipo;
}

Propietario::~Propietario(){}

void Propietario::mostrar(){}

void Propietario::modificar(){}

string Propietario::obtenerid()
{
    return " ";
}

string Propietario::display()
{
    return " ";
}

string Propietario::obtenertipo()
{
    return tipo;
}
