#ifndef __BUSCAPROFUNDIDADE_H__
#define __BUSCAPROFUNDIDADE_H__

#include "grafoDirigido.h"
#include "verticeDirigido.h"
#include "arestaDirigida.h"

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

    std::unordered_map<VerticeDirigido *, Cor> cor;              // status do visitamento
    std::unordered_map<VerticeDirigido *, VerticeDirigido *> pi; // predecessor do vértice
    std::unordered_map<VerticeDirigido *, int> d;                // tempo de descoberta do vértice
    std::unordered_map<VerticeDirigido *, int> f;                // tempo de fechamento do vértice
    int tempo;

public:
    BuscaProfundidade();
    ~BuscaProfundidade();

    void DFS(GrafoDirigido *g);
    void DFS_visit(GrafoDirigido *g, VerticeDirigido *u);
    void mostraInformacao(GrafoDirigido *g);
    void imprimeCaminho(GrafoDirigido *g, VerticeDirigido *s, VerticeDirigido *v);
};

#endif