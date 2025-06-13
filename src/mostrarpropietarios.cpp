#include "mostrarpropietarios.h"

void MostrarPropietarios (vector <Propietario*> lista_propietarios)
{
    unsigned int control=1;
    switch (control)
    {
    case 1:
    {
        bool validar;
        unsigned int i;
        if(lista_propietarios.empty())
        {
            cout<<"\nNo hay propietarios registrados en el sistema."<<endl;
            break;
        }
        for (i=0; i<lista_propietarios.size(); i++)//comprobar si hay humanos
        {
            if (lista_propietarios[i]->obtenertipo()=="1")
            {
                validar=1;
                break;
            }
            else validar=0;
        }

        if (validar)
        {
            cout<<"\n\tHUMANOS\n"<<endl;
            cout<<"PLANETA DE ORIGEN\t\t\t\tNIF"<<endl;
            cout<<"================================================================================"<<endl;

            for (i=0; i<lista_propietarios.size(); i++)//mostramos los humanos
            {
                if (lista_propietarios[i]->obtenertipo()=="1")lista_propietarios[i]->mostrar();
            }
        }
        for (i=0; i<lista_propietarios.size(); i++)//comprobar si hay extraterrestres
        {
            if (lista_propietarios[i]->obtenertipo()=="2")
            {
                validar=1;
                break;
            }
            else validar=0;
        }
        if (validar)
        {
            cout<<"\n\tEXTRATERRESTRES\n"<<endl;
            cout<<"PLANETA DE ORIGEN\t\t\t\tNIE"<<endl;
            cout<<"================================================================================"<<endl;

            for (i=0; i<lista_propietarios.size(); i++)//mostramos los extraterrestes
            {
                if (lista_propietarios[i]->obtenertipo()=="2")lista_propietarios[i]->mostrar();
            }
        }
    }

        break;
    default:
        break;
    }

}
