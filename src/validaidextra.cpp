#include "validaidextra.h"

bool ValidaIdExtra(string id)
{
    if(id.length()!=10)return true;

    for(int i=0; i<10;i++)
    {
        if((int)id[i] <48 || (int)id[i] >57)return true;
    }
    return false;
}
