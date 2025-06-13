#include <extraterrestre.h>

Extraterrestre::Extraterrestre(string _origen, string _tipo, string _id): Propietario(_origen,_tipo)
{
    id=_id;
}

Extraterrestre::~Extraterrestre(){}

void Extraterrestre::mostrar()
{
    if(origen.length()<=7)cout <<origen<<"\t\t\t\t\t\t"<<id<<endl;
    if(origen.length()>7 && origen.length()<=15)cout <<origen<<"\t\t\t\t\t"<<id<<endl;
    if(origen.length()>15 && origen.length()<=20)cout<<origen<<"\t\t\t\t"<<id<<endl;
    if(origen.length()>20 && origen.length()<=25)cout<<origen<<"\t\t\t\t"<<id<<endl;
}

string Extraterrestre::obtenerid()
{
    return id;
}

void Extraterrestre::modificar()
{
    string  opcion;
    do
    {
        cout<<"¿Que desea modificar?\n\n1.Planeta de origen\n2.Número de identificación\n0.Salir\n";
        cin>>opcion;
        while((opcion[0]!='1' && opcion[0]!='2' && opcion[0]!='0') || opcion.length()!=1)
        {
            cout<<"ERROR, por favor introduzca una opcion correcta"<<endl;
            cin>>opcion;
        }

        switch (opcion[0])
        {
        case'1':
            cout<<"Introduzca el nuevo planeta de origen del extraterrestre (max. 30 caracteres): ";
            cin.ignore(256,'\n');
            getline(cin,origen);
            cout<<endl;
            while(origen.length()>=30)
            {
                cout<<"ERROR, por favor recuerde que el maximo son 30 caracteres."<<endl;
                cin.ignore(256,'\n');
                getline(cin,origen);
                cout<<endl;
            }
            cout<<"\nModificación realizada con éxito.\n";
            break;

        case'2':    cout<<"Introduzca el nuevo número de identificación (NNNNNNNNNN): "<<endl;
            cin>>id;
            while(ValidaIdExtra(id))
            {
                cout<<"ERROR, por favor asegúrese de que el formato sea el correcto (NNNNNNNNNN): ";
                cin>>id;
            }
            cout<<"\nModificación realizada con éxito.\n";
            break;

        case'0':    break;

        }
    }while(opcion[0]!='0');
}

string Extraterrestre::display()
{
    return tipo+" "+id+" "+origen+"\n";
}
