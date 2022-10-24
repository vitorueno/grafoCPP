#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

#include "vertice.h"
#include "grafoNaoDirigido.h"
#include "aresta.h"
#include "grafoDirigido.h"

#include "buscaLargura.h"
#include "buscaProfundidade.h"
#include "conexidade.h"
#include "kruskal.h"

void testaGrafo()
{
    GrafoNaoDirigido g("g1");
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
    Aresta *a4 = g.insereA(v1, v2, "a4 (paralela)");
    Aresta *a5 = g.insereA(v1, v1, "a5 (laço)");

    cout << "\ntodas as arestas do grafo\n";
    unordered_set<Aresta *> arestas = g.arestas();

    for (auto &a : arestas)
    {
        cout << *a << endl;
    }

    // // Aresta *a4 = g.insereA(v1, v1, "a4 (v1, v1)");
    // // Aresta *a5 = g.insereA(v2, v2, "a5 (v2, v2)");
    // // Aresta *a6 = g.insereA(v1, v2, "a1 de novo (v1, v2)");

    vector<Vertice *> adjacentes = g.adj(v1);

    cout << "\nvértices adjacentes a v1:\n";
    for (auto &v : adjacentes)
    {
        cout << *v << endl;
    }

    cout << "\nnúmero de arestas: (espera-se 5)\n";
    cout << g.getTamanho() << endl;

    cout << "\nacessando a aresta a partir de dois vértices: v1 e v2\n";
    Aresta *a = g.getA(v1, v2).front();
    cout << *a << endl;

    cout << "\nverificando o grau do vértice v1 (espera-se 5)\n";
    cout << g.grau(v1) << endl;

    cout << "\npegar vértice oposto a um vértice em uma aresta: v1 e vértice a1 (espera-se v2)\n";
    Vertice *oposto = g.oposto(v1, a1);
    cout << *oposto << endl;

    cout << "\npegar par de vértices a partir de uma aresta: a1 (espera-se v1 e v2)\n";
    pair<Vertice *, Vertice *> parVertices = g.verticesA(a1);
    cout << *parVertices.first << "e " << *parVertices.second << endl;

    // removendo uma aresta
    cout << "\nremovendo a aresta a4. Arestas restantes: (espera-se a1, a2, a3, a5)\n";

    g.removeA(a4);

    for (auto &a : g.arestas())
    {
        cout << *a << endl;
    }

    // removendo um vértice
    cout << "\nremovendo o vértice v1. Vértices e arestas restantes: (espera-se não haver mais vértice v1)\n";

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

    Vertice *v1 = dg.insereV("v1");
    Vertice *v2 = dg.insereV("v2");
    Vertice *v3 = dg.insereV("v3");

    Aresta *a1 = dg.insereA(v1, v2, "a1");
    Aresta *a2 = dg.insereA(v1, v3, "a2");
    Aresta *a3 = dg.insereA(v3, v1, "a3");
    Aresta *a4 = dg.insereA(v1, v2, "a4 (paralela)");
    Aresta *a5 = dg.insereA(v1, v1, "a5 (laço)");
    // Aresta *a3 = dg.insereA(v3, v1, "a3");

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

    cout << "\nacessando a aresta a partir de dois vértices: v1 e v2 (espera-se a1)\n";
    Aresta *arestaUparaV = dg.getA(v1, v2).front();
    cout << *arestaUparaV << endl;

    cout << "\ngrau de entrada do v1 (espera-se 2): " << dg.grauE(v1) << endl;
    cout << "grau de saída do v1 (espera-se 4): " << dg.grauS(v1) << endl;

    cout << "\nacessando vértices a partir de uma aresta: a1 (espera-se v1 e v2) ";
    pair<Vertice *, Vertice *> par = dg.verticesA(a1);
    cout << *par.first << " e " << *par.second << endl;

    cout << "\nacessando vértice oposto a v1 na aresta a1 (espera-se v2)";
    Vertice *oposto = dg.oposto(v1, a1);
    cout << *oposto << endl;

    cout << "\nRemovendo a aresta a1. Arestas restantes: (espera-se a2, a3, a4, a5)\n";
    dg.removeA(a1);

    for (auto &a : dg.arestas())
    {
        cout << *a << endl;
    }

    cout << "\nRemovendo o vértice v1. Vértices e arestas restantes: (espera-se não haver mais v1)\n";
    dg.removeV(v1);

    for (auto &v : dg.vertices())
    {
        cout << *v << endl;
    }

    for (auto &a : dg.arestas())
    {
        cout << *a << endl;
    }
}

void testaBuscaLargura()
{
    GrafoNaoDirigido g("g");
    Vertice *s = g.insereV("s");
    Vertice *r = g.insereV("r");
    Vertice *v = g.insereV("v");
    Vertice *w = g.insereV("w");
    Vertice *t = g.insereV("t");
    Vertice *u = g.insereV("u");
    Vertice *x = g.insereV("x");
    Vertice *y = g.insereV("y");

    g.insereA(s, r, "a1");
    g.insereA(s, w, "a2");
    g.insereA(r, v, "a3");
    g.insereA(w, t, "a4");
    g.insereA(w, x, "a5");
    g.insereA(t, x, "a6");
    g.insereA(t, u, "a7");
    g.insereA(x, u, "a8");
    g.insereA(x, y, "a9");
    g.insereA(y, u, "a10");

    cout << "=============================busca em largura=============================\n";
    BuscaLargura b;
    b.BFS(&g, s);

    cout << "\ncaminho de s para u:\n";
    b.imprimeCaminho(&g, s, u);

    cout << "\ncaminho de s para y:\n";
    b.imprimeCaminho(&g, s, y);

    b.BFS(&g, v);

    cout << "\ncaminho de v para y:\n";
    b.imprimeCaminho(&g, v, y);
}

void testaBuscaProfundidade()
{
    GrafoDirigido g("g");
    Vertice *u = g.insereV("u");
    Vertice *v = g.insereV("v");
    Vertice *x = g.insereV("x");
    Vertice *y = g.insereV("y");
    Vertice *w = g.insereV("w");
    Vertice *z = g.insereV("z");

    g.insereA(u, v, "a1");
    g.insereA(u, x, "a2");
    g.insereA(v, y, "a3");
    g.insereA(y, x, "a4");
    g.insereA(x, v, "a5");
    g.insereA(w, y, "a6");
    g.insereA(w, z, "a7");
    g.insereA(z, z, "a8");

    cout << "=============================busca em profundidade=============================\n";
    BuscaProfundidade b;
    b.DFS(&g);

    b.mostraInformacao(&g);
}

void testaConexidade()
{
    Grafo gr("conexidade");
    Vertice *a = gr.insereV("a");
    Vertice *b = gr.insereV("b");
    Vertice *c = gr.insereV("c");
    Vertice *d = gr.insereV("d");

    Vertice *e = gr.insereV("e");
    Vertice *f = gr.insereV("f");
    Vertice *g = gr.insereV("g");

    Vertice *h = gr.insereV("h");
    Vertice *i = gr.insereV("i");
    Vertice *j = gr.insereV("j");

    gr.insereA(a, b);
    gr.insereA(a, c);
    gr.insereA(b, c);
    gr.insereA(b, d);

    gr.insereA(e, f);
    gr.insereA(e, g);

    gr.insereA(h, i);

    Conexidade con;

    con.compomenteConexo(&gr);

    if (con.mesmoComponente(a, b) && con.mesmoComponente(a, c) &&
        con.mesmoComponente(a, d))
    {
        cout << "a, b, c e d pertencem à mesma componente\n";
    }

    if (con.mesmoComponente(e, f) && con.mesmoComponente(e, g))
    {
        cout << "e, f e g pertencem à mesma componente\n";
    }

    if (con.mesmoComponente(h, i))
    {
        cout << "h e i pertencem à mesma componente\n";
    }

    if (!con.mesmoComponente(h, j))
    {
        cout << "h e j não pertecem à mesma componente conexa\n";
    }
}

void testaKruskal()
{
    Grafo gr("kruskal");
    Vertice *a = gr.insereV("a");
    Vertice *b = gr.insereV("b");
    Vertice *c = gr.insereV("c");
    Vertice *d = gr.insereV("d");
    Vertice *e = gr.insereV("e");
    Vertice *f = gr.insereV("f");
    Vertice *g = gr.insereV("g");
    Vertice *h = gr.insereV("h");
    Vertice *i = gr.insereV("i");

    Aresta *ab = gr.insereA(a, b);
    Aresta *ah = gr.insereA(a, h);
    Aresta *bc = gr.insereA(b, c);
    Aresta *bh = gr.insereA(b, h);
    Aresta *cd = gr.insereA(c, d);
    Aresta *ci = gr.insereA(c, i);
    Aresta *cf = gr.insereA(c, f);
    Aresta *de = gr.insereA(d, e);
    Aresta *df = gr.insereA(d, f);
    Aresta *ef = gr.insereA(e, f);
    Aresta *fg = gr.insereA(f, g);
    Aresta *ig = gr.insereA(i, g);
    Aresta *gh = gr.insereA(g, h);
    Aresta *hi = gr.insereA(h, i);

    Kruskal k;
    k.setCustoAresta(ab, 4);
    k.setCustoAresta(ah, 8);
    k.setCustoAresta(bc, 8);
    k.setCustoAresta(bh, 11);
    k.setCustoAresta(cd, 7);
    k.setCustoAresta(ci, 2);
    k.setCustoAresta(cf, 4);
    k.setCustoAresta(de, 9);
    k.setCustoAresta(df, 14);
    k.setCustoAresta(ef, 10);
    k.setCustoAresta(fg, 2);
    k.setCustoAresta(gh, 1);
    k.setCustoAresta(ig, 6);
    k.setCustoAresta(hi, 7);

    k.kruskal(&gr);
}

int main(int argc, char *argv[])
{
    // cout << "===========================teste do grafo não dirigido===========================\n";
    // testaGrafo();

    // cout << "\n===========================teste do grafo dirigido===========================\n";
    // testaDigrafo();

    // testaBuscaLargura();
    // testaBuscaProfundidade();

    // testaConexidade();

    testaKruskal();
    return 0;
}
