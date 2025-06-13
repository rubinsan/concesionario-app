#include "destructor.h"

Destructor::Destructor(string _tipo, string _id_nave, string _id_propietario, string _propulsion, unsigned short _tripulantes, unsigned short _precio, Fecha _f, Armas _armas)

    :Nave(_tipo, _id_nave, _id_propietario, _propulsion, _tripulantes, _precio, _f)
{
    armas=_armas;
}

Destructor::~Destructor(){}

void Destructor::mostrar()
{
    Nave::mostrar();
    armas.mostrar();
}

void Destructor::modificar()
{
    string opcion, integer, arma;
    unsigned short canon=0, misil=0, rayo=0, pem=0;
    do
    {
        cout<<"¿Que desea modificar?\n\n1.Propulsión\n2.Precio.\n3.Tripulantes.\n4.Armas.\n0.Salir\n";
        cin>>opcion;
        while((opcion[0]!='1' && opcion[0]!='2' && opcion[0]!='3' && opcion[0]!='4' && opcion[0]!='0') || opcion.length()!=1)
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

        case'2':    cout<<"Indique el precio de la nave: ";
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

        case'3':    cout<<"Introduzca el número de tripulantes que manejan la nave: ";
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

        case '4':
        {
            cout<<"ARMAMENTO DEL DESTRUCTOR\n"<<endl;
            cout<<"\tCAÑONES DE PLASMA\tMISILES TERMONUCLEARES\t\tRAYOS LASER\tPEMs"<<endl;
            cout<<"        ======================================================================================"<<endl;
            armas.mostrar();
            cout<<endl;
            cout<<"¿Desea modificar el número de cañones? (s/n): ";
            cin>>arma;
            while((arma[0]!='s' && arma[0]!='n') || arma.length()!=1)
            {
                cout<<"ERROR, por favor indique s o n: ";
                cin>>arma;
            }

            if (arma[0]=='s')
            {
                cout<<"Introduzca las unidades deseadas: ";
                cin>>integer;
                canon = atoi(integer.c_str());
                while(canon<=0 || integer.length()>4 ||ValidarNum(integer))
                {
                    cout<<"ERROR, introduzca un número correcto (máx 9999): ";
                    cin>>integer;
                    canon = atoi(integer.c_str());
                }
            }

            cout<<"¿Desea modificar el número de misiles? (s/n): ";
            cin>>arma;
            while((arma[0]!='s' && arma[0]!='n') || arma.length()!=1)
            {
                cout<<"ERROR, por favor indique s o n: ";
                cin>>arma;
            }

            if (arma[0]=='s')
            {
                cout<<"Introduzca las unidades deseadas: ";
                cin>>integer;
                misil = atoi(integer.c_str());
                while(misil<=0 || integer.length()>4 ||ValidarNum(integer))
                {
                    cout<<"ERROR, introduzca un número correcto (máx 9999): ";
                    cin>>integer;
                    misil = atoi(integer.c_str());
                }
            }

            cout<<"¿Desea modificar el número de rayos láser? (s/n): ";
            cin>>arma;
            while((arma[0]!='s' && arma[0]!='n') || arma.length()!=1)
            {
                cout<<"ERROR, por favor indique s o n: ";
                cin>>arma;
            }

            if (arma[0]=='s')
            {
                cout<<"Introduzca las unidades deseadas: ";
                cin>>integer;
                rayo = atoi(integer.c_str());
                while(rayo<=0 || integer.length()>4 ||ValidarNum(integer))
                {
                    cout<<"ERROR, introduzca un número correcto (máx 9999): ";
                    cin>>integer;
                    rayo= atoi(integer.c_str());
                }
            }

            cout<<"¿Desea modificar el número de PEMs? (s/n): ";
            cin>>arma;
            while((arma[0]!='s' && arma[0]!='n') || arma.length()!=1)
            {
                cout<<"ERROR, por favor indique s o n: ";
                cin>>arma;
            }
            if (arma[0]=='s')
            {
                cout<<"Introduzca las unidades deseadas: ";
                cin>>integer;
                pem = atoi(integer.c_str());
                while(pem<=0 || integer.length()>4 ||ValidarNum(integer))
                {
                    cout<<"ERROR, introduzca un número correcto (máx 9999): ";
                    cin>>integer;
                    pem = atoi(integer.c_str());
                }
            }

            Armas armamento(canon,misil,rayo,pem);
            armas=armamento;
            cout<<"\nModificación realizada con éxito.\n";
        }

        case '0':   break;

        }
    }while(opcion[0]!='0');
}

string Destructor::display()
{
    return Nave::display()+armas.display();
}
int Destructor::potencia_destructiva()
{
    return armas.calcularpotencia();
}
