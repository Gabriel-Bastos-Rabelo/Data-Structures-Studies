#include <stdio.h>
#include <stdlib.h>

int *SomaMatEmVetor(int *vma, int *vmb, int n, int m, int p, int q);
float *matrizTransposta(float *va, int n, int m);
float *SomaMatAComTRanspostaDeMatB(float *va, float *vb, int n, int m, int p, int q);
int *ElmLinhaL(int *va, int n, int m, int l);

int main()
{
    /*float *vma = malloc((6) * sizeof(float));
    if (vma == NULL)
    {
        return NULL;
    }
    float *vmb = malloc((6) * sizeof(float));

    if (vmb == NULL)
    {
        return NULL;
    }

    vma[0] = 1;
    vma[1] = 2;
    vma[2] = 3;
    vma[3] = -1;
    vma[4] = 0;
    vma[5] = 4;

    vmb[0] = 2.0;
    vmb[1] = -5.0;
    vmb[2] = 0.0;
    vmb[3] = -2.0;
    vmb[4] = 0.0;
    vmb[5] = 1.0;


    float *vc = SomaMatAComTRanspostaDeMatB(vma, vmb, 2, 3, 3, 2);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int k = (i * 3) + j;
            printf("%.2f ", vc[k]);
        }
        printf("\n");
    }
    */

    /*int *vmc = SomaMatEmVetor(vma, vmb, 2, 3, 2, 3);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", vmc[(i * 3) + j]);
        }
        printf("\n");
    }*/

    int *vma = malloc((6) * sizeof(int));
    if (vma == NULL)
    {
        return NULL;
    }

    vma[0] = 1;
    vma[1] = 2;
    vma[2] = 3;
    vma[3] = -1;
    vma[4] = 0;
    vma[5] = 4;

    int *vc = ElmLinhaL(vma, 2, 3, 1);
    for (int i = 0; i < 3; i++)
    {
        printf("%d", vc[i]);
    }
}

int *SomaMatEmVetor(int *vma, int *vmb, int n, int m, int p, int q)
{

    if (n == p && m == q)
    {
        int *vmc;
        vmc = malloc((n * m) * sizeof(int));
        if (vmc == NULL)
        {
            return NULL;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int k = ((i * m) + j);
                vmc[k] = vma[k] + vmb[k];
            }
        }

        return vmc;
    }
    else
    {
        return NULL;
    }
}

float *SomaMatAComTRanspostaDeMatB(float *va, float *vb, int n, int m, int p, int q)
{
    // verifico para saber se uma possivel soma futura irá ser possivel
    if (n == q && m == p)
    {

        float *vc = matrizTransposta(vb, p, q);
        if (vc == NULL)
        {
            return NULL;
        }
        float *vd = malloc((n * m) * sizeof(float));
        if (vd == NULL)
        {
            return NULL;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int k = ((i * m) + j);
                vd[k] = va[k] + vc[k];
            }
        }

        return vd;
    }
    return NULL;
}

float *matrizTransposta(float *va, int n, int m)
{

    float *vmc = malloc((n * m) * sizeof(float));
    if (vmc == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int k = (j * n) + i;
            int l = (i * m) + j;
            vmc[k] = va[l];
        }
    }

    return vmc;
}

int *ElmLinhaL(int *va, int n, int m, int l)
{
    int *vb = malloc((n * m) * sizeof(int));
    if (vb == NULL)
    {
        return NULL;
    }
    int pos = 0;
    for (int i = 0; i < m; i++)
    {
        int k = (l * m) + i;
        vb[pos] = va[k];
        pos++;
    }

    return vb;
}