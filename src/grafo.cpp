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

    for (auto &a : arestas())
    {
        delete a;
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

int Grafo::getTamanho()
{
    return arestas().size();
}

Aresta *Grafo::insereA(Vertice *u, Vertice *v)
{
    Aresta *a = new Aresta(u, v);
    u->mapaAdjacencia[v] = a;
    v->mapaAdjacencia[u] = a;
    return a;
}

Aresta *Grafo::insereA(Vertice *u, Vertice *v, std::string identificador)
{
    Aresta *a = new Aresta(u, v, identificador);
    u->mapaAdjacencia[v] = a;
    v->mapaAdjacencia[u] = a;
    return a;
}

Aresta *Grafo::getA(Vertice *u, Vertice *v)
{
    if (u->mapaAdjacencia.find(v) != u->mapaAdjacencia.end())
    {
        return u->mapaAdjacencia.at(v);
    }
    return nullptr;
}

int Grafo::grau(Vertice *v)
{
    int grau = 0;

    for (auto &keyValue : v->mapaAdjacencia)
    {
        Vertice *u = keyValue.first;

        if (u == v)
            grau += 2;
        else
            grau++;
    }
    return grau;
}

int Grafo::grauE(Vertice *v)
{
    return grau(v);
}

int Grafo::grauS(Vertice *v)
{
    return grau(v);
}

Vertice *Grafo::oposto(Vertice *v, Aresta *e)
{
    // se eu pudesse garantir que v pertence a aresta e:
    // return (e->getU() == v) ? e->getV() : e->getU();
    // mas vai que passam um v errado de sacanagem

    if (v == e->getV())
    {
        return e->getU();
    }

    if (v == e->getU())
    {
        return e->getV();
    }

    return nullptr;
}

Vertice *
Grafo::getV(std::string identificador)
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

std::vector<Vertice *> Grafo::vertices()
{
    // copiando o conteúdo da lista para um vector
    std::vector<Vertice *> vertices;

    // evitando que o vector precise mover elementos da memória
    vertices.reserve(getOrdem());

    vertices = {std::begin(listaVertices), std::end(listaVertices)};

    return vertices;
}

std::vector<Vertice *> Grafo::adj(Vertice *v)
{
    std::vector<Vertice *> vAdjacentes;

    // reservando tamanho previamente para evitar que sejam movidos
    vAdjacentes.reserve(v->mapaAdjacencia.size());

    // (key, value) = (vértice adjacente u, aresta que liga u e v)
    for (auto &keyValue : v->mapaAdjacencia)
    {
        auto &u = keyValue.first;
        vAdjacentes.push_back(u);
    }

    return vAdjacentes;
}

std::unordered_set<Aresta *> Grafo::arestas()
{
    std::unordered_set<Aresta *> arestas;

    for (auto &v : listaVertices)
    {
        for (auto &keyValue : v->mapaAdjacencia)
        {
            Aresta *a = keyValue.second;
            arestas.insert(a);
        }
    }

    return arestas;
}

std::unordered_set<Aresta *> Grafo::arestasE()
{
    return arestas();
}

std::unordered_set<Aresta *> Grafo::arestasS()
{
    return arestas();
}

std::pair<Vertice *, Vertice *> Grafo::verticesA(Aresta *e)
{
    return std::pair<Vertice *, Vertice *>(e->getU(), e->getV());
}