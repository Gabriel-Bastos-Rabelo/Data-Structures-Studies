#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

// questao 1 d

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

// questao 1 e
int iUltimoElementoVazia(Stack *s, void *i)
{
    if (s != NULL)
    {

        for (int i = s->top; i > -1; i--)
        {
            stkPop(s);
        }

        stkPush(s, i);

        return TRUE;
    }

    return FALSE;
}

// questao 1 f

int iUltimoElementoInalterada(Stack *s, void *i)
{

    if (s != NULL)
    {
        Stack *q = stkCreate(s->top + 2);
        void *aux;
        if (q != NULL)
        {
            for (int i = s->top; i > -1; i--)
            {
                aux = stkPop(s);
                stkPush(q, aux);
            }

            stkPush(s, i);

            for (int i = q->top; i > -1; i--)
            {
                aux = stkPop(q);
                stkPush(s, aux);
            }

            return TRUE;
        }
    }

    return FALSE;
}

// questao 1 g
int iterceiroElementoFinal(Stack *s, void *i)
{
    if (s != NULL)
    {
        if (s->top >= 1)
        {
            Stack *q = stkCreate(s->top + 2);
            void *aux;
            for (int i = s->top; i > 1; i--)
            {
                aux = stkPop(s);
                stkPush(q, aux);
            }

            stkPush(s, i);

            for (int i = q->top; i > -1; i--)
            {
                aux = stkPop(q);
                stkPush(s, aux);
            }

            return TRUE;
        }
    }

    return FALSE;
}

// questao 2

int xCy(void *frase)
{
    int tamanho = strlen((char *)frase);
    Stack *q = stkCreate(tamanho);
    if (q != NULL)
    {

        int i = 0;
        void *aux;
        while (((char *)frase)[i] != 'C')
        {

            stkPush(q, &((char *)frase)[i]);
            i++;
        }
        i++;
        while (i < tamanho)
        {
            if (stkIsEmpty(q) == TRUE)
            {
                return FALSE;
            }
            aux = stkPop(q);
            if (*((char *)aux) != ((char *)frase)[i])
            {
                return FALSE;
            }
            i++;
        }

        if (stkIsEmpty(q) == TRUE)
        {

            return TRUE;
        }
    }

    return FALSE;
}

// questao 3
int aDbD(void *frase)
{
    int tamanho = strlen((char *)frase);
    Stack *pilha1 = stkCreate(tamanho);
    Stack *pilha2 = stkCreate(tamanho);
    if (pilha1 != NULL)
    {
        void *aux;
        int i = 0;
        while (((char *)frase)[i] != 'D')
        {
            stkPush(pilha1, &((char *)frase)[i]);
            i++;
        }
        i++;
        int desempilharParaPilha2 = TRUE;
        for (; i < tamanho; i++)
        {
            if (((char *)frase)[i] == 'D')
            {
                if (desempilharParaPilha2)
                {
                    if (stkIsEmpty(pilha1) == FALSE)
                    {

                        return FALSE;
                    }
                    desempilharParaPilha2 = FALSE;
                }
                else
                {
                    if (stkIsEmpty(pilha2) == FALSE)
                    {

                        return FALSE;
                    }
                    desempilharParaPilha2 = TRUE;
                }
            }
            else if (desempilharParaPilha2)
            {
                if (stkIsEmpty(pilha1) == TRUE)
                {

                    return FALSE;
                }
                aux = stkPop(pilha1);
                if (*((char *)aux) != ((char *)frase)[i])
                {
                    return FALSE;
                }
                stkPush(pilha2, aux);
            }
            else if (desempilharParaPilha2 == FALSE)
            {
                if (stkIsEmpty(pilha2) == TRUE)
                {

                    return FALSE;
                }
                aux = stkPop(pilha2);
                if (*((char *)aux) != ((char *)frase)[i])
                {
                    return FALSE;
                }
                stkPush(pilha1, aux);
            }
        }

        return TRUE;
    }
}

// questao 7
int sequenciaValida(void *seq)
{
    int tamanho = strlen((char *)seq);

    int empilhar = 0;
    int desempilhar = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (((char *)seq)[i] == 'E')
        {
            empilhar++;
        }
        else
        {
            desempilhar++;
            if (desempilhar > empilhar)
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}

// questao 8 d
int menorQueChave(Stack *s, void *value)
{
    if (s != NULL)
    {
        if (stkIsEmpty(s) == FALSE)
        {

            while (*(int *)s->item[s->top] > *(int *)value && stkIsEmpty(s) == FALSE)
            {
                s->top--;
                printf("%d ", *(int *)s->item[s->top]);
            }

            return TRUE;
        }
    }

    return FALSE;
}

// questao 10
int puneNParatraz(Stack *s, int n)
{
    if (s != NULL)
    {
        if (n <= s->top)
        {
            void *aux;
            aux = stkTop(s);
            int next;
            for (int i = s->top; i > s->top - n; i--)
            {
                s->item[i] = s->item[i - 1];
            }

            s->item[s->top - n] = aux;

            return TRUE;
        }
    }

    return FALSE;
}

// questao 1 prova 2023.1

char *inverteString(char *s, int n)
{
    if (s != NULL)
    {

        char *stringAuxiliar = malloc(sizeof(char) * n);
        Stack *pilhaAuxiliar = stkCreate(n);
    
        int posicaoString = 0;

        for(int i = 0; i < n; i++)
        {
            if (((char *)s)[i] == ' ' || ((char *)s)[i] == '.')
            {
                while (stkIsEmpty(pilhaAuxiliar) == FALSE)
                {
                    stringAuxiliar[posicaoString] = *(char *)stkPop(pilhaAuxiliar);

                    posicaoString++;
                }
                if (((char *)s)[i] == ' ')
                {
                    stringAuxiliar[posicaoString] = ' ';
                }
                else
                {
                    stringAuxiliar[posicaoString] = '.';
                }
                posicaoString++;
            }
            else
            {

                stkPush(pilhaAuxiliar, &((char *)s)[i]);
            }

    
        }

        stkDestroy(pilhaAuxiliar);
        return stringAuxiliar;
    }

    return NULL;
}


int stkPromove(Stack * s, int n){
    if(s != NULL){
        if(n <= s->top+1){

            Stack *pilhaAuxiliar = stkCreate(s->top+1);
            void *aux;
            void *elm;
            for(int i = s->top; i > n; i--){
                aux = stkPop(s);
                stkPush(pilhaAuxiliar, aux);
            }

            elm = stkPop(s);

            while(stkIsEmpty(pilhaAuxiliar) == FALSE){

                
                aux = stkPop(pilhaAuxiliar);
                stkPush(s, aux);
            }

            stkPush(s, elm);

            return TRUE;




        }
    }

    return FALSE;
}