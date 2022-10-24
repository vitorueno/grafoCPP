#include "set.h"

Set::Set()
{
}

Set::~Set()
{
}

void Set::makeSet(Vertice *x)
{
    p[x] = x;
    rank[x] = 0;
}

void Set::unionSet(Vertice *x, Vertice *y)
{
    link(findSet(x), findSet(y));
}

void Set::link(Vertice *x, Vertice *y)
{
    if (rank[x] > rank[y])
    {
        p[y] = x;
    }
    else
    {
        p[x] = y;
    }
    if (rank[x] == rank[y])
    {
        rank[y] = rank[y] + 1;
    }
}

Vertice *Set::findSet(Vertice *x)
{
    if (x != p[x])
    {
        p[x] = findSet(p[x]);
    }
    return p[x];
}