#ifndef __ARESTA_H__
#define __ARESTA_H__

#include <string>
#include "vertice.h"
#include <sstream>

#include "objetoIdentificado.h"

class Aresta : public ObjetoIdentificado
{
private:
    Vertice *u;
    Vertice *v;
    int w;

public:
    Aresta();
    Aresta(std::string identificador);
    Aresta(Vertice *u, Vertice *v);
    Aresta(Vertice *u, Vertice *v, std::string identificador);
    ~Aresta();

    Vertice *getU();
    Vertice *getV();
    int getW();

    void setU(Vertice *u);
    void setV(Vertice *v);
    void setW(int w);

    friend std::ostream &operator<<(std::ostream &os, const Aresta &a);
};

#endif