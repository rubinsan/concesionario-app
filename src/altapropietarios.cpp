#include "altapropietarios.h"

vector <Propietario*> AltaPropietarios (vector <Propietario*> lista_propietarios)
{
    string planeta, especie, idhumano, idextraterrestre;
    unsigned int control=1, i;
    bool validar;
    switch (control)
    {
    case 1:
    {
        cout<<"Introduzca el planeta de origen del nuevo propietario (max. 30 caracteres): ";
        cin.ignore(256,'\n');
        getline(cin,planeta);
        cout<<endl;
        while(planeta.length()>=30)
        {
            cout<<"ERROR, por favor recuerde que el maximo son 30 caracteres."<<endl;
            cin.ignore(256,'\n');
            getline(cin,planeta);
            cout<<endl;
        }
        cout<<"Por favor, indique su especie:\n1. Humano.\n2. Extraterrestre."<<endl;
        cin>>especie;
        while((especie[0]!='1' && especie[0]!='2') || especie.length()!=1)
        {
            cout<<"ERROR, por favor introduzca una opcion correcta: ";
            cin>>especie;
            cout<<endl;
        }

        if (especie[0]=='1')
        {
            cout<<"Introduzca el número de identificación del humano (NNNNNNNNL): ";
            cin>>idhumano;
            cout<<endl;
            while(ValidaIdHumano(idhumano))
            {
                cout<<"ERROR, por favor asegúrese de que el formato sea el correcto (NNNNNNNNL): ";
                cin>>idhumano;
                cout<<endl;
            }
            if (!lista_propietarios.empty())
            {
                for (i=0; i<lista_propietarios.size(); i++)
                {
                    if (lista_propietarios[i]->obtenerid()==idhumano)
                    {
                        cout<<"\nEl humano ya esta registrado en el sistema, por favor asegúrese de introducir los datos correctamente"<<endl;
                        validar=true;
                        break;
                    }
                    validar=false;
                }
                if (validar) break;
            }
            lista_propietarios.push_back(new Humano(planeta,"1",idhumano));//se llama al constructor de humano.
            cout<<"\nEl humano se ha dado del alta en el sistema.\n";
        }

        if (especie[0]=='2')
        {
            cout<<"Introduzca el número de identificación del extraterrestre (NNNNNNNNNN): ";
            cin>>idextraterrestre;
            cout<<endl;
            while(ValidaIdExtra(idextraterrestre))
            {
                cout<<"ERROR, por favor asegúrese de que el formato sea el correcto (NNNNNNNNNN): ";
                cin>>idextraterrestre;
                cout<<endl;
            }
            if (!lista_propietarios.empty())
            {
                for (i=0; i<lista_propietarios.size(); i++)
                {
                    if (lista_propietarios[i]->obtenerid()==idextraterrestre)
                    {
                        cout<<"\nEl extraterreste ya esta registrado en el sistema, por favor asegúrese de introducir los datos correctamente"<<endl;
                        validar=true;
                        break;
                    }
                    validar=false;
                }
                if (validar) break;
            }
            lista_propietarios.push_back(new Extraterrestre(planeta,"2",idextraterrestre)); //se llama al constructor de extraterrestre.
            cout<<"\nEl extraterrestre se ha dado del alta en el sistema.\n";
        }

    }
        break;
    default:
        break;
    }


    return lista_propietarios;
}
