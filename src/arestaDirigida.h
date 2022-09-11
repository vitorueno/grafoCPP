#ifndef __ARESTADIRIGIDA_H__
#define __ARESTADIRIGIDA_H__

#include <string>
#include "verticeDirigido.h"
#include <sstream>

#include "objetoIdentificado.h"

class ArestaDirigida : public ObjetoIdentificado
{
private:
    VerticeDirigido *u;
    VerticeDirigido *v;

public:
    ArestaDirigida();
    ArestaDirigida(std::string identificador);
    ArestaDirigida(VerticeDirigido *u, VerticeDirigido *v);
    ArestaDirigida(VerticeDirigido *u, VerticeDirigido *v, std::string identificador);
    ~ArestaDirigida();

    VerticeDirigido *getU();
    VerticeDirigido *getV();

    void setU(VerticeDirigido *u);
    void setV(VerticeDirigido *v);

    friend std::ostream &operator<<(std::ostream &os, const ArestaDirigida &a);
    std::string toString();
};

#endif // __ARESTADIRIGIDA_H__