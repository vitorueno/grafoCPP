#ifndef __GRAFODIRIGIDO_H__
#define __GRAFODIRIGIDO_H__

#include "grafo.h"

class GrafoDirigido : public Grafo
{
public:
    GrafoDirigido();
    GrafoDirigido(std::string identificador);
    ~GrafoDirigido();

    // métodos do grafo
    Aresta *insereA(Vertice *u, Vertice *v);           // inserir aresta entre u e v
    Aresta *insereA(Vertice *u, Vertice *v,            // insere aresta entre u e v
                    std::string identificador);        // insere aresta com id entre u e v
    std::vector<Vertice *> adj(Vertice *v);            // vértices adjacentes ao vértice atual
    std::unordered_set<Aresta *> arestas();            // retorna todas as arestas do grafo
    std::unordered_set<Aresta *> arestasE(Vertice *v); // retorna todas as arestas de entrada do grafo
    std::unordered_set<Aresta *> arestasS(Vertice *v); // retorna todas as arestas de saída do grafo
    std::list<Aresta *> getA(Vertice *u, Vertice *v);  // retorna o vértice entre u e v (ou null)
    int grauE(Vertice *v);                             // retorna o grau do vértice v
    int grauS(Vertice *v);                             // retorna o grau do vértice v
    void removeA(Aresta *e);
    void removeV(Vertice *v);
};

#endif