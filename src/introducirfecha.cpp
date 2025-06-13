#include "introducirfecha.h"

Fecha IntroducirFecha()
{
    string integer;
    unsigned int d, m, a;
    cout<<"Introduzca el día: ";
    cin>>integer;
    d = atoi(integer.c_str());
    while(d<=0 || d>=32 || integer.length()>2 || ValidarNum(integer))
    {   cout<<"Día incorrecto, por favor, introduzca el día: ";
        cin>>integer;
        cout<<endl;
        d = atoi(integer.c_str());
    }

    cout<<"Introduzca el mes: ";
    cin>>integer;
    m = atoi(integer.c_str());
    while(m<=0 || m>=13 || integer.length()>2 || ValidarNum(integer))
        {   cout<<"Mes incorrecto, por favor, introduzca el mes: ";
            cin>>integer;
            cout<<endl;
            m = atoi(integer.c_str());
        }

    cout<<"Introduzca el año: ";
    cin>>integer;
    a = atoi(integer.c_str());
    while(a<=0 || integer.length()>4 || ValidarNum(integer))
    {
        cout<<"Año incorrecto, por favor, introduzca el año: ";
        cin>>integer;
        cout<<endl;
        a = atoi(integer.c_str());
    }
    Fecha fech(d,m,a);
    return fech;
}
