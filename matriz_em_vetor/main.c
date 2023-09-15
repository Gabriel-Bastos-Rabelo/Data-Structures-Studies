#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int *alocaEle(int a, int b);
int *multMatriz(int *ma, int *mb, int a, int b, int c, int d);

int main()
{

    int *ma, *mb, *mc;
    int n, m, p, q;
    printf("Entre com os tamanhos das matrizes: ");
    scanf("%d %d %d %d", &n, &m, &p, &q);
    ma = alocaEle(n, m);
    mb = alocaEle(p, q);
    mc = multMatriz(ma, mb, n, m, p, q);
    if (mc == NULL)
    {
        printf("Não foi possível multiplicar as matrizes!");
        return 0;
    }
    else
    {
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", mc[i * m + j]);
            }
            printf("\n");
        }
    }

    // imprimeMat(mc, n, q);
}

int *alocaEle(int a, int b)
{
    int *mc = malloc((a * b) * sizeof(int));
    if (mc == NULL)
    {
        return NULL;
    }
    int numero = 0;
    int k = 0;
    // Se você tiver uma matriz M de tamanho m x n, você pode linearizá-la em um vetor V de tamanho m * n.
    // Para converter as posições (i, j) da matriz para o índice k no vetor, a fórmula geral é: k = i * n + j.
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("Digite o elemento da posição (%d, %d)", i, j);
            scanf("%d", &numero);
            k = i * b + j;
            mc[k] = numero;
        }
    }

    return mc;
}

int *multMatriz(int *ma, int *mb, int a, int b, int c, int d)
{
    int *mc = malloc(sizeof(int) * (c * b));
    if (mc == NULL)
    {
        return NULL;
    }

    int soma = 0;

    if (b != c)
    {
        return NULL;
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < d; j++)
        {
            soma = 0;
            for (int k = 0; k < c; k++)
            {
                int x = i * b + k;
                int y = k * d + j;
                soma += ma[x] * mb[y];
            }

            int indice = i * b + j;
            mc[indice] = soma;
        }
    }

    return mc;
}