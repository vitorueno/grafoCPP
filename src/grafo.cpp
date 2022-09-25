#include "grafo.h"

Grafo::Grafo()
{
}

Grafo::Grafo(std::string identificador) : ObjetoIdentificado{identificador}
{
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

    u->mapaAdjacencia[v].push_back(a);
    v->mapaAdjacencia[u].push_back(a);
    return a;
}

Aresta *Grafo::insereA(Vertice *u, Vertice *v, std::string identificador)
{
    Aresta *a = new Aresta(u, v, identificador);
    u->mapaAdjacencia[v].push_back(a);
    v->mapaAdjacencia[u].push_back(a);
    return a;
}

std::list<Aresta *> Grafo::getA(Vertice *u, Vertice *v)
{
    if (u->mapaAdjacencia.find(v) != u->mapaAdjacencia.end())
    {
        return u->mapaAdjacencia.at(v);
    }
    std::list<Aresta *> vazia;
    return vazia;
}

int Grafo::grau(Vertice *v)
{
    int grau = 0;

    for (auto &keyValue : v->mapaAdjacencia) // para cada vértice adj do vértice v
    {
        std::list<Aresta *> arestas = keyValue.second; // arestas
        for (auto &a : arestas)
        {
            grau++;
        }
    }

    return grau;
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

void Grafo::removeA(Aresta *e)
{
    // pegando a referência para os vértices da aresta
    Vertice *v1 = e->getU();
    Vertice *v2 = e->getV();

    // removendo a aresta do mapa dos vértices
    v1->mapaAdjacencia.at(v2).remove(e);
    v2->mapaAdjacencia.at(v1).remove(e);

    // se a aresta era a única unindo v1 a v2, vou remover o registro do mapa
    // se v1 e v2 são iguais teremos um laço, então tentar remover duas vezes daria problema
    if (v1->mapaAdjacencia.at(v2).empty() && (v1 != v2))
        v1->mapaAdjacencia.erase(v2);

    if (v2->mapaAdjacencia.at(v1).empty())
        v2->mapaAdjacencia.erase(v1);

    // setando as referências da aresta para null
    e->setU(nullptr);
    e->setV(nullptr);

    // apagando a aresta
    delete e;
}

void Grafo::removeV(Vertice *v)
{
    std::unordered_map<Vertice *, std::list<Aresta *>> mapa = v->mapaAdjacencia;

    // remover cada aresta ligada a v
    for (auto &a : arestas(v))
    {
        removeA(a);
    }

    // zerar mapa de adjacência do vértice
    mapa.clear();
    // mapa.erase(mapa.begin(), mapa.end());

    // remover vértice da lista do grafo
    listaVertices.remove(v);

    // apagar vértice
    delete v;
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

std::ostream &operator<<(std::ostream &os, const Grafo &g)
{
    os << "Grafo <" << g.identificador << ">";
    return os;
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

    for (auto &v : listaVertices) // para cada vértice
    {
        for (auto &keyValue : v->mapaAdjacencia) // para cada vértice adj
        {
            std::list<Aresta *> listaAresta = keyValue.second; // pega lista de arestas
            for (auto &a : listaAresta)
            {
                arestas.insert(a);
            }
        }
    }

    return arestas;
}

std::unordered_set<Aresta *> Grafo::arestas(Vertice *v)
{
    std::unordered_set<Aresta *> arestas;

    for (auto &keyValue : v->mapaAdjacencia) // para cada vértice adj a
    {
        std::list<Aresta *> listaAresta = keyValue.second; // pega lista de arestas
        for (auto &a : listaAresta)
        {
            arestas.insert(a);
        }
    }

    return arestas;
}

std::pair<Vertice *, Vertice *> Grafo::verticesA(Aresta *e)
{
    return std::pair<Vertice *, Vertice *>(e->getU(), e->getV());
}