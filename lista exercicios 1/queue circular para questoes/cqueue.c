#include <stdio.h>
#include <stdlib.h>

#include "cqueue.h"

#define TRUE 1
#define FALSE 0

typedef struct _cqueue_
{
    int front, rear;
    int maxItens;
    int nElms;
    void **item;
} CQueue;

CQueue *cqcreate(int maxitems)
{
    if (maxitems > 0)
    {
        CQueue *q = (CQueue *)malloc(sizeof(CQueue));
        if (q != NULL)
        {
            q->item = (void *)malloc(sizeof(void *) * maxitems);
            if (q->item != NULL)
            {
                q->rear = -1;
                q->front = 0;
                q->maxItens = maxitems;
                q->nElms = 0;
                return q;
            }
        }

        free(q);
    }

    return NULL;
}

int cqIsEmpty(CQueue *q)
{
    if (q != NULL)
    {
        if (q->nElms == 0)
        {
            free(q->item);
            free(q);
            return TRUE;
        }
    }

    return FALSE;
}

int incCirc(int i, int max)
{
    if (i == max - 1)
    {
        return 0;
    }
    else
    {
        return i + 1;
    }
}

int decCirc(int i, int max)
{
    if (i == 0)
    {
        return max - 1;
    }
    else
    {
        return i - 1;
    }
}

int cqEnqueue(CQueue *q, void *data)
{
    if (q != NULL)
    {
        if (q->nElms < q->maxItens)
        {
            q->rear = incCirc(q->rear, q->maxItens);
            q->item[q->rear] = data;
            q->nElms++;
            return TRUE;
        }
    }

    return FALSE;
}

void *cqDequeue(CQueue *q)
{

    if (q != NULL)
    {

        if (q->nElms > 0)
        {

            void *data;
            data = q->item[q->front];
            q->front = incCirc(q->front, q->maxItens);
            q->nElms--;

            return data;
        }
    }

    return NULL;
}

int retornarRear(CQueue *q)
{
    if (q != NULL)
    {
        return q->rear;
    }
}

int retornarFront(CQueue *q)
{
    if (q != NULL)
    {
        return q->front;
    }
}

// questão 8 c
int removeElementosOrdemImpar(CQueue *q)
{
    if (q != NULL)
    {
        int pos = 0;
        int next;
        while (pos <= (int)(q->nElms / 2))
        {

            for (int i = pos; i < q->nElms; i++)
            {
                next = incCirc(i, q->maxItens);
                q->item[i] = q->item[next];

                printf("%d %d\n", *(int *)q->item[i], *(int *)q->item[next]);
            }
            q->rear = decCirc(q->rear, q->maxItens);
            pos++;
            q->nElms--;
        }
    }
}

// questao 8 e
int punirNPosicoes(CQueue *q, int n)
{
    if (q != NULL)
    {
        if (q->nElms > n)
        {
            void *aux;
            aux = q->item[q->front];
            int next;
            int percorridos = 0;
            int atual = q->front;
            while (percorridos < n)
            {
                next = incCirc(atual, q->maxItens);
                q->item[atual] = q->item[next];
                percorridos++;
                atual = incCirc(atual, q->maxItens);
            }

            q->item[n] = aux;

            return TRUE;
        }
    }

    return FALSE;
}

// questao 11
int PuneFuraFila(CQueue *f)
{

    if (f != NULL)
    {

        if (cqIsEmpty(f) == FALSE)
        {
            void *aux = f->item[f->front];
            int meio = f->nElms / 2;
            int current = f->front;
            int next = incCirc(current, f->maxItens);
            for (int i = 0; i < meio; i++)
            {
                f->item[current] = f->item[next];
                current = incCirc(current, f->maxItens);
                next = incCirc(current, f->maxItens);
            }

            f->item[current] = aux;

            return TRUE;
        }
    }

    return FALSE;
}

int primeiroElmPrimeiraPos(CQueue *f)
{
    if (f != NULL)
    {

        CQueue *filaAuxiliar = cqcreate(f->maxItens);
        void *aux;
        if (filaAuxiliar != NULL)
        {
            while (cqIsEmpty(f) == FALSE)
            {
                aux = cqDequeue(f);
                cqEnqueue(filaAuxiliar, aux);
            }

            while (cqIsEmpty(filaAuxiliar) == FALSE)
            {
                aux = cqDequeue(filaAuxiliar);
                cqEnqueue(f, aux);
            }

            return TRUE;
        }
    }

    return FALSE;
}

int FuraFila(CQueue *q, void *value)
{
    if (q != NULL)
    {
        if (q->nElms != q->maxItens)
        {

            int posicaoCerta = decCirc(q->front, q->maxItens);
            q->item[posicaoCerta] = value;
            q->front = posicaoCerta;

            return TRUE;
        }
    }

    return FALSE;
}


int qRemoveLessThanKey (CQueue * q, void * key){
    if(q != NULL){
        int current = q->front;

        for(int i = 0; i < q->nElms; i++){
            if(*(int *)q->item[current] < *(int*)key){
                q->front = current;
                break;
            }
            else{
                current = incCirc(current, q->maxItens);
                q -> nElms --;
            }
        }

        


        return TRUE;
    }


    return FALSE;
}