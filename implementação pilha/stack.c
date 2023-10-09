#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0

typedef struct _stack_
{
    int maxItens;
    int top;
    char *item;
} Stack;

Stack *stkCreate(int max)
{
    Stack *s;
    if (max > 0)
    {
        s = (Stack *)malloc(sizeof(Stack));
        if (s != NULL)
        {
            s->item = (char *)malloc(sizeof(char) * max);

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

int stkPush(Stack *s, char elm)
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

char stkPop(Stack *s) // Correção aqui
{
    char aux; // Correção aqui
    if (s != NULL)
    {
        if (s->top >= 0)
        {
            aux = s->item[s->top]; // Correção aqui
            s->top--;
            return aux; // Correção aqui
        }
    }

    return '\0'; // Correção aqui
}

char stkTop(Stack *s) // Correção aqui
{
    char aux; // Correção aqui
    if (s != NULL)
    {
        if (s->top >= 0)
        {
            aux = s->item[s->top]; // Correção aqui
            return aux;            // Correção aqui
        }
    }
    return '\0'; // Correção aqui
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

// lista de exercicios 4

int ehPalindromo(char *s, int n)
{

    if (s != NULL)
    {
        Stack *stk = stkCreate(n);
        if (stk != NULL)
        {

            char aux;
            for (int i = 0; i < n; i++)
            {
                stkPush(stk, s[i]);
                
            }

            for (int j = 0; j < n; j++)
            {
                aux = stkPop(stk);
                
                if (aux != s[j])
                {

                   
                    return FALSE;
                }
            }

            return TRUE;
        }
    }

    return FALSE;
}
