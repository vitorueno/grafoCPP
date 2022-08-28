#ifndef __VERTICE_H__
#define __VERTICE_H__

#include <string>
#include <unordered_map>
#include "aresta.h"

class Vertice
{
private:
    std::string identificador;
    // std::unordered_map<Vertice *, Aresta *> mapaAdjacencia;

public:
    Vertice();
    Vertice(std::string identificador);
    ~Vertice();

    std::string getIdentificador();
};

#endif