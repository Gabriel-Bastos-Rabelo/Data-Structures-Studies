#include <stdlib.h>
#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>
#define True 1
#define False 0

TNode *abpCreate()
{
    TNode *t = (TNode *)malloc(sizeof(TNode));
    if (t != NULL)
    {
        t = NULL;
    }
    return t;
}

void abpDestroyIfEmpty(TNode *t)
{
    if (t == NULL)
    {
        free(t);
    }
}

void abpEsvaziar(TNode *t)
{
    if (t == NULL)
    {
        return;
    }
    else
    {
        abpEsvaziar(t->l);
        abpEsvaziar(t->r);
        free(t);
        t = NULL;
    }
}

/*void emOrdemListar(TNode *t){
  if(t != NULL){
    emOrdemListar(t->l);
    printf("%d", t->data);
    emOrdemListar(t->r);
  }
}*/

TNode *abpInsert(TNode *t, void *data, int (*cmp)(void *, void *))
{
    if (t == NULL)
    {
        TNode *newnode = (TNode *)malloc(sizeof(TNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->l = NULL;
            newnode->r = NULL;
            return newnode;
        }
    }

    else
    {
        if (cmp(data, t->data) == -1)
        {
            t->l = abpInsert(t->l, data, cmp);
        }

        else
        {
            t->r = abpInsert(t->r, data, cmp);
        }

        return t;
    }

    return NULL;
}


TNode *abpRemoveMaior(TNode *t, int (*cmp)(void *, void *), void **data)
{
    if (t != NULL)
    {
        if (t->r != NULL)
        {
            t->r = abpRemoveMaior(t->r, cmp, data);
            return t;
        }

        else
        {
            if (t->l != NULL)
            {
                *data = t->data;
                TNode *aux = t->l;
                free(t);
                return aux;
            }

            else
            {
                *data = t->data;
                free(t);
                return NULL;
            }
        }
    }

    *data = NULL;
    return NULL;
}

TNode *abpRemoveAno(TNode *t, void *key, int (*cmp)(void *, void *), void **data)
{
    void *data2;
    if (t != NULL)
    {
        int stat = cmp(key, t->data);
        if (stat < 0)
        {
            t->l = abpRemoveAno(t->l, key, cmp, data);
            return t;
        }

        else if (stat > 0)
        {
            t->r = abpRemoveAno(t->r, key, cmp, data);
            return t;
        }

        else
        {

            if (t->l == NULL && t->r == NULL)
            {
                *data = t->data;
                free(t);
                return NULL;
            }

            else if (t->l == NULL)
            {
                TNode *aux = t->r;
                *data = t->data;
                free(t);
                return aux;
            }

            else if (t->r == NULL)
            {
                TNode *aux = t->l;
                *data = t->data;
                free(t);
                return aux;
            }

            else
            {
                *data = t->data;
                t->l = abpRemoveMaior(t->l, cmp, &data2);
                t->data = data2;
                return t;
            }
        }
    }

    return NULL;
}





TNode *abpRemoveNome(TNode *t, void *key, int (*cmp)(void *, void *), void **data)
{
    void *data2;
    if (t != NULL)
    {
        int stat = cmp(key, t->data);
        if(stat == 0){

            if(t->l == NULL && t->r == NULL){
                *data = t->data;
                free(t);
                return NULL;
            }

            else if (t->l == NULL)
            {
                TNode *aux = t->r;
                *data = t->data;
                free(t);
                return aux;
            }

            else if (t->r == NULL)
            {
                TNode *aux = t->l;
                *data = t->data;
                free(t);
                return aux;
            }

            else{

                *data = t->data;
                t->l = abpRemoveMaior(t->l, cmp, &data2);
                t->data = data2;
                return t;
            
            }


        }

        else{
            t->l = abpRemoveNome(t->l, key, cmp, data);
            t->r = abpRemoveNome(t->r, key, cmp, data);

            return t;
        }
    }

    return NULL;
}


TNode *abpRemoveNota(TNode *t, void *key, int (*cmp)(void *, void *), void **data)
{
    void *data2;
    if (t != NULL)
    {
        int stat = cmp(key, t->data);
        if(stat == 0){

            if(t->l == NULL && t->r == NULL){
                *data = t->data;
                free(t);
                return NULL;
            }

            else if (t->l == NULL)
            {
                TNode *aux = t->r;
                *data = t->data;
                free(t);
                return aux;
            }

            else if (t->r == NULL)
            {
                TNode *aux = t->l;
                *data = t->data;
                free(t);
                return aux;
            }

            else{

                *data = t->data;
                t->l = abpRemoveMaior(t->l, cmp, &data2);
                t->data = data2;
                return t;
            
            }


        }

        else{
            t->l = abpRemoveNota(t->l, key, cmp, data);
            t->r = abpRemoveNota(t->r, key, cmp, data);

            return t;
        }
    }

    return NULL;
}


void abpConsultarAno(TNode *t, void *key, int(*cmp)(void *, void *), void **data){
    if(t != NULL){
        int stat = cmp(key, t->data);
        if(stat < 0){
            abpConsultarAno(t->l, key, cmp, data);
        }
        else if(stat > 0){
            abpConsultarAno(t->r, key, cmp, data);
        }

        else{
            *data = t->data;
        }
    }
}


void abpConsultarNome(TNode *t, void *key, int(*cmp)(void *, void *), void **data){
    if(t != NULL){
        int stat = cmp(key, t->data);
        if(stat == 0){
            *data = t->data;
        }
        else{
            abpConsultarNome(t->l, key, cmp, data);
            abpConsultarNome(t->r, key, cmp, data);
        }
    }
}


void abpConsultarNota(TNode *t, void *key, int(*cmp)(void *, void *), void **data){
    if(t != NULL){
        int stat = cmp(key, t->data);
        if(stat == 0){
            *data = t->data;
        }
        else{
            abpConsultarNota(t->l, key, cmp, data);
            abpConsultarNota(t->r, key, cmp, data);
        }
    }
}


