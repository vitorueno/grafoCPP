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

void Conexidade::makeSet(Vertice *x)
{
    p[x] = x;
    rank[x] = 0;
}

void Conexidade::unionSet(Vertice *x, Vertice *y)
{
    link(findSet(x), findSet(y));
}

void Conexidade::link(Vertice *x, Vertice *y)
{
    if (rank[x] > rank[y])
    {
        p[y] = x;
    }
    else
    {
        p[x] = y;
    }
    if (rank[x] == rank[y])
    {
        rank[y] = rank[y] + 1;
    }
}

Vertice *Conexidade::findSet(Vertice *x)
{
    if (x != p[x])
    {
        p[x] = findSet(p[x]);
    }
    return p[x];
}

Conexidade::Conexidade()
{
}

Conexidade::~Conexidade()
{
}
