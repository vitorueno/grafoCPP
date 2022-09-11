#include "verticeDirigido.h"

VerticeDirigido::VerticeDirigido()
{
}

VerticeDirigido::VerticeDirigido(std::string identificador) : ObjetoIdentificado{identificador}
{
}

VerticeDirigido::~VerticeDirigido()
{
}

std::ostream &operator<<(std::ostream &os, const VerticeDirigido &v)
{
    os << "Vértice <" << v.identificador << "> ";
    return os;
}

std::string VerticeDirigido::toString()
{
    std::ostringstream ss;
    ss << identificador;
    return ss.str();
}