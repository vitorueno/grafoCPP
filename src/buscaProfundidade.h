#ifndef __BUSCAPROFUNDIDADE_H__
#define __BUSCAPROFUNDIDADE_H__

#include "grafo.h"
#include "vertice.h"
#include <limits>
#include <unordered_map>
#include <string>
#include <iostream>

class BuscaProfundidade
{
protected:
    enum Cor
    {
        branco,
        cinza,
        preto
    };

    std::unordered_map<Vertice *, Cor> cor;      // status do visitamento
    std::unordered_map<Vertice *, Vertice *> pi; // predecessor do vértice
    std::unordered_map<Vertice *, int> d;        // tempo de descoberta do vértice
    std::unordered_map<Vertice *, int> f;        // tempo de fechamento do vértice
    int tempo;

public:
    BuscaProfundidade();
    ~BuscaProfundidade();

    void DFS(Grafo *g);
    void DFS_visit(Grafo *g, Vertice *u);
    void mostraInformacao(Grafo *g);
    void imprimeCaminho(Grafo *g, Vertice *s, Vertice *v);
};

#endif