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

std::vector<Aresta *> Grafo::getA(Vertice *u, Vertice *v)
{
    std::vector<Aresta *> arestas;
    if (u->mapaAdjacencia.find(v) != u->mapaAdjacencia.end())
    {
        arestas = {std::begin(u->mapaAdjacencia.at(v)), std::end(u->mapaAdjacencia.at(v))};
    }
    return arestas;
}

int Grafo::grau(Vertice *v)
{
    int grau = 0;

    for (auto &keyValue : v->mapaAdjacencia)
    {
        Vertice *u = keyValue.first;
        std::list<Aresta *> a = keyValue.second;

        if (u == v)
            grau += a.size() * 2;
        else
            grau += a.size();
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

void Grafo::removeA(Aresta *e)
{
    // pegando a referência para os vértices da aresta
    Vertice *v1 = e->getU();
    Vertice *v2 = e->getV();

    // variável para acesso do mapa de adjacência de cada vértice
    std::unordered_map<Vertice *, std::list<Aresta *>> map_v1 = v1->mapaAdjacencia;
    std::unordered_map<Vertice *, std::list<Aresta *>> map_v2 = v2->mapaAdjacencia;

    // removendo a aresta dos mapas dos vértices v1 e v2
    map_v1.at(v2).remove(e);
    map_v2.at(v1).remove(e);

    // se a lista fica vazia naquela posição, vamos apagar o registro no mapa
    if (map_v1.at(v2).empty())
    {
        map_v1.erase(v2);
    }

    if (map_v2.at(v1).empty())
    {
        map_v2.erase(v1);
    }

    // atribuindo null para as referências aos vértices da aresta
    e->setU(nullptr);
    e->setV(nullptr);

    // finalmente, apagando a aresta
    delete e;
}

void Grafo::removeV(Vertice *v)
{
    std::unordered_map<Vertice *, std::list<Aresta *>> mapa = v->mapaAdjacencia;

    // remover cada aresta ligada a v
    for (auto &keyValue : mapa)
    {
        std::list<Aresta *> arestas = keyValue.second;
        for (auto a : arestas)
        {
            removeA(a);
        }
    }

    // zerar mapa de adjacência do vértice
    mapa.erase(mapa.begin(), mapa.end());

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

std::string Grafo::toString()
{
    std::ostringstream ss;
    ss << identificador;
    return ss.str();
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
            std::list<Aresta *> arestasDoV = keyValue.second;
            for (auto a : arestasDoV)
            {
                arestas.insert(a);
            }
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