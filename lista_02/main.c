#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

float RetornaDiagonalPrincipal(float **mat, int n, int m);
int **MultMatrix(int n, int m, int p, int q, float **ma, float **mb);
int TipodeMatriz(int **ma, int n, int m);
int **matrizTransposta(int **ma, int n, int m);
int eh_simetrica(int **ma, int **mb, int n, int m);
int **matrizOposta(int **ma, int n, int m);
int eh_diagonal(int **ma, int n, int m);
int eh_antisimetrica(int **ma, int **mb, int n, int m);

int main()
{

    int n = 2;
    int m = 2;
    int **ma = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        ma[i] = malloc(m * sizeof(int));
    }

    ma[0][0] = 1;
    ma[0][1] = 0;
    ma[1][0] = 0;
    ma[1][1] = 2;

    int resultado = TipodeMatriz(ma, n, m);
    printf("%d", resultado);

    return 0;
}


// QUESTAO 1
int soma_matriz(int *v, int n)
{

    int soma = 0;

    for (int i = 0; i < n; i++)
    {
        soma += v[i];
    }

    return soma;
}

// QUESTAO 2
float RetornaDiagonalPrincipal(float **mat, int n, int m)
{

    float soma = 0.0;
    for (int i = 0; i < n; i++)
    {
        soma += mat[i][i];
    }

    return soma;
}

// QUESTAO 3
int **MultMatrix(int n, int m, int p, int q, float **ma, float **mb)
{

    if (m == p)
    {

        int elemento = 0;
        int **mc;
        mc = malloc(n * sizeof(int *));
        for (int i = 0; i < q; i++)
        {
            mc[i] = malloc(q * sizeof(int));
        }

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < q; j++)
            {
                elemento = 0;
                for (int k = 0; k < m; k++)
                {
                    elemento += ma[i][k] * mb[k][j];
                }

                mc[i][j] = elemento;
            }
        }
        return mc;
    }
    else
    {
        return NULL;
    }
}


// QUESTAO 5
int TipodeMatriz(int **ma, int n, int m)
{

    int **matriz_tranposta;
    int **matriz_oposta;
    matriz_tranposta = matrizTransposta(ma, n, m);
    matriz_oposta = matrizOposta(ma, n, m);
    if (eh_simetrica(ma, matriz_tranposta, n, m) == TRUE)
    {
        return 1;
    }
    else if (eh_antisimetrica(matriz_tranposta, matriz_oposta, n, m) == TRUE)
    {
        return 3;
    }
    else if (eh_diagonal(ma, n, m) == TRUE)
    {
        return 2;
    }
}

int eh_simetrica(int **ma, int **mb, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ma[i][j] != mb[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}

int eh_antisimetrica(int **ma, int **mb, int n, int m)
{
    if (n != m)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ma[i][j] != mb[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}

int eh_diagonal(int **ma, int n, int m)
{

    if (n == m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (ma[i][j] != 0)
                {
                    return 0;
                }
            }
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

int **matrizTransposta(int **ma, int n, int m)
{

    int **mc;
    mc = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        mc[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mc[i][j] = ma[j][i];
        }
    }

    return mc;
}

int **matrizOposta(int **ma, int n, int m)
{
    int **mc;
    mc = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        mc[i] = malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mc[i][j] = ma[i][j] * -1;
        }
    }

    return mc;
}