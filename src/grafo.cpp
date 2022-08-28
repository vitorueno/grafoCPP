#include "grafo.h"

Grafo::Grafo()
{
}

Grafo::Grafo(std::string identificador)
{
    Grafo::identificador = identificador;
}

Grafo::~Grafo()
{
}

std::string Grafo::getIdentificador()
{
    return identificador;
}

void Grafo::insereV()
{
    listaVertices.push_back(Vertice());
}

void Grafo::insereV(std::string identificador)
{
    listaVertices.push_back(Vertice(identificador));
}

int Grafo::getOrdem()
{
    return listaVertices.size();
}

// const std::list<Vertice> &Grafo::vertices() const
// {
//     return listaVertices;
// }

std::list<Vertice>::iterator Grafo::vertices()
{
    return listaVertices.begin();
}