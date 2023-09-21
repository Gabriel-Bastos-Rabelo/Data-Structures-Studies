#include "cofo.h"
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct time
{
    char nome[30];
    int partidas;
    int vitorias;
    int derrotas;
} Time;

typedef struct cofo
{
    int numItems;
    int maxItems;
    int cur;
    Time *items;
} Cofo;

Time *createTime(const char *nome, int partidas, int vitorias, int derrotas)
{
    Time *t;
    t = (Time *)malloc(sizeof(Time));
    if (t != NULL)
    {
        strcpy(t->nome, nome);
        t->partidas = partidas;
        t->vitorias = vitorias;
        t->derrotas = derrotas;
    }
}

Cofo *cofCreate(int maxItems)
{
    Cofo *c;
    if (maxItems > 0)
    {
        c = (Cofo *)malloc(sizeof(Cofo));
        if (c != NULL)
        {
            c->items = (Time *)malloc(sizeof(Time) * maxItems);

            if (c->items != NULL)
            {
                c->numItems = 0;
                c->maxItems = maxItems;
                return c;
            }

            free(c);
        }
    }
    return NULL;
}

int cofDestroy(Cofo *c)
{
    if (c != NULL)
    {
        if (c->numItems == 0)
        {
            free(c->items);
            free(c);
            return TRUE;
        }
    }

    return FALSE;
}

int cofInsert(Cofo *c, Time *t)
{
    if (c != NULL)
    {
        if (c->numItems < c->maxItems)
        {
            c->items[c->numItems] = *t;
            c->numItems++;
            return TRUE;
        }
    }

    return FALSE;
}
