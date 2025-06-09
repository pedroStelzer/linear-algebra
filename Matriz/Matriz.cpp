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

Matriz* Matriz::subtrair(Matriz* matriz)
{
    vector<int> numeros;

    for(int i = 0; i < this->linhas; i++)
    {
        for(int j = 0; j < this->colunas; j++)
        {
            numeros.push_back(this->matriz[i][j] - matriz->matriz[i][j]);
        }
    }
    return new Matriz(this->linhas, this->colunas, numeros);
};

Matriz* Matriz::multiplicar(Matriz* matriz)
{
    vector<int> numeros;

    for(int i = 0; i < this->linhas; i++)
    {
        for(int j = 0; j < matriz->colunas; j++)
        {
            int resultado = 0;

            for(int k = 0; k < this->linhas; k++) resultado += this->matriz[i][k] * matriz->matriz[k][j];

            numeros.push_back(resultado);
        }
    }

    return new Matriz(this->linhas, matriz->colunas, numeros);
};

Matriz* Matriz::transposta()
{
    vector<int> numeros;

    int linhas = this->linhas;
    int colunas = this->colunas;

    for(int i = 0; i < colunas; i++)
        for(int j = 0; j < linhas; j++) 
            numeros.push_back(this->matriz[j][i]);

    return new Matriz(colunas, linhas, numeros);
}

bool Matriz::simetrica()
{
    int linhas = this->linhas;
    int colunas = this->colunas;

    if(colunas != linhas) return false;

    Matriz* transposta = this->transposta();

    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            if(transposta->matriz[i][j] != this->matriz[i][j]) return false;

    return true;
}

bool Matriz::anti_simetrica()
{
    int linhas = this->linhas;
    int colunas = this->colunas;

    if(colunas != linhas) return false;

    Matriz* matriz_anti_simetrica = this->somar(this->transposta());

    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            if(matriz_anti_simetrica->matriz[i][j] != 0) return false;
    
    return true;
}