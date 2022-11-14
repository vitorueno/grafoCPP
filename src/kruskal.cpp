#include "kruskal.h"

Kruskal::Kruskal()
{
}

Kruskal::~Kruskal()
{
}

Grafo *Kruskal::kruskal(Grafo *g)
{
    Grafo *a = new Grafo("kruskal");
    copiaVerticeParaGrafo(g, a);
    // criando conjuntos disjuntos
    for (auto v : g->vertices())
    {
        makeSet(v);
    }

    // ordenando arestas em ordem não crescente
    std::vector<std::pair<Aresta *, int>> arestasOrdenadas = ordenaMapaCusto();

    // para cada aresta em ordem não crescente
    for (auto e : arestasOrdenadas)
    {
        Vertice *u = e.first->getU();
        Vertice *v = e.first->getV();

        // se u e v não pertencem ao mesmo conjunto
        if (findSet(u) != findSet(v))
        {
            Vertice *novoU = a->getV(u->getIdentificador());
            Vertice *novoV = a->getV(v->getIdentificador());

            Aresta *original = g->getA(u, v).front();
            std::string idAresta = original->getIdentificador();

            // cria aresta de u para v
            a->insereA(novoU, novoV, idAresta);
            // std::cout << *teste << "\n";
            // une os conjuntos de u e v
            unionSet(u, v);
        }
    }

    return a;
}

void Kruskal::setCustoAresta(Aresta *a, int custo)
{
    w[a] = custo;
}

void Kruskal::imprimeArvoreCustoMinimo(Grafo *a, Grafo *g)
{
    int total = 0;
    for (auto aresta : a->arestas())
    {
        // para obter o custo da aresta é preciso da aresta do grafo original "g"
        // pela forma como eu implementei o custo (pode ser melhorado)

        Vertice *u = aresta->getU();
        Vertice *v = aresta->getV();

        Vertice *velhoU = g->getV(u->getIdentificador());
        Vertice *velhoV = g->getV(v->getIdentificador());

        Aresta *original = g->getA(velhoU, velhoV).front();
        int custo = w[original];
        total += custo;
        std::cout << *aresta << " custo: " << custo << "\n";
    }

    std::cout << "custo total: " << total << "\n";
}

// ordena as aresta em ordem não crescente de custo ("decrescente")
std::vector<std::pair<Aresta *, int>> Kruskal::ordenaMapaCusto()
{
    // usaremos vetores pois já possuem métodos de ordenação

    // vector com o par igual ao do hashmap
    std::vector<std::pair<Aresta *, int>> listaMapa;

    // pega os pares aresta/custo e joga no vector
    for (auto &keyValue : w)
    {
        listaMapa.push_back(keyValue);
    }

    // ordena o vector
    std::sort(listaMapa.begin(), listaMapa.end(), compararCusto);

    return listaMapa;
}

void Kruskal::copiaVerticeParaGrafo(Grafo *g1, Grafo *g2)
{
    // cria vértices no grafo g2 com base no grafo g1
    for (auto v : g1->vertices())
    {
        g2->insereV(v->getIdentificador());
    }
}

bool Kruskal::compararCusto(std::pair<Aresta *, int> &a, std::pair<Aresta *, int> &b)
{
    // custo da primeira aresta é maior ou igual ao custo da segunda
    return a.second <= b.second;
}
