#include "altanaves.h"
#include "asignararmas.h"

vector <Nave*> AltaNaves (vector <Nave*> lista_naves, vector <Propietario*> lista_propietarios, Fecha f)
{
    string tipo, idnave, propulsion, idprop, integer, escudo;
    unsigned short tripulantes, precio, hangar, capacidad, velocidad;
    unsigned int control=1, i, pasajeros;
    bool validar;
    switch (control)
    {
    case 1:
    {
        if(lista_propietarios.empty())
        {
            cout<<"\nNo hay propietarios registrados en el sistema.\nSe recuerda que debe existir al menos un propietario.\n"<<endl;
            break;
        }
        cout<<"\nIntroduzca el número de identificación de la nave (LNNNNLLL): ";
        cin>>idnave;
        cout<<endl;
        while(ValidaIdNave(idnave))
        {   cout<<"ERROR, por favor introduzca un número de identificación válido (LNNNNLLL): ";
            cin>>idnave;
            cout<<endl;
        }
        if (!lista_naves.empty())
        {
            for (i=0; i<lista_naves.size(); i++)
            {
                if (lista_naves[i]->obtenerid()==idnave)
                {
                    cout<<"\nLa nave ya esta registrada en el sistema, por favor asegúrese de introducir los datos correctamente"<<endl;
                    validar=true;
                    break;
                }
                validar=false;
            }
            if (validar) break;
        }
        cout<<"\nIntroduzca el número de identificación del propietario: ";
        cin>>idprop;
        cout<<endl;
        while(ValidaIdHumano(idprop) && ValidaIdExtra(idprop))
        {
            cout<<"ERROR por favor, introduzca una identificación de propietario válida: ";
            cin>>idprop;
            cout<<endl;
        }
        for (i=0; i<lista_propietarios.size(); i++)
        {
            if (lista_propietarios[i]->obtenerid()==idprop)
            {
                validar=true;
                break;
            }
            validar=false;
        }
        if (!validar)
        {
            cout<<"El propietario no está dado de alta."<<endl;
            break;
        }
        do
        {
            cout<<"\nIndique el tipo de nave:\n1.Estacion espacial\n2.Destructor\n3.Carguero\n4.Caza"<<endl;
            cin>>tipo;
            cout<<endl;
            while((tipo[0]!='1' && tipo[0]!='2' && tipo[0]!='3' && tipo[0]!='4') || tipo.length()!=1)
            {
                cout<<"ERROR, por favor introduzca un tipo de nave correcto: ";
                cin>>tipo;
                cout<<endl;
            }
            if((tipo[0]=='1'&& idprop.length()==10) || (tipo[0]=='2' && idprop.length()==9))
            {
                cout<<"La especie del propietario no puede manejar esa nave. Recuerda:\nLos humanos no pueden pilotar destructores y los extraterrestres no pueden pilotar estaciones espaciales";
            }
        }
        while ((tipo[0]=='1'&& idprop.length()==10) || (tipo[0]=='2' && idprop.length()==9));
        cout<<"\nIntroduzca el tipo de propulsion\n1.Motor de curvatura\n2.Compresor de traza\n3.Motor FTL\n4.Velas Solares\n5.Motor Iónico"<<endl;
        cin>>propulsion;
        cout<<endl;
        while((propulsion[0]!='1' && propulsion[0]!='2' && propulsion[0]!='3' && propulsion[0]!='4' && propulsion[0]!='5') || propulsion.length()!=1)
        {
            cout<<"ERROR, por favor introduzca una ocpcion correcta: ";
            cin>>propulsion;
            cout<<endl;
        }
        if(tipo[0]!='4')
        {
            cout<<"\nIntroduzca el número de tripulantes que manejan la nave: ";
            cin>>integer;
            cout<<endl;
            tripulantes = atoi(integer.c_str());
            while(tripulantes<=0 || integer.length()>4 ||ValidarNum(integer))
            {
                cout<<"ERROR, por favor introduzca un numero de tripulantes correcto (1-9999): ";
                cin>>integer;
                cout<<endl;
                tripulantes = atoi(integer.c_str());
            }
        }
        cout<<"Indique el precio de la nave: ";
        cin>>integer;
        cout<<endl;
        precio = atoi(integer.c_str());
        while(precio<=0 || integer.length()>4 ||ValidarNum(integer))
        {
            cout<<"ERROR, introduzca un precio correcto (0-9999): ";
            cin>>integer;
            cout<<endl;
            precio = atoi(integer.c_str());
        }

        switch(tipo[0])
        {
        case '1'://alta estacion espacial
        {  cout<<"Introduzca el numero de pasajeros de la Estacion espacial: ";
            cin>>integer;
            cout<<endl;
            pasajeros = atoi(integer.c_str());
            while(pasajeros<=0 || integer.length()>9 ||ValidarNum(integer))
            {
                cout<<"ERROR, por favor introduzca un número de pasajeros correcto (0-999.999.999): ";
                cin>>integer;
                cout<<endl;
                pasajeros = atoi(integer.c_str());
            }
            cout<<"Introduzca el numero de hangares de la Estacion espacial: ";
            cin>>integer;
            cout<<endl;
            hangar = atoi(integer.c_str());
            while(hangar<=0 || integer.length()>4 ||ValidarNum(integer))
            {
                cout<<"ERROR, por favor introduzca un numero de hangares correcto (0-9999): ";
                cin>>integer;
                cout<<endl;
                hangar = atoi(integer.c_str());
            }
            cout<<"Indique si la estacion espacial posee escudo (s/n): ";
            cin>>escudo;
            cout<<endl;
            while((escudo[0]!='s' && escudo[0]!='n') || escudo.length()!=1)
            {
                cout<<"ERROR, por favor indique s o n: ";
                cin>>escudo;
                cout<<endl;
            }
            if (escudo[0]=='s') validar=true;
            else validar=false;
            lista_naves.push_back(new Estacion(tipo, idnave, idprop, propulsion, tripulantes, precio, f, pasajeros, hangar, validar));
            cout<<"\nLa estación espacial "<<idnave<<" se ha dado de alta con éxito"<<endl;
            break;
        }

        case '2'://alta destructor
        {
            cout<<"ARMAS DEL DESTRUCTOR"<<endl;
            Armas armamento=AsignarArmas();
            lista_naves.push_back(new Destructor(tipo, idnave, idprop, propulsion, tripulantes, precio, f, armamento));
            cout<<"\nEl destructor "<<idnave<<" se ha dado de alta con éxito"<<endl;
            break;
        }

        case '3'://alta carguero
            cout<<"Indique la CAPACIDAD del carguero: ";
            cin>>integer;
            cout<<endl;
            capacidad = atoi(integer.c_str());
            while(capacidad<=0 || integer.length()>4 || ValidarNum(integer))
            {
                cout<<"ERROR, por favor introduzca un numero correcto: ";
                cin>>integer;
                cout<<endl;
                capacidad = atoi(integer.c_str());
            }
            cout<<"Indique la VELOCIDAD del carguero: ";
            cin>>integer;
            cout<<endl;
            velocidad = atoi(integer.c_str());
            while(velocidad<=0 || integer.length()>4 || ValidarNum(integer))
            {
                cout<<"ERROR, por favor introduzca un numero correcto: ";
                cin>>integer;
                cout<<endl;
                velocidad = atoi(integer.c_str());
            }
            cout<<"Indique si el posee escudo (s/n): ";
            cin>>escudo;
            cout<<endl;
            while((escudo[0]!='s' && escudo[0]!='n') || escudo.length()!=1)
            {
                cout<<"ERROR, por favor indique s o n: ";
                cin>>escudo;
                cout<<endl;
            }
            if (escudo[0]=='s') validar=true;
            else validar=false;

            lista_naves.push_back(new Carguero(tipo, idnave, idprop, propulsion, tripulantes, precio, f, capacidad, velocidad, validar));
            cout<<"\nEl carguero "<<idnave<<" se ha dado de alta con éxito"<<endl;
            break;

        case '4'://alta Caza
            cout<<"Indique la velocidad del caza: ";
            cin>>integer;
            cout<<endl;
            velocidad = atoi(integer.c_str());
            while(velocidad<=0 || integer.length()>4)
            {
                cout<<"ERROR, por favor introduzca un numero correcto: ";
                cin>>integer;
                cout<<endl;
                velocidad = atoi(integer.c_str());
            }
            cout<<"ARMAMENTO DEL CAZA\n"<<endl;
            Armas armamento=AsignarArmas();
            lista_naves.push_back(new Caza(tipo, idnave, idprop, propulsion, 1, precio, f, velocidad, armamento));
            cout<<"\nEl caza "<<idnave<<" se ha dado de alta con éxito"<<endl;
            break;
        }
    }

        break;
    default:
        break;
    }

    return lista_naves;
}
