#include "vertice.h"

Vertice::Vertice()
{
}

Vertice::Vertice(std::string identificador) : ObjetoIdentificado{identificador}
{
}

Vertice::~Vertice()
{
}

std::ostream &operator<<(std::ostream &os, const Vertice &v)
{
    os << "Vértice <" << v.identificador << "> ";
    return os;
}
