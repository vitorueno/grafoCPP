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

std::string Vertice::getIdentificador()
{
    return identificador;
}