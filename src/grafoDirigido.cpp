#include "grafoDirigido.h"

GrafoDirigido::GrafoDirigido()
{
}

GrafoDirigido::GrafoDirigido(std::string identificador) : ObjetoIdentificado{identificador}
{
}

void GrafoDirigido::limpar()
{
    std::list<VerticeDirigido *>::iterator i;
    for (i = listaVertices.begin(); i != listaVertices.end(); i++)
    {
        delete *i;
    }

    for (auto &a : arestas())
    {
        delete a;
    }
}

GrafoDirigido::~GrafoDirigido()
{
    limpar();
}

VerticeDirigido *GrafoDirigido::insereV()
{
    VerticeDirigido *v = new VerticeDirigido();
    listaVertices.push_back(v);
    return v;
}

VerticeDirigido *GrafoDirigido::insereV(std::string identificador)
{
    VerticeDirigido *v = new VerticeDirigido(identificador);
    listaVertices.push_back(v);
    return v;
}

int GrafoDirigido::getOrdem()
{
    return listaVertices.size();
}

int GrafoDirigido::getTamanho()
{
    return arestas().size();
}

ArestaDirigida *GrafoDirigido::insereA(VerticeDirigido *u, VerticeDirigido *v)
{
    ArestaDirigida *a = new ArestaDirigida(u, v);

    u->mapaAdjacenciaS[v].push_back(a);
    v->mapaAdjacenciaE[u].push_back(a);

    return a;
}

ArestaDirigida *GrafoDirigido::insereA(VerticeDirigido *u, VerticeDirigido *v, std::string identificador)
{
    ArestaDirigida *a = new ArestaDirigida(u, v, identificador);
    u->mapaAdjacenciaS[v].push_back(a);
    v->mapaAdjacenciaE[u].push_back(a);
    return a;
}

std::list<ArestaDirigida *> GrafoDirigido::getA(VerticeDirigido *u, VerticeDirigido *v)
{
    if (u->mapaAdjacenciaS.find(v) != u->mapaAdjacenciaS.end())
    {
        return u->mapaAdjacenciaS.at(v);
    }

    std::list<ArestaDirigida *> vazia;
    return vazia;
}

int GrafoDirigido::grauE(VerticeDirigido *v)
{
    int grauE = 0;

    for (auto &keyValue : v->mapaAdjacenciaE)
    {
        std::list<ArestaDirigida *> arestas = keyValue.second;
        for (auto &a : arestas)
        {
            grauE++;
        }
    }

    return grauE;
}

int GrafoDirigido::grauS(VerticeDirigido *v)
{
    int grauS = 0;

    for (auto &keyValue : v->mapaAdjacenciaS)
    {
        std::list<ArestaDirigida *> arestas = keyValue.second;
        for (auto &a : arestas)
        {
            grauS++;
        }
    }

    return grauS;
}

VerticeDirigido *GrafoDirigido::oposto(VerticeDirigido *v, ArestaDirigida *e)
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

void GrafoDirigido::removeA(ArestaDirigida *e)
{
    // pegando a referência para os vértices da aresta
    VerticeDirigido *u = e->getU();
    VerticeDirigido *v = e->getV();

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
    if (v->mapaAdjacenciaE.find(u) != v->mapaAdjacenciaE.end())
    {
        v->mapaAdjacenciaE.at(u).remove(e);

        // se era a única aresta de u para v limpa os mapas
        if (v->mapaAdjacenciaE.at(u).empty())
        {
            v->mapaAdjacenciaE.erase(v);
        }
    }

    // setando as referências da aresta para null
    e->setU(nullptr);
    e->setV(nullptr);

    // apagando a aresta
    delete e;
}

void GrafoDirigido::removeV(VerticeDirigido *v)
{
    std::unordered_map<VerticeDirigido *, std::list<ArestaDirigida *>>
        mapaE = v->mapaAdjacenciaE;
    std::unordered_map<VerticeDirigido *, std::list<ArestaDirigida *>>
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

VerticeDirigido *GrafoDirigido::getV(std::string identificador)
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

std::ostream &operator<<(std::ostream &os, const GrafoDirigido &g)
{
    os << "GrafoDirigido <" << g.identificador << ">";
    return os;
}

std::string GrafoDirigido::toString()
{
    std::ostringstream ss;
    ss << identificador;
    return ss.str();
}

std::vector<VerticeDirigido *> GrafoDirigido::vertices()
{
    // copiando o conteúdo da lista para um vector
    std::vector<VerticeDirigido *> vertices;

    // evitando que o vector precise mover elementos da memória
    vertices.reserve(getOrdem());

    vertices = {std::begin(listaVertices), std::end(listaVertices)};

    return vertices;
}

std::vector<VerticeDirigido *> GrafoDirigido::adj(VerticeDirigido *v)
{
    // obs: em digrafo só é adjacente quando estiver no mapa de saída

    std::vector<VerticeDirigido *> vAdjacentes;

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

std::unordered_set<ArestaDirigida *> GrafoDirigido::arestas()
{
    std::unordered_set<ArestaDirigida *> todasArestas;

    for (auto &v : listaVertices) // para cada vértice v
    {
        for (auto &keyValue : v->mapaAdjacenciaS) // para cada adj de v
        {
            std::list<ArestaDirigida *> arestas = keyValue.second;
            for (auto &a : arestas) // adiciona cada aresta adjacente ao conjunto
            {
                todasArestas.insert(a);
            }
        }
    }

    return todasArestas;
}

std::unordered_set<ArestaDirigida *> GrafoDirigido::arestasE(VerticeDirigido *v)
{
    std::unordered_set<ArestaDirigida *> arestasE;

    for (auto &keyValue : v->mapaAdjacenciaE)
    {
        std::list<ArestaDirigida *> listaArestas = keyValue.second;
        for (auto &a : listaArestas)
        {
            arestasE.insert(a);
        }
    }

    return arestasE;
}

std::unordered_set<ArestaDirigida *> GrafoDirigido::arestasS(VerticeDirigido *v)
{
    std::unordered_set<ArestaDirigida *> arestasS;

    for (auto &keyValue : v->mapaAdjacenciaS)
    {
        std::list<ArestaDirigida *> listaArestas = keyValue.second;
        for (auto &a : listaArestas)
        {
            arestasS.insert(a);
        }
    }

    return arestasS;
}

std::pair<VerticeDirigido *, VerticeDirigido *> GrafoDirigido::verticesA(ArestaDirigida *e)
{
    // u = origem; e = destino
    return std::pair<VerticeDirigido *, VerticeDirigido *>(e->getU(), e->getV());
}