// arquivo de implementação
#include "matriz.h"
#include <stdlib.h>

typedef struct matriz
{
    int row;
    int col;
    int *matriz;

} Matriz;

Matriz *create(int row, int col)
{

    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));

    if (mat == NULL)
    {
        return NULL;
    }

    mat->row = row;
    mat->col = col;

    mat->matriz = (int *)malloc(sizeof(int) * (row * col));

    return mat;
}

void insert(Matriz *mat, int value, int row, int col)
{

    mat->matriz[(row * mat->col) + col] = value;
}

int destroy(Matriz *mat)
{
    if (mat == NULL)
    {
        return FALSE;
    }
    free(mat->matriz);
    free(mat);
    return TRUE;
}

int matGetElemIJ(Matriz *mat, int i, int j)
{
    return mat->matriz[(i * mat->col) + j];
}

int *transposta(Matriz *mat)
{   
    if(mat -> row == mat -> col){
        
        int *mc = (int *)malloc(sizeof(int) * (mat->row * mat->col));
        if(mc != NULL){

        for (int i = 0; i < mat->row; i++)
        {
            for (int j = 0; j < mat->col; j++)
            {

                int k = (j * mat->row) + i;
                int l = (i * mat->col) + j;
                mc[k] = mat->matriz[l];
            }
        }

         return mc;
        }

         


        }
        
       
    
    return NULL;
   
}

int *multiplication(Matriz *mata, Matriz *matb)
{
    if (mata != NULL && matb != NULL)
    {
        if ((mata->col) == (matb->row))
        {
            int *matmult = malloc(sizeof(int) * (mata->col * matb->row));

            if (matmult == NULL)
            {
                return NULL;
            }
            for (int i = 0; i < mata->row; i++)
            {
                for (int j = 0; j < matb->col; j++)
                {
                    int soma = 0;
                    for (int k = 0; k < matb->row; k++)
                    {

                        soma += matGetElemIJ(mata, i, k) * matGetElemIJ(matb, k, j);
                    }

                    int indice = i * (mata->col) + j;
                    matmult[indice] = soma;
                }
            }

            return matmult;
        }
        return NULL;
    }
    return NULL;
}

int getNumCol(Matriz *mat)
{
    if (mat == NULL)
    {
        return -1;
    }
    return mat->col;
}

int getNumRow(Matriz *mat)
{
    if (mat == NULL)
    {
        return -1;
    }
    return mat->row;
}