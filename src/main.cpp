#include <iostream>
// #include <stdlib.h>
#include <list>
#include <string>

using namespace std;

#include "vertice.h"
#include "grafo.h"

int main(int argc, char *argv[])
{
    Grafo g("g1");

    cout << g.getIdentificador() << endl;

    g.insereV("v1");
    g.insereV("v2");
    g.insereV("v3");

    list<Vertice>::iterator it = g.vertices();

    for (int i = 0; i < g.getOrdem(); i++)
    {
        cout << it->getIdentificador() << endl;
        it++;
    }
}
