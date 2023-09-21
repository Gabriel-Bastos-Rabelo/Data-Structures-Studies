#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define TRUE 1
#define FALSE 0

typedef struct _queue_
{
    int front, rear;
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
                q->rear = -1;
                q->front = 0;
                return q;
            }
        }
        free(q);
    }

    return NULL;
}

int qDestroy(Queue *q)
{
    if (q != NULL)
    {
        if (q->rear < 0)
        {
            free(q->item);
            free(q);
            return TRUE;
        }
        return FALSE;
    }
}

int qEnqueue(Queue *q, void *data)
{
    if (q != NULL)
    {

        if (q->rear < q->maxItens - 1)
        {

            q->rear++;
            q->item[q->rear] = data;
            return TRUE;
        }
    }
    return FALSE;
}

void *qDequeue(Queue *q)
{
    if (q != NULL)
    {

        if (q->rear >= 0)
        {
            void *data = q->item[q->front];
            for (int i = q->front; i < q->rear; i++)
            {
                q->item[i] = q->item[i + 1];
            }

            q->rear--;

            return data;
        }
    }

    return NULL;
}

void *qFirst(Queue *q)
{
    if (q != NULL)
    {
        if (q->rear >= 0)
        {
            void *data = q->item[q->front];

            return data;
        }
    }

    return NULL;
}

int qIsEmpty(Queue *q)
{
    if (q != NULL)
    {
        if (q->rear < 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}
