#include <fecha.h>

Fecha::Fecha(){}

Fecha::Fecha(unsigned short _dia, unsigned short _mes, unsigned short _ano)
{
    dia=_dia;
    mes=_mes;
    ano=_ano;
}

Fecha::Fecha(const Fecha &f)
{
    dia=f.dia;
    mes=f.mes;
    ano=f.ano;
}

 Fecha::~Fecha(){}

void Fecha::mostrar()
{
    cout <<dia<<"/"<<mes<<"/"<<ano;
}

bool Fecha::operator ==(Fecha f)
{
    if(this->dia==f.dia && this->mes==f.mes && this->ano==f.ano)return true;
    else return false;
}

string Fecha::display()
{
    return to_string(dia)+" "+to_string(mes)+" "+to_string(ano);
}
int Fecha::calculo ()
{
    return (dia+((mes-1)*30)+(ano*365));//no se tiene en cuenta los meses con 31 días, ni febrero con 28, ni los años bisiestos.
}
