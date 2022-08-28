#ifndef __ARESTA_H__
#define __ARESTA_H__

#include <string>

class Aresta
{
private:
    std::string identificador;

public:
    Aresta();
    Aresta(std::string identificador);
    ~Aresta();

    std::string getIdentificador() const;
};

#endif