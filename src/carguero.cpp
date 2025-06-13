#include "carguero.h"

Carguero::Carguero(string _tipo, string _id_nave, string _id_propietario, string _propulsion, unsigned short _tripulantes, unsigned short _precio, Fecha _f, unsigned short _capacidad, unsigned short _velocidad, bool _escudo )
    :Nave( _tipo, _id_nave, _id_propietario, _propulsion, _tripulantes, _precio, _f)
{
    capacidad=_capacidad;
    velocidad=_velocidad;
    escudo=_escudo;
}

Carguero::~Carguero(){}

void Carguero::mostrar()
{
    Nave::mostrar();
    cout<<"\t"<<capacidad<<"\t\t"<<velocidad<<"\t\t";
    if (escudo==1) cout <<"SI"<<endl;
    else cout <<"NO"<<endl;
}
void Carguero::modificar()
{
    string opcion, integer, escudoest;
    do
    {
        cout<<"¿Que desea modificar?\n\n1.Propulsión\n2.Tripulantes\n3.Precio.\n4.Capacidad\n5.Velocidad.\n6.Escudo.\n0.Salir\n";
        cin>>opcion;
        while((opcion[0]!='1' && opcion[0]!='2' && opcion[0]!='3' && opcion[0]!='4' && opcion[0]!='5' && opcion[0]!='6' && opcion[0]!='0') || opcion.length()!=1)
        {
            cout<<"ERROR, por favor introduzca una opcion correcta"<<endl;
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

        case '4':   cout<<"Indique la CAPACIDAD del carguero: ";
            cin>>integer;
            capacidad = atoi(integer.c_str());
            while(capacidad<=0 || integer.length()>4 || ValidarNum(integer))
            {
                cout<<"ERROR, por favor introduzca un numero correcto: ";
                cin>>integer;
                capacidad = atoi(integer.c_str());
            }
            cout<<"\nModificación realizada con éxito.\n";
            break;

        case '5':   cout<<"Indique la VELOCIDAD del carguero: ";
            cin>>integer;
            velocidad = atoi(integer.c_str());
            while(velocidad<=0 || integer.length()>4 || ValidarNum(integer))
            {
                cout<<"ERROR, por favor introduzca un numero correcto: ";
                cin>>velocidad;
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

        case '0':   break;

        }
    }while(opcion[0]!='0');
}

string Carguero::display()
{
    return Nave::display()+to_string(capacidad)+" "+to_string(velocidad)+" "+to_string(escudo)+"\n";
}

int Carguero::potencia_destructiva()
{
    return 0;
}
