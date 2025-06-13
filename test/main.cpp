#include <iostream>
#include <time.h>
#include <string.h>
#include "sistema.h"

int main()
{

    time_t tiempo = time(NULL);//variable donde guardo el valor de los segundos transcurridos desde 1970.
    unsigned int d, m, a;
    struct tm *tlocal = localtime(&tiempo); //la funcion localtime transforma el nuemro de segundos en años, dias, etc. y lo guerda en una variable de tipo tm.
    char output[11]; //array donde guardo la fecha
    strftime(output,11,"%d/%m/%Y",tlocal); //formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy
    string _fecha (output);//convierte el char a string.
    string integer=_fecha.substr(0,2);//corta y pega en integer los caracteres deseados.
    d = atoi(integer.c_str());
    integer=_fecha.substr(3,2);
    m = atoi(integer.c_str());
    integer=_fecha.substr(6,4);
    a = atoi(integer.c_str());
    cout<<"\nFecha del sistema: ";
    Fecha f1(d,m,a);//Para iniciar el sistema se le pasa la fecha actual del equipo en que se ejecute.
    f1.mostrar();
    Sistema inicio=Sistema(f1);
    inicio.bienvenida();
    inicio.menu();


}

