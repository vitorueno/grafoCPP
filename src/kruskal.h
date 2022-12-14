#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__

#include "set.h"
#include "grafo.h"
#include "aresta.h"
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

#include <iostream>

class Kruskal : public Set
{
protected:
    std::map<Aresta *, int> w;
    void copiaVerticeParaGrafo(Grafo *g1, Grafo *g2);
    std::vector<std::pair<Aresta *, int>> ordenaMapaCusto();
    static bool compararCusto(std::pair<Aresta *, int> &a, std::pair<Aresta *, int> &b);

public:
    Kruskal();
    ~Kruskal();

    Grafo *kruskal(Grafo *g);

    void setCustoArestas(Grafo *g);

    // std::vector<int> getVectorCusto();

    void imprimeArvoreCustoMinimo(Grafo *a, Grafo *g);
};

#endif // __KRUSKAL_H__