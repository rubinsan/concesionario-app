#include "permitirventa.h"

bool PermitirVenta (Nave* n, Propietario* p)
{
    if (p->obtenerid().length()==9 && n->obtenertipo()=="2") return true;
    if (p->obtenerid().length()==10 && n->obtenertipo()=="1") return true;
    return false;
}
