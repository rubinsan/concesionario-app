#include "armas.h"

Armas::Armas(unsigned short _canon, unsigned short _misil, unsigned short _rayo, unsigned short _pem ){
    canon=_canon;
    misil=_misil;
    rayo=_rayo;
    pem=_pem;

}

Armas::Armas()
{
    canon=0;
    misil=0;
    rayo=0;
    pem=0;
}

Armas::Armas(const Armas &a){
    canon=a.canon;
    misil=a.misil;
    rayo=a.rayo;
    pem=a.pem;

}

Armas::~Armas(){}

void Armas::mostrar()
{
    cout<<"\t"<<canon<<"\t\t\t"<<misil<<"\t\t\t\t"<<rayo<<"\t\t"<<pem<<endl;
}

bool Armas::operator ==(Armas a)
{
    if(this->canon==a.canon && this->misil==a.misil && this->rayo==a.rayo && this->pem==a.pem)return true;
    else return false;
}

string Armas::display()
{
    return to_string(canon)+" "+to_string(misil)+" "+to_string(rayo)+" "+to_string(pem)+"\n";
}

int Armas::calcularpotencia ()
{
  return ((canon*10)+(misil*20)+(rayo*5)+(pem*15));
}
