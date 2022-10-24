#ifndef __SET_H__
#define __SET_H__

#include <unordered_map>
#include "grafo.h"
#include "vertice.h"

class Set
{
protected:
    std::unordered_map<Vertice *, Vertice *> p;
    std::unordered_map<Vertice *, int> rank;

public:
    Set();
    ~Set();

    void makeSet(Vertice *x);
    void unionSet(Vertice *x, Vertice *y);
    void link(Vertice *x, Vertice *y);
    Vertice *findSet(Vertice *x);
};

#endif // __SET_H__