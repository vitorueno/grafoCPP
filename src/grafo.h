#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <list>
#include <string>
#include "vertice.h"
#include "aresta.h"

class Grafo
{
private:
    std::string identificador;
    std::list<Vertice *> listaVertices;

    void limpar(); // liberar recursos criados dinamicamente

public:
    Grafo();
    Grafo(std::string identificador);
    ~Grafo();

    // métodos do grafo
    std::string getIdentificador() const;            // retorna o identificador do grafo
    std::list<Vertice *>::const_iterator vertices(); // retorna um iterator dos vértices
    Vertice *insereV();                              // insereVertice sem identificador
    Vertice *insereV(std::string identificador);     // insereVertice com identificador
    int getOrdem();                                  // devolve o número de vértices
    Aresta *insereA(Vertice *u, Vertice *v);         // inserir aresta entre u e v
    Aresta *insereA(Vertice *u, Vertice *v,          // insere aresta entre u e v
                    std::string identificador);      // insere aresta com id entre u e v

    // métodos da minha implementação
    Vertice *getV(std::string identificador); // retorna o vértice com esse identificador
};

#endif