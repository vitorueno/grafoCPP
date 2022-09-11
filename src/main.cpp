#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

#include "vertice.h"
#include "grafo.h"
#include "aresta.h"
#include "grafoDirigido.h"
#include "verticeDirigido.h"
#include "arestaDirigida.h"

void testaGrafo()
{
    Grafo g("g1");
    cout << g << endl;

    // inserindo vértices
    Vertice *v1 = g.insereV("v1");
    Vertice *v2 = g.insereV("v2");
    Vertice *v3 = g.insereV("v3");

    vector<Vertice *> vertices = g.vertices();

    cout << "\npercorrendo todos os vértices\n";
    for (auto &v : vertices)
    {
        cout << *v << endl;
    }

    // inserindo arestas
    Aresta *a1 = g.insereA(v1, v2, "a1");
    Aresta *a2 = g.insereA(v1, v3, "a2");
    Aresta *a3 = g.insereA(v2, v3, "a3");
    // // Aresta *a4 = g.insereA(v1, v1, "a4 (v1, v1)");
    // // Aresta *a5 = g.insereA(v2, v2, "a5 (v2, v2)");
    // // Aresta *a6 = g.insereA(v1, v2, "a1 de novo (v1, v2)");

    vector<Vertice *> adjacentes = g.adj(v1);

    cout << "\nvértices adjacentes a v1:\n";
    for (auto &v : adjacentes)
    {
        cout << *v << endl;
    }

    cout << "\ntodas as arestas do grafo\n";
    unordered_set<Aresta *> arestas = g.arestas();

    for (auto &a : arestas)
    {
        cout << *a << endl;
    }

    cout << "\nnúmero de arestas:\n";
    cout << g.getTamanho() << endl;

    cout << "\nacessando a aresta a partir de dois vértices\n";
    Aresta *a = g.getA(v1, v2);
    cout << *a << endl;

    cout << "\nverificando o grau do vértice v1\n";
    cout << g.grau(v1) << endl;

    cout << "\npegar vértice oposto a um vértice em uma aresta\n";
    Vertice *oposto = g.oposto(v1, a1);

    if (oposto == v2)
    {
        cout << "conseguiu pegar o oposto!\n";
    }

    cout << "\npegar par de vértices de uma aresta\n";
    pair<Vertice *, Vertice *> parVertices = g.verticesA(a1);
    if (parVertices.first == v1 && parVertices.second == v2)
    {
        cout << "o par coincide com os vértices esperados\n";
    }

    // removendo uma aresta
    cout << "\nremovendo a aresta a1\n";

    g.removeA(a1);

    for (auto &a : g.arestas())
    {
        cout << *a << endl;
    }

    if (v1->mapaAdjacencia.find(v2) == v1->mapaAdjacencia.end())
    {
        cout << "v2 não é mais adjacente a v1\n";
    }

    // removendo um vértice
    cout << "\nremovendo o vértice v1\n";

    g.removeV(v1);

    for (auto &v : g.vertices())
    {
        cout << *v << endl;
    }

    for (auto &v : g.arestas())
    {
        cout << *v << endl;
    }
}

void testaDigrafo()
{
    GrafoDirigido dg("digrafo 1");
    cout << dg << endl;

    VerticeDirigido *v1 = dg.insereV("v1");
    VerticeDirigido *v2 = dg.insereV("v2");
    VerticeDirigido *v3 = dg.insereV("v3");

    ArestaDirigida *a1 = dg.insereA(v1, v2, "a1");
    ArestaDirigida *a2 = dg.insereA(v1, v3, "a2");
    ArestaDirigida *a3 = dg.insereA(v3, v1, "a3");

    cout << "\ntodos os vértices\n";
    for (auto &v : dg.vertices())
    {
        cout << *v << endl;
    }

    cout << "\narestas de entrada de v1\n";
    for (auto &a : dg.arestasE(v1))
    {
        cout << *a << endl;
    }

    cout << "\narestas de saída de v1\n";
    for (auto &a : dg.arestasS(v1))
    {
        cout << *a << endl;
    }

    cout << "\npercorrendo os adjacentes de v1\n";
    for (auto &v : dg.adj(v1))
    {
        cout << *v << endl;
    }

    ArestaDirigida *arestaUparaV = dg.getA(v1, v2);

    if (arestaUparaV == a1)
    {
        cout << "\nmétodo getA funcionou pois conseguiu pegar o a1\n";
    }

    cout << "\ngrau de entrada do v1: " << dg.grauE(v1) << endl;
    cout << "grau de saída do v1: " << dg.grauS(v1) << endl;

    pair<VerticeDirigido *, VerticeDirigido *> par = dg.verticesA(a1);
    if (par.first == v1 && par.second == v2)
    {
        cout << "\nfunção verticesA funcionou pois conseguiu pegar v1 e v2\n";
    }

    VerticeDirigido *oposto = dg.oposto(v1, a1);
    if (oposto == v2)
    {
        cout << "\nfunção oposto funcionou pois conseguiu pegar v2 a partir de v1 e a1\n";
    }

    cout << "\ntestando a remoção de aresta:\n";
    dg.removeA(a1);

    for (auto &a : dg.arestas())
    {
        cout << *a << endl;
    }

    cout << "\ntestando a remoção de vértice:\n";
    dg.removeV(v2);

    for (auto &v : dg.vertices())
    {
        cout << *v << endl;
    }

    for (auto &a : dg.arestas())
    {
        cout << *a << endl;
    }
}

int main(int argc, char *argv[])
{

    // testaGrafo();
    testaDigrafo();
    return 0;
}
