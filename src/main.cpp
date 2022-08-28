#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "vertice.h"
#include "grafo.h"
#include "aresta.h"

int main(int argc, char *argv[])
{
    Grafo g("g1");

    cout << g.getIdentificador() << endl;

    Vertice *v1 = g.insereV("v1");
    Vertice *v2 = g.insereV("v2");
    Vertice *v3 = g.insereV("v3");

    list<Vertice *>::const_iterator it = g.vertices();

    for (int i = 0; i < g.getOrdem(); i++)
    {
        cout << (*it)->getIdentificador() << endl;
        it++;
    }

    Aresta *a1 = g.insereA(v1, v2, "a1");

    Aresta *recPeloV1 = v1->mapaAdjacencia[v2];
    Aresta *recPeloV2 = v2->mapaAdjacencia[v1];

    if ((a1 == recPeloV1) && (a1 == recPeloV2))
    {
        cout << "endereços apontam para o mesmo objeto\n";
    }

    // cout << recPeloV2->getIdentificador() << endl;
    // cout << a1->getIdentificador() << endl;
}
