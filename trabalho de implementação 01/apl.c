#include "matriz.h"
#include <stdio.h>

int main()
{
    // Pegando do usuario numero de linhas e colunas da matriz A
    int matALinhas, matAColunas;
    printf("Digite o número de linhas e colunas da matriz A: \n");
    scanf("%d %d", &matALinhas, &matAColunas);

    // Pegando do usuario número de linhas e colunas da matriz B
    int matBLinhas, matBColunas;
    printf("Digite o número de linhas e colunas da matriz B: \n");
    scanf("%d %d", &matBLinhas, &matBColunas);
    Matriz *mata = create(matALinhas, matAColunas);
    Matriz *matb = create(matBLinhas, matBColunas);

    // Inserindo valores na matriz A
    if (mata != NULL)
    {
        for (int i = 0; i < getNumRow(mata); i++)
        {
            for (int j = 0; j < getNumCol(mata); j++)
            {
                int value;
                printf("Insira o valor para a linha %d e coluna %d da matriz A: \n", i, j);
                scanf("%d", &value);
                insert(mata, value, i, j);
            }
        }
    }

    // Inserindo valores na matriz B
    if (matb != NULL)
    {
        for (int i = 0; i < getNumRow(matb); i++)
        {
            for (int j = 0; j < getNumCol(matb); j++)
            {
                int value;
                printf("Insira o valor para a linha %d e coluna %d da matriz B: \n", i, j);
                scanf("%d", &value);
                insert(matb, value, i, j);
            }
        }
    }

    // Imprimindo a matriz A

    printf("Matriz A\n");
    for (int i = 0; i < getNumRow(mata); i++)
    {
        for (int j = 0; j < getNumCol(mata); j++)
        {

            int elemento = matGetElemIJ(mata, i, j);
            printf("%d ", elemento);
        }
        printf("\n");
    }

    printf("\n");

    // Imprimindo a matriz B
    printf("Matriz B\n");

    for (int i = 0; i < getNumRow(matb); i++)
    {
        for (int j = 0; j < getNumCol(matb); j++)
        {

            int elemento = matGetElemIJ(matb, i, j);
            printf("%d ", elemento);
        }
        printf("\n");
    }

    printf("\n");

    // Imprimindo a multiplicação da matriz A pela B
    printf("Multiplicação da matriz A pela B \n");
    int *matmult = multiplication(mata, matb);

    if (matmult != NULL)
    {

        for (int i = 0; i < getNumRow(mata); i++)
        {
            for (int j = 0; j < getNumCol(matb); j++)
            {
                int indice = ((getNumCol(matb) * i) + j);
                printf("%d ", matmult[indice]);
            }
            printf("\n");
        }
    }

    printf("\n");

    // Imprimindo a matriz transposta de A

    printf("Matriz transposta de A\n");
    int *matTranpostaA = transposta(mata);

    if (matTranpostaA != NULL)
    {

        for (int i = 0; i < getNumRow(mata); i++)
        {
            for (int j = 0; j < getNumCol(mata); j++)
            {
                int indice = ((getNumCol(mata) * i) + j);
                printf("%d ", matTranpostaA[indice]);
            }
            printf("\n");
        }
    }

    printf("\n");

    // Imprimindo a matriz transposta de B

    printf("Matriz transposta de B\n");

    int *matTranpostaB = transposta(matb);

    if (matTranpostaB != NULL)
    {

        for (int i = 0; i < getNumRow(matb); i++)
        {
            for (int j = 0; j < getNumCol(matb); j++)
            {
                int indice = ((getNumCol(matb) * i) + j);
                printf("%d ", matTranpostaB[indice]);
            }
            printf("\n");
        }
    }

    // Destruindo a matriz A
    destroy(mata);

    // Destruindo a matriz B
    destroy(matb);
}