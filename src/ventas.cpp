#include "ventas.h"

Ventas::Ventas(){}

Ventas::Ventas(Fecha f, string _comprador, string _producto)
{
    fecha=f;
    comprador=_comprador;
    producto=_producto;
}

Fecha Ventas::obtenerFecha()
{
    return fecha;
}
void Ventas::mostrar()
{
    fecha.mostrar();
    cout<<"\t"<<comprador<<"\t"<<producto<<endl;
}

string Ventas::display()
{
    return fecha.display()+" "+comprador+" "+producto+"\n";
}

string Ventas::obtenerComprador()
{
    return comprador;
}
int Ventas::calculo ()
{
    return fecha.calculo();
}
