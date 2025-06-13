#include "validaidnave.h"

bool ValidaIdNave(string id)
{
    if(id.length()!=8)return true;

    if(((int)id[0] <65 || (int)id[0] >90) && ((int)id[0] <97 || (int)id[0] >122)) return true;
    for(int i=1; i<5;i++)
    {
        if((int)id[i] <48 || (int)id[i] >57)return true;
    }
    for(int i=5; i<8;i++)
    {
        if(((int)id[i] <65 || (int)id[i] >90) && ((int)id[i] <97 || (int)id[i] >122)) return true;
    }
    return false;
}
