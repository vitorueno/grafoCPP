#include "grafoDirigido.h"

GrafoDirigido::GrafoDirigido()
{
}

GrafoDirigido::GrafoDirigido(std::string identificador)
    : Grafo{identificador}
{
}

GrafoDirigido::~GrafoDirigido()
{
    // limpar();
}

Aresta *GrafoDirigido::insereA(Vertice *u, Vertice *v)
{
    Aresta *a = new Aresta(u, v);

    u->mapaAdjacenciaS[v].push_back(a);
    v->mapaAdjacencia[u].push_back(a);

    return a;
}

Aresta *GrafoDirigido::insereA(Vertice *u, Vertice *v, std::string identificador)
{
    Aresta *a = new Aresta(u, v, identificador);
    u->mapaAdjacenciaS[v].push_back(a);
    v->mapaAdjacencia[u].push_back(a);
    return a;
}

std::list<Aresta *> GrafoDirigido::getA(Vertice *u, Vertice *v)
{
    if (u->mapaAdjacenciaS.find(v) != u->mapaAdjacenciaS.end())
    {
        return u->mapaAdjacenciaS.at(v);
    }

    std::list<Aresta *> vazia;
    return vazia;
}

int GrafoDirigido::grauE(Vertice *v)
{
    int grauE = 0;

    for (auto &keyValue : v->mapaAdjacencia)
    {
        std::list<Aresta *> arestas = keyValue.second;
        for (auto &a : arestas)
        {
            grauE++;
        }
    }

    return grauE;
}

int GrafoDirigido::grauS(Vertice *v)
{
    int grauS = 0;

    for (auto &keyValue : v->mapaAdjacenciaS)
    {
        std::list<Aresta *> arestas = keyValue.second;
        for (auto &a : arestas)
        {
            grauS++;
        }
    }

    return grauS;
}

void GrafoDirigido::removeA(Aresta *e)
{
    // pegando a referência para os vértices da aresta
    Vertice *u = e->getU();
    Vertice *v = e->getV();

    // remove a aresta da lista de arestas dentro dos respectivos mapas
    if (u->mapaAdjacenciaS.find(v) != u->mapaAdjacenciaS.end())
    {
        u->mapaAdjacenciaS.at(v).remove(e);

        // se era a única aresta de u para v limpa os mapas
        if (u->mapaAdjacenciaS.at(v).empty())
        {
            u->mapaAdjacenciaS.erase(v);
        }
    }
    if (v->mapaAdjacencia.find(u) != v->mapaAdjacencia.end())
    {
        v->mapaAdjacencia.at(u).remove(e);

        // se era a única aresta de u para v limpa os mapas
        if (v->mapaAdjacencia.at(u).empty())
        {
            v->mapaAdjacencia.erase(v);
        }
    }

    // setando as referências da aresta para null
    e->setU(nullptr);
    e->setV(nullptr);

    // apagando a aresta
    delete e;
}

void GrafoDirigido::removeV(Vertice *v)
{
    std::unordered_map<Vertice *, std::list<Aresta *>>
        mapaE = v->mapaAdjacencia;
    std::unordered_map<Vertice *, std::list<Aresta *>>
        mapaS = v->mapaAdjacenciaS;

    // remover cada aresta que entra em v
    for (auto &aE : arestasE(v))
    {
        removeA(aE);
    }

    // remover cada aresta que sai de v
    for (auto &aS : arestasS(v))
    {
        // if (aS->getU() != aS->getV())
        removeA(aS);
    }

    // zerar mapa de adjacência do vértice
    mapaE.clear();
    mapaS.clear();

    // remover vértice da lista do grafo
    listaVertices.remove(v);

    // apagar vértice
    delete v;
}

std::vector<Vertice *> GrafoDirigido::adj(Vertice *v)
{
    // obs: em digrafo só é adjacente quando estiver no mapa de saída

    std::vector<Vertice *> vAdjacentes;

    // reservando tamanho previamente para evitar que sejam movidos
    vAdjacentes.reserve(v->mapaAdjacenciaS.size());

    // (key, value) = (vértice adjacente u, aresta que liga u e v)
    for (auto &keyValue : v->mapaAdjacenciaS)
    {
        auto &u = keyValue.first;
        vAdjacentes.push_back(u);
    }

    return vAdjacentes;
}

std::unordered_set<Aresta *> GrafoDirigido::arestas()
{
    std::unordered_set<Aresta *> todasArestas;

    for (auto &v : listaVertices) // para cada vértice v
    {
        for (auto &keyValue : v->mapaAdjacenciaS) // para cada adj de v
        {
            std::list<Aresta *> arestas = keyValue.second;
            for (auto &a : arestas) // adiciona cada aresta adjacente ao conjunto
            {
                todasArestas.insert(a);
            }
        }
    }

    return todasArestas;
}

std::unordered_set<Aresta *> GrafoDirigido::arestasE(Vertice *v)
{
    std::unordered_set<Aresta *> arestasE;

    for (auto &keyValue : v->mapaAdjacencia)
    {
        std::list<Aresta *> listaArestas = keyValue.second;
        for (auto &a : listaArestas)
        {
            arestasE.insert(a);
        }
    }

    return arestasE;
}

std::unordered_set<Aresta *> GrafoDirigido::arestasS(Vertice *v)
{
    std::unordered_set<Aresta *> arestasS;

    for (auto &keyValue : v->mapaAdjacenciaS)
    {
        std::list<Aresta *> listaArestas = keyValue.second;
        for (auto &a : listaArestas)
        {
            arestasS.insert(a);
        }
    }

    return arestasS;
}
