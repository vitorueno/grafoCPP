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
    Aresta *a = new Aresta();
    u->mapaAdjacencia[v] = a;
    v->mapaAdjacencia[u] = a;
    return a;
}

Aresta *Grafo::insereA(Vertice *u, Vertice *v, std::string identificador)
{
    Aresta *a = new Aresta(identificador);
    u->mapaAdjacencia[v] = a;
    v->mapaAdjacencia[u] = a;
    return a;
}

Vertice *Grafo::getV(std::string identificador)
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

    vertices = {std::begin(listaVertices),
                std::end(listaVertices)};

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
