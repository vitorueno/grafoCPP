#include "aresta.h"

Aresta::Aresta()
{
}

Aresta::Aresta(std::string identificador)
    : ObjetoIdentificado{identificador}
{
}

Aresta::Aresta(Vertice *u, Vertice *v, std::string identificador)
    : ObjetoIdentificado{identificador}, u{u}, v{v}
{
}

Aresta::Aresta(Vertice *u, Vertice *v)
    : u{u}, v{v}
{
}

Aresta::~Aresta()
{
}

Vertice *Aresta::getU()
{
    return u;
}

Vertice *Aresta::getV()
{
    return v;
}

int Aresta::getW()
{
    return w;
}

void Aresta::setU(Vertice *u)
{
    Aresta::u = u;
}

void Aresta::setV(Vertice *v)
{
    Aresta::v = v;
}

void Aresta::setW(int w)
{
    Aresta::w = w;
}

std::ostream &operator<<(std::ostream &os, const Aresta &a)
{
    os << "Aresta <" << a.identificador << "> (" << a.u->getIdentificador()
       << ", " << a.v->getIdentificador() << ")";
    return os;
}
