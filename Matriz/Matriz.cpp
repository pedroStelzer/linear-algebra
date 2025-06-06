#include <iostream>
#include "Matriz.h"

Matriz::Matriz(int linha, int coluna, vector<int> numeros)
{
    this->linhas = linha;
    this->colunas = coluna;

    int k = 0;

    for(int i = 0; i < linha; i++)
    {
        vector<int> temp;

        for(int j = 0; j < coluna; j++, k++)
        {
            temp.push_back(numeros[k]);
        }

        this->matriz.push_back(temp);
    }
};

Matriz::~Matriz() {};