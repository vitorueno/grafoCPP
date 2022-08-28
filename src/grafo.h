#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <list>
#include <vector>
#include <unordered_set>
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
    std::string getIdentificador() const;        // retorna o identificador do grafo
    std::vector<Vertice *> vertices();           // retorna um iterator dos vértices
    Vertice *insereV();                          // insereVertice sem identificador
    Vertice *insereV(std::string identificador); // insereVertice com identificador
    int getOrdem();                              // retorna o número de vértices
    int getTamanho();                            // retorna o número de arestas
    Aresta *insereA(Vertice *u, Vertice *v);     // inserir aresta entre u e v
    Aresta *insereA(Vertice *u, Vertice *v,      // insere aresta entre u e v
                    std::string identificador);  // insere aresta com id entre u e v
    std::vector<Vertice *> adj(Vertice *v);      // vértices adjacentes ao vértice atual
    std::unordered_set<Aresta *> arestas();      // retorna todas as arestas do grafo
    std::unordered_set<Aresta *> arestasE();     // retorna todas as arestas de entrada do grafo
    std::unordered_set<Aresta *> arestasS();     // retorna todas as arestas de saída do grafo
    Aresta *getA(Vertice *u, Vertice *v);        // retorna o vértice entre u e v (ou null)
    int grau(Vertice *v);                        // retorna o grau do vértice v
    int grauE(Vertice *v);                       // retorna o grau do vértice v
    int grauS(Vertice *v);                       // retorna o grau do vértice v

    // métodos da minha implementação
    Vertice *getV(std::string identificador); // retorna o vértice com esse identificador
};

#endif