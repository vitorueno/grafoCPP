#include "buscaProfundidade.h"

BuscaProfundidade::BuscaProfundidade()
{
}

BuscaProfundidade::~BuscaProfundidade()
{
}

void BuscaProfundidade::DFS(Grafo *g)
{
    for (auto v : g->vertices())
    {
        cor[v] = branco;
        pi[v] = nullptr;
    }

    tempo = 0;

    for (auto u : g->vertices())
    {
        if (cor[u] == branco)
        {
            DFS_visit(g, u);
        }
    }
}

void BuscaProfundidade::DFS_visit(Grafo *g, Vertice *u)
{
    cor[u] = cinza;
    tempo += 1;
    d[u] = tempo;

    for (auto v : g->adj(u))
    {
        if (cor[v] == branco)
        {
            pi[v] = u;
            DFS_visit(g, v);
        }
    }

    cor[u] = preto;
    tempo++;
    f[u] = tempo;
}

void BuscaProfundidade::imprimeCaminho(Grafo *g, Vertice *s, Vertice *v)
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

void BuscaProfundidade::mostraInformacao(Grafo *g)
{
    for (auto v : g->vertices())
    {
        std::cout << *v << "\n";
        if (pi[v] != nullptr)
        {
            std::cout << "predecessor: " << *(pi[v]) << "\n";
        }
        else
        {
            std::cout << "predecessor: nulo\n";
        }

        std::cout << "tempo de abertura: " << d[v] << "\n";
        std::cout << "tempo de fechamento: " << f[v] << "\n";
        std::cout << "cor: " << cor[v] << "\n\n";
    }
}
