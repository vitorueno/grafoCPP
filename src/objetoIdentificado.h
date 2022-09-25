#ifndef __OBJETOIDENTIFICADO_H__
#define __OBJETOIDENTIFICADO_H__

#include <string>
#include <sstream>

class ObjetoIdentificado
{
protected:
    std::string identificador;

public:
    ObjetoIdentificado();
    ObjetoIdentificado(std::string identificador);
    ~ObjetoIdentificado();

    std::string getIdentificador();
    void setIdentificador(std::string identificador);

    std::string toString();
};

#endif // __OBJETOIDENTIFICADO_H__