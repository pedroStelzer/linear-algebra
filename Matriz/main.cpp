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
        cout << "2. Somar" << endl;
        cout << "3. Subtrair" << endl;
        cout << "4. Multiplicar" << endl;
        cout << "5. Transposta" << endl;
        cout << "6. Simetrica" << endl;
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
            
            case 2:
            
                // verificar se pode somar

                matrizes.push_back(matrizes[0]->somar(matrizes[1]));

                matrizes[0]->imprimir();
                cout << "+" << endl;
                matrizes[1]->imprimir();
                cout << "=" << endl;
                matrizes[2]->imprimir();

                break;
            
            case 3:

                // verificar se pode subtrair
            
                matrizes.push_back(matrizes[0]->subtrair(matrizes[1]));

                matrizes[0]->imprimir();
                cout << "-" << endl;
                matrizes[1]->imprimir();
                cout << "=" << endl;
                matrizes[2]->imprimir();

                break;
            
            case 4:

                // verificar se pode ter multiplicação de matrizes

                matrizes.push_back(matrizes[0]->multiplicar(matrizes[1]));

                matrizes[0]->imprimir();
                cout << "x" << endl;
                matrizes[1]->imprimir();
                cout << "=" << endl;
                matrizes[2]->imprimir();

                break;
            
            case 5:

                matrizes.push_back(matrizes[0]->transposta());
                matrizes[1]->imprimir();

                break;
            
            case 6:

                if(matrizes[0]->simetrica())
                {
                    cout << "A matriz: " << endl;

                    matrizes[0]->imprimir();

                    cout << "\n é simétrica" << endl << endl;
                }
                else
                {
                    cout << "A matriz: " << endl;

                    matrizes[0]->imprimir();

                    cout << "\n não é simétrica. Para ser simétrica a matriz precisa: [A] = [A]^t" << endl << endl;
                }

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