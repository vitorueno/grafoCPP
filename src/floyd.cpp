#include "floyd.h"

Floyd::Floyd()
{
    // infinito = std::numeric_limits<int>::max();
    infinito = 99999;
}

Floyd::~Floyd()
{
}

void Floyd::floyd(Grafo *g)
{
    std::vector<Vertice *> vert = g->vertices();
    tam = vert.size();
    int dAnt[tam][tam];
    Vertice *pAnt[tam][tam];
    int dAtual[tam][tam];
    Vertice *pAtual[tam][tam];

    // std::vector<std::vector<int>> dAnt;
    // std::vector<std::vector<Vertice *>> pAnt;
    // std::vector<std::vector<int>> dAtual;
    // std::vector<std::vector<Vertice *>> pAtual;

    // dAnt.reserve(tam);
    // pAnt.reserve(tam);
    // dAtual.reserve(tam);
    // pAtual.reserve(tam);

    int i = 0;
    int j = 0;

    for (auto u : vert)
    {
        j = 0;
        // dAnt[i].reserve(tam);
        // pAnt[i].reserve(tam);
        // dAtual[i].reserve(tam);
        // pAtual[i].reserve(tam);

        for (auto v : vert)
        {
            std::list<Aresta *> uv = g->getA(u, v);

            // preenchendo a matriz de custo
            if (u == v)
            {
                dAnt[i][j] = 0;
            }
            else if (!uv.empty())
            {
                dAnt[i][j] = uv.front()->getW();
            }
            else
            {
                dAnt[i][j] = infinito;
            }

            // preenchendo a matriz de predecessores
            if ((u != v) && (dAnt[i][j] < infinito))
            {
                pAnt[i][j] = v;
            }
            else
            {
                pAnt[i][j] = nullptr;
            }

            j++;
        }
        i++;
    }

    for (int coluna = 0; coluna < tam; coluna++)
    {
        for (int linha = 0; linha < tam; linha++)
        {
            int r = dAnt[linha][coluna];
            if (r == infinito)
            {
                std::cout << "∞ ";
            }
            else
            {
                std::cout << r << " ";
            }
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for (int coluna = 0; coluna < tam; coluna++)
    {
        for (int linha = 0; linha < tam; linha++)
        {
            Vertice *v = pAnt[linha][coluna];
            if (v == nullptr)
            {
                std::cout << "null ";
            }
            else
            {
                std::cout << v->getIdentificador() << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    for (int k = 0; k < tam; k++)
    {
        for (int j = 0; j < tam; j++)
        {
            for (int i = 0; i < tam; i++)
            {

                int soma = (dAnt[i][k] + dAnt[k][j]);
                if (soma < dAnt[i][j])
                {
                    dAtual[i][j] = soma;
                    pAtual[i][j] = pAnt[k][j];
                }
                else
                {
                    dAtual[i][j] = dAnt[i][j];
                    pAtual[i][j] = pAnt[i][j];
                }

                dAnt[i][k] = dAtual[i][k];
                dAnt[k][j] = dAtual[k][j];
                dAnt[i][j] = dAtual[i][j];
                pAnt[k][j] = pAtual[k][j];
                pAnt[i][j] = pAtual[i][j];
            }
        }
    }

    for (int coluna = 0; coluna < tam; coluna++)
    {
        for (int linha = 0; linha < tam; linha++)
        {
            int r = dAtual[linha][coluna];
            if (r == infinito)
            {
                std::cout << "∞ ";
            }
            else
            {
                std::cout << r << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    for (int coluna = 0; coluna < tam; coluna++)
    {
        for (int linha = 0; linha < tam; linha++)
        {
            Vertice *v = pAtual[coluna][linha];
            if (v == nullptr)
            {
                std::cout << "- ";
            }
            else
            {
                std::cout << v->getIdentificador() << " ";
            }
        }
        std::cout << "\n";
    }
}
