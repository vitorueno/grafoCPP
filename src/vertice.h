#ifndef __VERTICE_H__
#define __VERTICE_H__

#include <string>
#include <unordered_map>
#include <sstream>
#include <list>

#include "objetoIdentificado.h"

class Aresta;

class Vertice : public ObjetoIdentificado
{
public:
    std::unordered_map<Vertice *, std::list<Aresta *>> mapaAdjacencia;

    Vertice();
    Vertice(std::string identificador);
    ~Vertice();

    friend std::ostream &operator<<(std::ostream &os, const Vertice &v);
    std::string toString();
};

#endif