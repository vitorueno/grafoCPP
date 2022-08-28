#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

#include "vertice.h"
#include "grafo.h"
#include "aresta.h"

int main(int argc, char *argv[])
{
    Grafo g("g1");

    cout << g.getIdentificador() << endl;

    // inserindo vértices
    Vertice *v1 = g.insereV("v1");
    Vertice *v2 = g.insereV("v2");
    Vertice *v3 = g.insereV("v3");

    vector<Vertice *> vertices = g.vertices();

    cout << "\npercorrendo todos os vértices\n";
    for (auto &v : vertices)
    {
        cout << v->getIdentificador() << endl;
    }

    // inserindo arestas
    Aresta *a1 = g.insereA(v1, v2, "a1 (v1, v2)");
    Aresta *a2 = g.insereA(v1, v3, "a2 (v1, v3)");
    Aresta *a3 = g.insereA(v2, v3, "a3 (v2, v3)");
    Aresta *a4 = g.insereA(v1, v1, "a4 (v1, v1)");
    Aresta *a5 = g.insereA(v2, v2, "a5 (v2, v2)");

    vector<Vertice *> adjacentes = g.adj(v1);

    cout << "\nvértices adjacentes a v1:\n";
    for (auto &v : adjacentes)
    {
        cout << v->getIdentificador() << endl;
    }

    cout << "\ntodas as arestas do grafo\n";
    unordered_set<Aresta *> arestas = g.arestas();

    for (auto &a : arestas)
    {
        cout << a->getIdentificador() << endl;
    }

    cout << "\nnúmero de arestas:\n";
    cout << g.getTamanho() << endl;

    return 0;
}
