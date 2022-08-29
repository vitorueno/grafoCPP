#include "vertice.h"

Vertice::Vertice()
{
}

Vertice::Vertice(std::string identificador)
{
    Vertice::identificador = identificador;
}

Vertice::~Vertice()
{
}

std::string Vertice::getIdentificador() const
{
    return identificador;
}

std::ostream &operator<<(std::ostream &os, const Vertice &v)
{
    os << "Vértice <" << v.identificador << "> ";
    return os;
}

std::string Vertice::toString()
{
    std::ostringstream ss;
    ss << identificador;
    return ss.str();
}