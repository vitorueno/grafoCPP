#include "grafoNaoDirigido.h"

GrafoNaoDirigido::GrafoNaoDirigido()
{
}

GrafoNaoDirigido::GrafoNaoDirigido(std::string identificador)
    : Grafo{identificador}
{
}

GrafoNaoDirigido::~GrafoNaoDirigido()
{
    // limpar();
}

int GrafoNaoDirigido::grau(Vertice *v)
{
    int grau = 0;

    for (auto &keyValue : v->mapaAdjacencia) // para cada vértice adj do vértice v
    {
        std::list<Aresta *> arestas = keyValue.second; // arestas
        for (auto &a : arestas)
        {
            grau++;
        }
    }

    return grau;
}
