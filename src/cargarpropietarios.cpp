#include "cargarpropietarios.h"

vector <Propietario*> CargarPropietarios (vector <Propietario*> p)
{
    ifstream leerprop("Propietarios.txt");

    while (!leerprop.eof()) //carga de los datos de los propietarios
    {
        string tipo, planeta, id;
        char plan[30];//array para leer planetas

        leerprop>>tipo;
        leerprop>>id;
        leerprop.getline(plan,30);//como planeta puede llevar espacio, leemos hasta el final de linea
        for(unsigned int i=0; i<30;i++)//quitamos el espacio que hay antes del planeta en nuestro fichero
        {
            plan[i]=plan[i+1];
        }
        planeta=plan;

        if (tipo=="1") //Humano
        {
            p.push_back(new Humano(planeta,"1",id));
        }
        if (tipo=="2") //Extraterrestre
        {
            p.push_back(new Extraterrestre(planeta,"2",id));
        }
    }
    return p;
}
