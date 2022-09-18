#ifndef __VERTICEDIRIGIDO_H__
#define __VERTICEDIRIGIDO_H__

#include <string>
#include <unordered_map>
#include <sstream>
#include <list>

#include "objetoIdentificado.h"

class ArestaDirigida;

class VerticeDirigido : public ObjetoIdentificado
{
public:
    std::unordered_map<VerticeDirigido *, std::list<ArestaDirigida *>> mapaAdjacenciaE;
    std::unordered_map<VerticeDirigido *, std::list<ArestaDirigida *>> mapaAdjacenciaS;

    VerticeDirigido();
    VerticeDirigido(std::string identificador);
    ~VerticeDirigido();

    friend std::ostream &operator<<(std::ostream &os, const VerticeDirigido &v);
    std::string toString();
};

#endif