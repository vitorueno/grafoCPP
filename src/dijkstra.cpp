#include "dijkstra.h"

Dijkstra::Dijkstra(/* args */)
{
}

Dijkstra::~Dijkstra()
{
}

Vertice *Dijkstra::remove_minimo()
{
    Vertice *vMenorCusto = q.front();
    int menor_custo = d[vMenorCusto];

    for (auto v : q)
    {
        if (d[v] < menor_custo)
        {
            vMenorCusto = v;
            menor_custo = d[v];
        }
    }

    q.remove(vMenorCusto);

    return vMenorCusto;
}

void Dijkstra::inicializaFila(GrafoNaoDirigido *g)
{
    for (auto v : g->vertices())
    {
        q.push_back(v);
    }
}

bool Dijkstra::pertenceAFila(Vertice *v)
{
    for (auto u : q)
    {
        if (u == v)
        {
            return true;
        }
    }
    return false;
}

void Dijkstra::dijkstra(GrafoNaoDirigido *g, Vertice *s)
{
    infinito = 10000;

    for (auto v : g->vertices())
    {
        d[v] = infinito;
        p[v] = nullptr;
    }

    d[s] = 0;
    std::unordered_set<Vertice *> S;
    inicializaFila(g);

    while (!q.empty())
    {
        Vertice *u = remove_minimo();
        S.insert(u);
        for (auto v : g->adj(u))
        {
            Aresta *aresta = g->getA(u, v).front();
            if ((pertenceAFila(v)) && (d[v] > (d[u] + aresta->getW())))
            {
                d[v] = (d[u] + aresta->getW());
                p[v] = u;
            }
        }
    }
}