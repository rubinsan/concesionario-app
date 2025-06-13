#include "asignararmas.h"

Armas AsignarArmas()
{
    unsigned int canon=0, misil=0, rayo=0, pem=0;
    string arma, integer;
    cout<<"¿La nave tiene cañones? (s/n): ";
    cin>>arma;
    cout<<endl;
    while((arma[0]!='s' && arma[0]!='n') || arma.length()!=1)
    {
        cout<<"ERROR, por favor indique s o n: ";
        cin>>arma;
        cout<<endl;
    }

    if (arma[0]=='s')
    {
        cout<<"¿Cuántos cañones tiene?: ";
        cin>>integer;
        cout<<endl;
        canon = atoi(integer.c_str());
        while(canon<=0 || integer.length()>4 ||ValidarNum(integer))
        {
            cout<<"ERROR, introduzca un número correcto (máx 9999): ";
            cin>>integer;
            cout<<endl;
            canon = atoi(integer.c_str());
        }
    }

    cout<<"¿La nave tiene misiles? (s/n): ";
    cin>>arma;
    cout<<endl;
    while((arma[0]!='s' && arma[0]!='n') || arma.length()!=1)
    {
        cout<<"ERROR, por favor indique s o n: ";
        cin>>arma;
        cout<<endl;
    }

    if (arma[0]=='s')
    {
        cout<<"¿Cuántos misiles tiene?: ";
        cin>>integer;
        cout<<endl;
        misil = atoi(integer.c_str());
        while(misil<=0 || integer.length()>4 ||ValidarNum(integer))
        {
            cout<<"ERROR, introduzca un número correcto (máx 9999): ";
            cin>>integer;
            cout<<endl;
            misil = atoi(integer.c_str());
        }
    }

    cout<<"¿La nave tiene rayos? (s/n): ";
    cin>>arma;
    cout<<endl;
    while((arma[0]!='s' && arma[0]!='n') || arma.length()!=1)
    {
        cout<<"ERROR, por favor indique s o n: ";
        cin>>arma;
        cout<<endl;
    }

    if (arma[0]=='s')
    {
        cout<<"¿Cuántos rayos tiene?: ";
        cin>>integer;
        cout<<endl;
        rayo = atoi(integer.c_str());
        while(rayo<=0 || integer.length()>4 ||ValidarNum(integer))
        {
            cout<<"ERROR, introduzca un número correcto (máx 9999): ";
            cin>>integer;
            cout<<endl;
            rayo= atoi(integer.c_str());
        }
    }

    cout<<"¿La nave tiene PEMs? (s/n): ";
    cin>>arma;
    cout<<endl;
    while((arma[0]!='s' && arma[0]!='n') || arma.length()!=1)
    {
        cout<<"ERROR, por favor indique s o n: ";
        cin>>arma;
        cout<<endl;
    }

    if (arma[0]=='s')
    {
        cout<<"¿Cuántos PEMs tiene?: ";
        cin>>integer;
        cout<<endl;
        pem = atoi(integer.c_str());
        while(pem<=0 || integer.length()>4 ||ValidarNum(integer))
        {
            cout<<"ERROR, introduzca un número correcto (máx 9999): ";
            cin>>integer;
            cout<<endl;
            pem = atoi(integer.c_str());
        }
    }
    Armas arms(canon,misil,rayo,pem);
    return arms;
}
