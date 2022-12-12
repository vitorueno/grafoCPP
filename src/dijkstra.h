#include "grafo.h"
#include "grafoNaoDirigido.h"
#include "vertice.h"
#include "aresta.h"
#include <unordered_set>
#include <queue>
#include <list>

#include <map>

#include <iostream>

#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

class Dijkstra
{
public:
    std::map<Vertice *, int> d;
    std::map<Vertice *, Vertice *> p;
    int infinito;
    std::list<Vertice *> q;

    Dijkstra();
    ~Dijkstra();

    Vertice *remove_minimo();
    void inicializaFila(GrafoNaoDirigido *g);
    bool pertenceAFila(Vertice *v);

    void dijkstra(GrafoNaoDirigido *g, Vertice *s);
};

#endif // __DIJKSTRA_H__