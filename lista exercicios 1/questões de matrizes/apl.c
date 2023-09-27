#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{

    // testes para a questao 13
    /*
    int v[4] = {1, 2, 3, 4};
    int *vColuna;

    vColuna = ExtraiColuna(v, vColuna, 2, 0);

    for (int i = 0; i < 2; i++)
    {
        printf("%d", vColuna[i]);
    }

    */

    // testes para a questao 15

    // int v[4] = {1, 2, 3, 4};
    // int maior = MaiorElementodaMatrizEmK(v, 2, 2, 0);
    // printf("%d", maior);

    int v1[] = {1,2,3,4,5,6,7,8,9};
    printf("%d", MaiordaColunadaMatriz(v1, 3, 3, 1));
}