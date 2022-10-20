#include "buscaLargura.h"

void BuscaLargura::BFS(Grafo *g, Vertice *s)
{
    for (auto v : g->vertices())
    {
        cor[v] = branco;
        pi[v] = nullptr;
        d[v] = std::numeric_limits<int>::infinity();
    }

    d[s] = 0;
    cor[s] = cinza;
    q.push(s);

    while (!q.empty())
    {
        Vertice *u = q.front();
        q.pop();
        for (auto v : g->adj(u))
        {
            if (cor[v] == branco)
            {
                q.push(v);
                cor[v] = cinza;
                pi[v] = u;
                d[v] = d[u] + 1;
            }
        }
        cor[u] = preto;
    }
}

void BuscaLargura::BFS(GrafoDirigido *g, Vertice *s)
{
    for (auto v : g->vertices())
    {
        cor[v] = branco;
        pi[v] = nullptr;
        d[v] = std::numeric_limits<int>::infinity();
    }

    d[s] = 0;
    cor[s] = cinza;
    q.push(s);

    while (!q.empty())
    {
        Vertice *u = q.front();
        q.pop();
        for (auto v : g->adj(u))
        {
            if (cor[v] == branco)
            {
                q.push(v);
                cor[v] = cinza;
                pi[v] = u;
                d[v] = d[u] + 1;
            }
        }
        cor[u] = preto;
    }
}

void BuscaLargura::imprimeCaminho(Grafo *g, Vertice *s, Vertice *v)
{
    if (v == s)
    {
        std::cout << *v << "\n";
    }
    else
    {
        if (pi[v] == nullptr)
        {
            std::cout << "não existe caminho de s para v\n";
        }
        else
        {
            imprimeCaminho(g, s, pi[v]);
            std::cout << *v << "\n";
        }
    }
}

BuscaLargura::BuscaLargura()
{
}

BuscaLargura::~BuscaLargura()
{
}
