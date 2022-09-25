#include "arestaDirigida.h"

ArestaDirigida::ArestaDirigida()
{
}

ArestaDirigida::ArestaDirigida(std::string identificador)
    : ObjetoIdentificado{identificador}
{
}

ArestaDirigida::ArestaDirigida(VerticeDirigido *u, VerticeDirigido *v, std::string identificador)
    : ObjetoIdentificado{identificador}, u{u}, v{v}
{
}

ArestaDirigida::ArestaDirigida(VerticeDirigido *u, VerticeDirigido *v)
    : u{u}, v{v}
{
}

ArestaDirigida::~ArestaDirigida()
{
}

VerticeDirigido *ArestaDirigida::getU()
{
    return u;
}

VerticeDirigido *ArestaDirigida::getV()
{
    return v;
}

void ArestaDirigida::setU(VerticeDirigido *u)
{
    ArestaDirigida::u = u;
}

void ArestaDirigida::setV(VerticeDirigido *v)
{
    ArestaDirigida::v = v;
}

std::ostream &operator<<(std::ostream &os, const ArestaDirigida &a)
{
    os << "ArestaDirigida <" << a.identificador << "> (" << a.u->getIdentificador()
       << ", " << a.v->getIdentificador() << ")";
    return os;
}
