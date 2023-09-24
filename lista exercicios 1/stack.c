#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0

typedef struct _stack_
{
    int maxItens;
    int top;
    void **item;
} Stack;

Stack *stkCreate(int max)
{
    Stack *s;
    if (max > 0)
    {
        s = (Stack *)malloc(sizeof(Stack));
        if (s != NULL)
        {
            s->item = (void **)malloc(sizeof(void *) * max);

            if (s->item != NULL)
            {
                s->maxItens = max;
                s->top = -1;
                return s;
            }
        }
    }

    return NULL;
}

int stkDestroy(Stack *s)
{
    if (s != NULL)
    {
        if (s->top < 0)
        {
            free(s->item);
            free(s);
            return TRUE;
        }
    }

    return FALSE;
}

int stkPush(Stack *s, void *elm)
{
    if (s != NULL)
    {
        if (s->top < s->maxItens - 1)
        {
            s->top++;
            s->item[s->top] = elm;
            return TRUE;
        }
    }

    return FALSE;
}

void *stkPop(Stack *s)
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

void *stkTop(Stack *s)
{
    void *aux;
    if (s != NULL)
    {
        if (s->top >= 0)
        {
            aux = s->item[s->top];
            return aux;
        }
    }
    return NULL;
}

int stkIsEmpty(Stack *s)
{
    if (s != NULL)
    {
        if (s->top < 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

// questão 1 a
int iSegundoElemento(Stack *s, void *i)
{
    if (s != NULL)
    {
        if (stkIsEmpty(s) == FALSE)
        {
            if (s->top >= 2)
            {
                for (int i = 0; i < 2; i++)
                {
                    stkPop(s);
                }
                stkPush(s, i);

                return TRUE;
            }
        }
    }

    return FALSE;
}

// questão 1 b
int iSegundoElementoInalterada(Stack *s, void *i)
{
    if (s != NULL)
    {
        if (stkIsEmpty(s) == FALSE)
        {
            void *aux;
            aux = stkPop(s);
            stkPush(s, i);
            stkPush(s, aux);
            return TRUE;
        }
    }

    return FALSE;
}

// questao 1 c

int iEnesimoElemento(Stack *s, int n, void *i)
{
    if (s != NULL)
    {

        if (n <= s->top)
        {
            for (int i = s->top; i < s->top - n; i--)
            {
                stkPop(s);
            }

            stkPush(s, i);
            return TRUE;
        }
    }

    return FALSE;
}

int iEnesimoInalterada(Stack *s, int n, void *i)
{
    if (s != NULL)
    {

        if (s->top >= n)
        {
            Stack *pilhaAuxiliar = stkCreate(n);
            void *aux;
            for (int i = 0; i < n - 1; i++)
            {
                aux = stkPop(s);
                stkPush(pilhaAuxiliar, aux);
            }

            stkPop(s);
            stkPush(s, i);

            for (int i = 0; i < n - 1; i++)
            {
                aux = stkPop(pilhaAuxiliar);
                stkPush(s, aux);
            }

            return TRUE;
        }
    }

    return FALSE;
}

int iUltimoElementoVazia(Stack *s, void *i)
{
}