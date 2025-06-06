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

void Matriz::imprimir()
{
    int linha = this->linhas;
    int coluna = this->colunas;

    int linha_mais_digitos = 0;

    // Contar quantidade de digitos de cada linha

    int digitos_linha[linha];
    int digitos_extras = 0;

    for(int i = 0; i < linha; i++)
    {
        digitos_linha[i] = 0;

        for(int j = 0; j < coluna; j++)
        {
            int numero = this->matriz[i][j];

            if(numero < 0) digitos_extras++;

            while(numero != 0)
            {
                numero /= 10;
                digitos_extras++;
            }
        }

        if(linha_mais_digitos < digitos_extras) linha_mais_digitos = digitos_extras;

        digitos_linha[i] = digitos_extras;
        digitos_extras = 0;
    }
    //------------------------------------//

    int espacos = coluna+linha_mais_digitos-1;

    cout << "__";

    for(int i = 0; i < espacos; i++) cout << " ";

    cout << "__" << endl;

    for(int i = 0; i < linha; i++)
    {
        cout << "| ";

        for(int j = 0; j < coluna; j++)
        {
            

            if(j < coluna-1)
            {
                cout << this->matriz[i][j] << " ";
            }
            else
            {
                cout << this->matriz[i][j];
                for(int k = 0; k < linha_mais_digitos - digitos_linha[i] + 1; k++) cout << " ";
            }
        }

        cout << "|";

        cout << endl;
    }

    cout << "‾‾";

    for(int i = 0; i < espacos; i++) cout << " ";

    cout << "‾‾" << endl;
};

Matriz* Matriz::somar(Matriz* matriz)
{
    vector<int> numeros;

    for(int i = 0; i < this->linhas; i++)
    {
        for(int j = 0; j < this->colunas; j++)
        {
            numeros.push_back(this->matriz[i][j] + matriz->matriz[i][j]);
        }
    }
    return new Matriz(this->linhas, this->colunas, numeros);
};