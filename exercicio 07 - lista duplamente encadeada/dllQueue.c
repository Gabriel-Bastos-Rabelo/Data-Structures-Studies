#include "dllQueue.h"
#include <stdio.h>
#include <stdlib.h>




typedef struct _dlnode_ {
    struct _dlnode_ *next, *prev;
    void * data;
}DLNode;

typedef struct _dllist_
{
    DLNode *first;
    DLNode *cur;
}DLList;

DLList *dllCreate(){

    DLList *l = (DLList *)malloc(sizeof(DLList));

    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;

}


int dllInsertBeforeSpec( DLList *l, void *key, void * data, int (*cmp)(void *, void *)){
    if(l != NULL){
        if(l -> first != NULL){
            DLNode *current;
            current = l->first;

            while(current != NULL){
                if(cmp(key, current->data)){
                    break;
                }
                current = current -> next;
            }


            if(current != NULL){
                DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                if(newnode != NULL){

                    newnode -> data = data;
                    newnode -> next = current;
                    newnode -> prev = current->prev;
                    current->prev = newnode;

                    if(current -> prev != NULL){

                        current->prev->next = newnode;

                    }
                    else{

                        l->first = newnode;

                    }

                    return TRUE;
                   
                }
            }
        }
    }


    return FALSE;
}


void * dllREmoveAfterSpec( DLList *l, void *key, int (*cmp)(void *, void *)){
    if(l != NULL){
        if(l -> first != NULL){
            DLNode *current;
            DLNode *prox;
            current = l->first;

            while(current != NULL){
                if(cmp(key, current->data)){
                    break;
                }
                current = current -> next;
            }

            if(current != NULL && current->next != NULL){
                void *data = current->next->data;
                prox = current->next;
                current->next = prox->next;
                prox->next->prev = current;
                free(prox);
                return data;    
            }
        }
    }


    return NULL;
}





void * dllREmoveBeforeSpec( DLList *l, void *key, int (*cmp)(void *, void *)){
    if (l != NULL){
        if(l -> first != NULL){
            DLNode *current;
            DLNode *last;
            current = l->first;

            while(current != NULL){
                if(cmp(key, current->data)){
                    break;
                }
                current = current->next;
            }

            if(current != NULL && current -> prev != NULL){
                void *data = current->prev->data;
                last = current->prev;
                current->prev = last->prev;
                last->prev->next = current;
                free(last);
                return data;


            }
        }
    }

    return NULL;
}



