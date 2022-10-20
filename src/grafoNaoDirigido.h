#ifndef __GRAFONAODIRIGIDO_H__
#define __GRAFONAODIRIGIDO_H__

#include "grafo.h"

class GrafoNaoDirigido : public Grafo
{
public:
    GrafoNaoDirigido();
    GrafoNaoDirigido(std::string identificador);
    ~GrafoNaoDirigido();

    // métodos do grafo não dirigido
    int grau(Vertice *v); // retorna o grau do vértice v
};

#endif // __GRAFONAODIRIGIDO_H__