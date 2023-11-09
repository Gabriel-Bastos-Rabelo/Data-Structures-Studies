#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0



DLList *dllcreate(){
    DLList *l = (DLList *)malloc(sizeof(DLList));

    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}


SLList *sllcreate(){
    SLList *l = (SLList *)malloc(sizeof(SLList));

    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}



CDLList *cdllcreate(){
    SLList *l = (CDLList *)malloc(sizeof(CDLList));

    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}

CSLList *csllcreate(){
    SLList *l = (CSLList *)malloc(sizeof(CSLList));

    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}


//questão 1 letra a

//para lista encadeada simples
int sllInsertAsFirst(SLList *l, void *data){
    if(l != NULL){
        SLNode *newnode = (SLNode*)malloc(sizeof(SLNode));

        if(newnode != NULL){
            newnode->data = data;
            newnode->next = l->first;
            l->first = newnode;
            return TRUE;
        }
    }

    return FALSE;
}

//para lista duplamente encadeada
int dllInsertAsFirst(DLList *l, void *data){
    if(l != NULL){
        DLNode *newnode = (DLNode*)malloc(sizeof(DLNode));
        DLNode *next;

        if(newnode != NULL){
            newnode->data = data;
            newnode->next = l->first;
            newnode->prev = NULL;
            next = l->first;
            if(next != NULL){
                next->prev = newnode;
            }
            l->first = newnode;
            return TRUE;
        }
    }

    return FALSE;
}

//para lista circular simplesmente encadeada

int csllInsertAsFirst(CSLList *l, void *data){
    //tenho que fazer o next do novonode apontar para o primeiro, o l->first 
    //apontar para o novonode e no prev do current last apontar para o novonode
    //caso especial, se não tiver nenhum elemento
    //caso especial, se tiver somente um elemento
    if(l != NULL){
        CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
        CSLNode *current;

        if(newnode != NULL){
            newnode->data = data;
            
           

            current = l->first;

            if(current == NULL){
                newnode->next = newnode;
            }

            else{

                while(current->next != l->first){
                    current = current->next;
                }

                newnode->next = l->first;
                current->next = newnode;
            }

            l->first = newnode;

            return TRUE;

        }

    }

    return FALSE;
}


//para lista circular duplamente encadeada
int cdllInsertAsFirst(CDLList *l, void *data){

    if(l != NULL){
        CDLNode* newnode = (CDLNode*)malloc(sizeof(CDLNode));
        CDLNode *current;

        if(newnode != NULL){
            newnode->data = data;

            current = l->first;

            if(current == NULL){
                newnode->next = newnode;
                newnode->prev = newnode;
            }
            else{
                while(current->next != l->first){
                    current = current->next;
                }

                current->next = newnode;
                l->first->prev = newnode;
                newnode->next = l->first;
                newnode->prev = current;
            }

            l->first = newnode;

            return TRUE;

        }
    }

    return FALSE;
}

