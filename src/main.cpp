#include <iostream>
#include <list>
using namespace std;

#include "vertice.h"

int main(int argc, char *argv[])
{
    Vertice v(10);
    list<int> l = {7, 5, 16, 8};

    l.push_back(16);

    // Print out the list
    cout << "l = { ";
    for (int n : l)
    {
        cout << n << ", ";
    }
    cout << "};\n";

    cout << v.x << "\n";
}
