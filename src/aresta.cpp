#include "aresta.h"

Aresta::Aresta()
{
}

Aresta::Aresta(std::string identificador)
{
    Aresta::identificador = identificador;
}

Aresta::~Aresta()
{
}

std::string Aresta::getIdentificador() const
{
    return identificador;
}