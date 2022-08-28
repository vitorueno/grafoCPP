#include "grafo.h"

Grafo::Grafo()
{
}

Grafo::Grafo(std::string identificador)
{
    Grafo::identificador = identificador;
}

void Grafo::limpar()
{
    std::list<Vertice *>::iterator i;
    for (i = listaVertices.begin(); i != listaVertices.end(); i++)
    {
        delete *i;
    }
}

Grafo::~Grafo()
{
    limpar();
}

std::string Grafo::getIdentificador() const
{
    return identificador;
}

Vertice *Grafo::insereV()
{
    Vertice *v = new Vertice();
    listaVertices.push_back(v);
    return v;
}

Vertice *Grafo::insereV(std::string identificador)
{
    Vertice *v = new Vertice(identificador);
    listaVertices.push_back(v);
    return v;
}

int Grafo::getOrdem()
{
    return listaVertices.size();
}

Aresta *Grafo::insereA(Vertice *u, Vertice *v)
{
    Aresta *a = new Aresta();
    u->mapaAdjacencia[v] = a;
    v->mapaAdjacencia[u] = a;
    return a;
}

Aresta *Grafo::insereA(Vertice *u, Vertice *v, std::string identificador)
{
    Aresta *a = new Aresta(identificador);
    u->mapaAdjacencia[v] = a;
    v->mapaAdjacencia[u] = a;
    return a;
}

Vertice *Grafo::getV(std::string identificador)
{
    for (auto &v : listaVertices)
    {
        if (v->getIdentificador() == identificador)
        {
            return v;
        }
    }
    return nullptr;
}

std::list<Vertice *>::const_iterator Grafo::vertices()
{
    return listaVertices.begin();
}