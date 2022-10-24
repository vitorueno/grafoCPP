#include "kruskal.h"

Kruskal::Kruskal()
{
}

Kruskal::~Kruskal()
{
}

Grafo Kruskal::kruskal(Grafo *g)
{
    Grafo a("Kruskal");
    copiaVerticeParaGrafo(g, &a);

    for (auto v : g->vertices())
    {
        makeSet(v);
    }

    for (auto e : ordenaMapaCusto())
    {
        // std::cout << e.second << "\n";
        Vertice *u = e.first->getU();
        Vertice *v = e.first->getV();

        if (findSet(u) != findSet(v))
        {
            a.insereA(u, v);
            unionSet(u, v);
        }
    }

    return a;
}

void Kruskal::setCustoAresta(Aresta *a, int custo)
{
    w[a] = custo;
}

std::vector<std::pair<Aresta *, int>> Kruskal::ordenaMapaCusto()
{
    std::vector<std::pair<Aresta *, int>> listaMapa;

    for (auto &keyValue : w)
    {
        listaMapa.push_back(keyValue);
    }

    std::sort(listaMapa.begin(), listaMapa.end(), compararCusto);

    return listaMapa;
}

void Kruskal::copiaVerticeParaGrafo(Grafo *g1, Grafo *g2)
{
    for (auto v : g1->vertices())
    {
        g2->insereV(v->getIdentificador());
    }
}

bool Kruskal::compararCusto(std::pair<Aresta *, int> &a, std::pair<Aresta *, int> &b)
{
    return a.second >= b.second;
}
