#include "mostrarnaves.h"

void MostrarNaves (vector <Nave*> lista_naves)
{
    unsigned int control=1;
    switch (control)
    {
    case 1:
    {
        bool validar;
        unsigned int i;
        if(lista_naves.empty())
        {
            cout<<"\nNo hay naves registradas.\n"<<endl;
            break;
        }
        for (i=0; i<lista_naves.size(); i++)//comprobar si hay estaciones
        {
            if (lista_naves[i]->obtenertipo()=="1")
            {
                validar=1;
                break;
            }
            else validar=0;
        }

        if (validar)
        {
            cout<<"\n\tESTACIONES ESPACIALES\n"<<endl;
            cout<<"MATRICULA\tPROPIETARIO\tPROPULSION\t\tTRIPULANTES\tPRECIO\tFECHA DE ALTA\tPASAJEROS\tHANGARES\tESCUDO"<<endl;
            cout<<"============================================================================================================================================================================================="<<endl;
            for (i=0; i<lista_naves.size(); i++)//mostrar estaciones
            {
                if (lista_naves[i]->obtenertipo()=="1") lista_naves[i]->mostrar();
            }
        }
        for (i=0; i<lista_naves.size(); i++)//comprobar si hay destructores
        {
            if (lista_naves[i]->obtenertipo()=="2")
            {
                validar=1;
                break;
            }
            else validar=0;
        }

        if (validar)
        {
            cout<<"============================================================================================================================================================================================="<<endl;
            cout<<"\n\tDESTRUCTORES\n"<<endl;
            cout<<"MATRICULA\tPROPIETARIO\tPROPULSION\t\tTRIPULANTES\tPRECIO\tFECHA DE ALTA\tCAÑONES DE PLASMA\tMISILES TERMONUCLEARES\t\tRAYOS LASER\tPEMs"<<endl;
            cout<<"============================================================================================================================================================================================="<<endl;
            for (i=0; i<lista_naves.size(); i++)//mostrar destructores
            {
                if (lista_naves[i]->obtenertipo()=="2") lista_naves[i]->mostrar();
            }
        }
        for (i=0; i<lista_naves.size(); i++)//comprobar si hay cargueros
        {
            if (lista_naves[i]->obtenertipo()=="3")
            {
                validar=1;
                break;
            }
            else validar=0;
        }

        if (validar)
        {
            cout<<"============================================================================================================================================================================================="<<endl;
            cout<<"\n\tCARGUEROS\n"<<endl;
            cout<<"MATRICULA\tPROPIETARIO\tPROPULSION\t\tTRIPULANTES\tPRECIO\tFECHA DE ALTA\tCAPACIDAD\tVELOCIDAD\tESCUDO"<<endl;
            cout<<"============================================================================================================================================================================================="<<endl;
            for (i=0; i<lista_naves.size(); i++)//mostrar cargueros
            {
                if (lista_naves[i]->obtenertipo()=="3") lista_naves[i]->mostrar();
            }
        }
        for (i=0; i<lista_naves.size(); i++)//comprobar si hay cazas
        {
            if (lista_naves[i]->obtenertipo()=="4")
            {
                validar=1;
                break;
            }
            else validar=0;
        }

        if (validar)
        {
            cout<<"============================================================================================================================================================================================="<<endl;
            cout<<"\n\tCAZAS\n"<<endl;
            cout<<"MATRICULA\tPROPIETARIO\tPROPULSION\t\tTRIPULANTES\tPRECIO\tFECHA DE ALTA\tVELOCIDAD\tCAÑONES DE PLASMA\tMISILES TERMONUCLEARES\t\tRAYOS LASER\tPEMs"<<endl;
            cout<<"============================================================================================================================================================================================="<<endl;
            for (i=0; i<lista_naves.size(); i++)//mostrar cazas
            {
                if (lista_naves[i]->obtenertipo()=="4")lista_naves[i]->mostrar();
            }
        }
        cout<<"=============================================================================================================================================================================================\n"<<endl;
    }

        break;
    default:
        break;
    }

}
