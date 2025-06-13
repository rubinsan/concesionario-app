#include "validarnum.h"

bool ValidarNum(string elemento)
{
    for(int i=0; i<elemento.length();i++)
    {
        if((int)elemento[i] <48 || (int)elemento[i] >57) return true;
    }
    return false;
}
