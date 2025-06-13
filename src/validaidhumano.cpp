#include "validaidhumano.h"


bool ValidaIdHumano(string id)
{
        if(id.length()!=9)return true;

        for(int i=0; i<8;i++)
        {
            if((int)id[i] <48 || (int)id[i] >57)return true;
        }

        if(((int)id[8] <65 || (int)id[8] >90) && ((int)id[8] <97 || (int)id[8] >122)) return true;

        return false;
}
