#ifndef __GRAFODIRIGIDO_H__
#define __GRAFODIRIGIDO_H__

#include <list>
#include <vector>
#include <unordered_set>
#include <string>
#include <utility>
#include "verticeDirigido.h"
#include "arestaDirigida.h"
#include <sstream>
#include <algorithm>

#include "objetoIdentificado.h"

class GrafoDirigido : public ObjetoIdentificado
{
private:
    std::list<VerticeDirigido *> listaVertices;

    void limpar(); // liberar recursos criados dinamicamente

public:
    GrafoDirigido();
    GrafoDirigido(std::string identificador);
    ~GrafoDirigido();

    // métodos do grafo
    std::vector<VerticeDirigido *> vertices();                         // retorna um iterator dos vértices
    VerticeDirigido *insereV();                                        // insereVerticeDirigido sem identificador
    VerticeDirigido *insereV(std::string identificador);               // insereVerticeDirigido com identificador
    int getOrdem();                                                    // retorna o número de vértices
    int getTamanho();                                                  // retorna o número de arestas
    ArestaDirigida *insereA(VerticeDirigido *u, VerticeDirigido *v);   // inserir aresta entre u e v
    ArestaDirigida *insereA(VerticeDirigido *u, VerticeDirigido *v,    // insere aresta entre u e v
                            std::string identificador);                // insere aresta com id entre u e v
    std::vector<VerticeDirigido *> adj(VerticeDirigido *v);            // vértices adjacentes ao vértice atual
    std::unordered_set<ArestaDirigida *> arestas();                    // retorna todas as arestas do grafo
    std::unordered_set<ArestaDirigida *> arestasE(VerticeDirigido *v); // retorna todas as arestas de entrada do grafo
    std::unordered_set<ArestaDirigida *> arestasS(VerticeDirigido *v); // retorna todas as arestas de saída do grafo
    ArestaDirigida *getA(VerticeDirigido *u, VerticeDirigido *v);      // retorna o vértice entre u e v (ou null)
    // int grau(VerticeDirigido *v);                                                 // retorna o grau do vértice v
    int grauE(VerticeDirigido *v);                                                // retorna o grau do vértice v
    int grauS(VerticeDirigido *v);                                                // retorna o grau do vértice v
    VerticeDirigido *oposto(VerticeDirigido *v, ArestaDirigida *e);               // retorna o vértice oposto a v na aresta e
    std::pair<VerticeDirigido *, VerticeDirigido *> verticesA(ArestaDirigida *e); // retorna o par de vértices conectados a aresta
    void removeA(ArestaDirigida *e);
    void removeV(VerticeDirigido *v);

    // métodos da minha implementação
    VerticeDirigido *getV(std::string identificador); // retorna o vértice com esse identificador
    friend std::ostream &operator<<(std::ostream &os, const GrafoDirigido &g);
    std::string toString();
};

#endif