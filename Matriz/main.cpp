#include <iostream>
#include <windows.h>
#include "Matriz.h"

void criar(vector<Matriz*>& matrizes);

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    vector<Matriz*> matrizes;

    bool parou = false;

    while(!parou)
    {
        int op = 0;

        cout << "O que você deseja fazer?" << endl << endl;
        cout << "1. Criar uma matriz" << endl;
        cout << "0. Sair" << endl;

        cin >> op;


        switch(op)
        {
            case 0:
                parou = true;
                break;

            case 1:
                criar(matrizes);
                if(!matrizes.empty())
                    matrizes.back()->imprimir();
                break;
            
            default:
                break;
        }
    }

    for (auto m : matrizes) delete m;

    return 0;
}

void criar(vector<Matriz*>& matrizes)
{
    int linhas = 0;
    int colunas = 0;
    vector<int> numeros;

    cout << "\nQuantidade de linhas: ";
    cin >> linhas;

    cout << "Quantidade de colunas: ";
    cin >> colunas;

    cout << endl;

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            int numero;

            cout << "pos " << i+1 << j+1 << ": ";
            cin >> numero;

            numeros.push_back(numero);
        }
    }

    cout << endl;

    matrizes.push_back(new Matriz(linhas, colunas, numeros));

    cout << endl;
};