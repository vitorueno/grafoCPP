#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <list>
#include <string>
#include "vertice.h"

class Grafo
{
private:
    std::string identificador;
    std::list<Vertice> listaVertices;

public:
    Grafo();
    Grafo(std::string identificador);
    ~Grafo();

    // métodos do grafo
    std::string getIdentificador(); //
    // const std::list<Vertice> &vertices() const; // obter lista de vértices
    std::list<Vertice>::iterator vertices();
    void insereV();                          // insereVertice sem identificador
    void insereV(std::string identificador); // insereVertice com identificador
    int getOrdem();
};

#endif