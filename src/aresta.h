#ifndef __ARESTA_H__
#define __ARESTA_H__

#include <string>
#include "vertice.h"
#include <sstream>

class Aresta
{
private:
    std::string identificador;
    Vertice *u;
    Vertice *v;

public:
    Aresta();
    Aresta(std::string identificador);
    Aresta(Vertice *u, Vertice *v);
    Aresta(Vertice *u, Vertice *v, std::string identificador);
    ~Aresta();

    std::string getIdentificador();
    Vertice *getU();
    Vertice *getV();

    void setIdentificador(std::string identificador);
    void setU(Vertice *u);
    void setV(Vertice *v);

    friend std::ostream &operator<<(std::ostream &os, const Aresta &a);
    std::string toString();
};

#endif