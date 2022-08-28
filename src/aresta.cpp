#include "aresta.h"

Aresta::Aresta()
{
}

Aresta::Aresta(std::string identificador)
{
    Aresta::identificador = identificador;
}

Aresta::Aresta(Vertice *u, Vertice *v, std::string identificador)
{
    Aresta::u = u;
    Aresta::v = v;
    Aresta::identificador = identificador;
}

Aresta::Aresta(Vertice *u, Vertice *v)
{
    Aresta::u = u;
    Aresta::v = v;
}

Aresta::~Aresta()
{
}

std::string Aresta::getIdentificador()
{
    return identificador;
}

Vertice *Aresta::getU()
{
    return u;
}

Vertice *Aresta::getV()
{
    return v;
}

void Aresta::setIdentificador(std::string identificador)
{
    Aresta::identificador = identificador;
}

void Aresta::setU(Vertice *u)
{
    Aresta::u = u;
}

void Aresta::setV(Vertice *v)
{
    Aresta::v = v;
}
