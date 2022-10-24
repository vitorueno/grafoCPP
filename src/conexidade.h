#ifndef __CONEXIDADE_H__
#define __CONEXIDADE_H__

#include "grafo.h"
#include "vertice.h"
#include "set.h"

class Conexidade : public Set
{
public:
    Conexidade();
    ~Conexidade();

    void compomenteConexo(Grafo *g);
    bool mesmoComponente(Vertice *u, Vertice *v);
};

#endif // __CONEXIDADE_H__