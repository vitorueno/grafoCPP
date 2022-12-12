#include "grafoDirigido.h"
#include "grafo.h"
#include "aresta.h"
#include "vertice.h"

#include <limits>
#include <vector>
#include <iostream>
#include <string>

#ifndef __FLOYD_H__
#define __FLOYD_H__

class Floyd
{
    // protected:
    // std::vector<std::vector<Vertice *>> piAnt;
    // std::vector<std::vector<Vertice *>> piAtual;

public:
    int infinito;

    // std::vector<std::vector<Vertice *>>
    //     piAnt;
    // std::vector<std::vector<Vertice *>> piAtual;

    // std::vector<std::vector<int>> dAnt;
    // std::vector<std::vector<int>> dAtual;
    int tam;
    Floyd();

    // Floyd(Grafo *g);
    ~Floyd();

    void floyd(Grafo *g); // algoritmo de floyd

    // inicializa matriz de adjacência e predecessor
    // void inicializaMatrizes(Grafo *g);
    // void imprimeCaminhoMinimo(int i, int j);
    // void imprimeTeste();
    // void imprimeResult();

    // void atualizaMatrizes();

    // std::vector<std::vector<Vertice *>> getPi();
    // std::vector<std::vector<int>> getPi();
    // std::vector<std::vector<int>> getD();
    // int getTam();
};

#endif