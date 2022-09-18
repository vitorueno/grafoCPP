#include "objetoIdentificado.h"

ObjetoIdentificado::ObjetoIdentificado()
{
}

ObjetoIdentificado::ObjetoIdentificado(std::string identificador)
    : identificador{identificador}
{
}

ObjetoIdentificado::~ObjetoIdentificado()
{
}

void ObjetoIdentificado::setIdentificador(std::string identificador)
{
    ObjetoIdentificado::identificador = identificador;
}

std::string ObjetoIdentificado::getIdentificador()
{
    return identificador;
}
