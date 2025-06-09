#ifndef MATRIZ_H
#define MATRIZ_H
#include <vector>

using namespace std;

class Matriz
{
    private:

        int linhas;
        int colunas;
        vector<vector<int>> matriz;

    public:

        Matriz(int linha, int coluna, vector<int> numeros);
        ~Matriz();

        Matriz* somar(Matriz* matriz);
        Matriz* subtrair(Matriz* matriz);
        Matriz* multiplicar(Matriz* matriz);

        Matriz* transposta();
        bool simetrica();

        void imprimir();

};

#endif // MATRIZ_H