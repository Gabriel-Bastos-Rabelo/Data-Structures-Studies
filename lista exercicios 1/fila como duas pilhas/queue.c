#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define TRUE 1
#define FALSE 0

typedef struct _queue_
{
    int top;
    int maxItens;
    void **item;
} Queue;

Queue *qcreate(int maxItems)
{
    Queue *q;
    if (maxItems > 0)
    {
        q = (Queue *)malloc(sizeof(Queue));
        if (q != NULL)
        {
            q->item = (void **)malloc(sizeof(void *) * maxItems);
            if (q->item != NULL)
            {
                q->maxItens = maxItems;
                q->top = -1;
                return q;
            }
        }
        free(q);
    }

    return NULL;
}

int qEnqueue(Queue *q, void *data)
{
    if (q != NULL)
    {
        if (q->top < q->maxItens - 1)
        {
            q->top++;
            q->item[q->top] = data;
            return TRUE;
        }
    }

    return FALSE;
}

void *stkPop(Queue *s)
{
    void *aux;
    if (s != NULL)
    {
        if (s->top >= 0)
        {
            aux = s->item[s->top];
            s->top--;
            return aux;
        }
    }
    return NULL;
}

void *qDequeue(Queue *q)
{
    if (q != NULL)
    {
        Queue *queueAuxiliar = qcreate(q->maxItens);
        if (queueAuxiliar != NULL)
        {
            if (qIsEmpty(q) == FALSE)
            {
                void *aux;
                void *elmRetirado;
                for (int i = q->top; i > -1; i--)
                {
                    aux = stkPop(q);
                    qEnqueue(queueAuxiliar, aux);
                }

                elmRetirado = stkPop(queueAuxiliar);

                for (int i = queueAuxiliar->top; i > -1; i--)
                {
                    aux = stkPop(queueAuxiliar);
                    qEnqueue(q, aux);
                }

                return elmRetirado;
            }
        }
    }

    return NULL;
}

int qIsEmpty(Queue *q)
{
    if (q != NULL)
    {
        if (q->top < 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}

int qDestroy(Queue *q)
{
    if (q != NULL)
    {
        if (q->top < 0)
        {
            free(q->item);
            free(q);
            return TRUE;
        }
        return FALSE;
    }
}