#include "conexidade.h"

void Conexidade::compomenteConexo(Grafo *g)
{
    for (auto v : g->vertices())
    {
        makeSet(v);
    }
    for (auto e : g->arestas())
    {
        if (findSet(e->getU()) != findSet(e->getV()))
        {
            unionSet(e->getU(), e->getV());
        }
    }
}

bool Conexidade::mesmoComponente(Vertice *u, Vertice *v)
{
    if (findSet(u) == findSet(v))
    {
        return true;
    }
    return false;
}

Conexidade::Conexidade()
{
}

Conexidade::~Conexidade()
{
}
