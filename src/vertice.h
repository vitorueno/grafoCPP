#ifndef __VERTICE_H__
#define __VERTICE_H__

#include <string>
#include <unordered_map>
#include <sstream>
#include <list>

class Aresta;

class Vertice
{
private:
    std::string identificador;

public:
    std::unordered_map<Vertice *, std::list<Aresta *>> mapaAdjacencia;

    Vertice();
    Vertice(std::string identificador);
    ~Vertice();

    std::string getIdentificador() const;
    friend std::ostream &operator<<(std::ostream &os, const Vertice &v);
    std::string toString();
};

#endif