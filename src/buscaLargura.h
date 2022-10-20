#ifndef __BUSCALARGURA_H__
#define __BUSCALARGURA_H__

#include "grafo.h"
#include "grafoDirigido.h"
#include "aresta.h"
#include "vertice.h"

#include <limits>
#include <queue>
#include <unordered_map>
#include <string>
#include <iostream>

class BuscaLargura
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
    std::unordered_map<Vertice *, int> d;        // distância em relação ao inicial
    std::queue<Vertice *> q;                     // fila de vértices (controle)

public:
    BuscaLargura();
    ~BuscaLargura();

    void imprimeCaminho(Grafo *g, Vertice *s, Vertice *v);
    void BFS(Grafo *g, Vertice *s);
    void BFS(GrafoDirigido *g, Vertice *s);
};

#endif // __BUSCALARGURA_H__