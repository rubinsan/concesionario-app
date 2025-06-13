#include "estacion.h"

Estacion::Estacion(string _tipo, string _id_nave, string _id_propietario, string _propulsion, unsigned short _tripulantes, unsigned short _precio, Fecha _f, unsigned int _pasajeros, unsigned short _hangares, bool _escudo)

    :Nave( _tipo, _id_nave, _id_propietario, _propulsion, _tripulantes, _precio, _f)
{
    pasajeros=_pasajeros;
    hangares=_hangares;
    escudo=_escudo;
}

Estacion::~Estacion(){}

void Estacion::mostrar()
{
    Nave::mostrar();
    cout<<"\t"<<pasajeros<<"\t\t"<<hangares<<"\t\t";
    if (escudo==1) cout <<"SI"<<endl;
    else cout <<"NO"<<endl;
}

void Estacion::modificar()
{
    string opcion, integer, escudoest;
    {
        cout<<"¿Que desea modificar?\n\n1.Propulsión\n2.Tripulantes\n3.Precio.\n4.Pasajeros\n5.Hangares.\n6.Escudo.\n0.Salir\n";
        cin>>opcion;
        while((opcion[0]!='1' && opcion[0]!='2' && opcion[0]!='3' && opcion[0]!='4' && opcion[0]!='5' && opcion[0]!='6' && opcion[0]!='0') || opcion.length()!=1)
        {
            cout<<"ERROR, por favor introduzca una opción correcta"<<endl;
            cin>>opcion;
        }

        switch (opcion[0])
        {
        case '1':  cout<<"Introduzca el tipo de propulsion\n1.motor de curvatura\n2.compresor de traza\n3.motor FTL\n4.velas solares\n5.motor iónico"<<endl;
            cin>>propulsion;
            while((propulsion[0]!='1' && propulsion[0]!='2' && propulsion[0]!='3' && propulsion[0]!='4' && propulsion[0]!='5') || propulsion.length()!=1)
            {
                cout<<"ERROR, por favor introduzca una ocpcion correcta: ";
                cin>>propulsion;
            }
            cout<<"\nModificación realizada con éxito.\n";
            break;

        case'2':    cout<<"Introduzca el número de tripulantes que manejan la nave: ";
            cin>>integer;
            tripulantes = atoi(integer.c_str());
            while(tripulantes<=0 || integer.length()>4 ||ValidarNum(integer))
            {
                cout<<"ERROR, por favor introduzca un numero de tripulantes correcto (1-9999): ";
                cin>>integer;
                tripulantes = atoi(integer.c_str());
            }
            cout<<"\nModificación realizada con éxito.\n";
            break;

        case '3':   cout<<"Indique el precio de la nave: ";
            cin>>integer;
            precio = atoi(integer.c_str());
            while(precio<=0 || integer.length()>4 ||ValidarNum(integer))
            {
                cout<<"ERROR, introduzca un precio correcto (0-9999): ";
                cin>>integer;
                precio = atoi(integer.c_str());
            }
            cout<<"\nModificación realizada con éxito.\n";
            break;

        case '4':  cout<<"Introduzca el numero de pasajeros de la Estacion espacial: ";
            cin>>integer;
            pasajeros = atoi(integer.c_str());
            while(pasajeros<=0 || integer.length()>9 ||ValidarNum(integer))
            {
                cout<<"ERROR, por favor introduzca un número de pasajeros correcto (0-999.999.999): ";
                cin>>integer;
                pasajeros = atoi(integer.c_str());
            }
            cout<<"\nModificación realizada con éxito.\n";
            break;

        case '5':  cout<<"Introduzca el numero de hangares de la Estacion espacial: ";
            cin>>integer;
            hangares = atoi(integer.c_str());
            while(hangares<=0 || integer.length()>4 ||ValidarNum(integer))
            {
                cout<<"ERROR, por favor introduzca un numero de hangares correcto (0-9999): ";
                cin>>integer;
                hangares = atoi(integer.c_str());
            }
            cout<<"\nModificación realizada con éxito.\n";
            break;

        case '6':   cout<<"Indique si el posee escudo (s/n): ";
            cin>>escudoest;
            while((escudoest[0]!='s' && escudoest[0]!='n') || escudoest.length()!=1)
            {
                cout<<"ERROR, por favor indique s o n: ";
                cin>>escudoest;
            }
            if (escudoest[0]=='s') escudo=true;
            else escudo=false;
            cout<<"\nModificación realizada con éxito.\n";
            break;

        case '0': break;

        }
    }while(opcion[0]!='0');
}

string Estacion::display()
{
    return Nave::display()+to_string(pasajeros)+" "+to_string(hangares)+" "+to_string(escudo)+"\n";
}
int Estacion::potencia_destructiva()
{
    return 0;
}
