#ifndef __CONEXIDADE_H__
#define __CONEXIDADE_H__

#include "grafo.h"
#include "vertice.h"

#include <unordered_map>

class Conexidade
{
public:
    std::unordered_map<Vertice *, Vertice *> p;
    std::unordered_map<Vertice *, int> rank;
    Conexidade();
    ~Conexidade();

    void compomenteConexo(Grafo *g);
    bool mesmoComponente(Vertice *u, Vertice *v);

    void makeSet(Vertice *x);
    void unionSet(Vertice *x, Vertice *y);
    void link(Vertice *x, Vertice *y);
    Vertice *findSet(Vertice *x);
};

#endif // __CONEXIDADE_H__