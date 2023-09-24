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
            q->item = (void *)malloc(sizeof(void *));
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