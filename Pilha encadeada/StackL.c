#include "StackL.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _slnode_ {
    void *data;
    //verificar se isso esta certo
    SLNode *next;
}SLNode;

typedef struct _sllist_{
    SLNode *first;
} LStack;




LStack* sllCreate(){
    LStack* l = (LStack *) malloc(sizeof(LStack));
    if(l != NULL){
        l->first = NULL;
        return l;
    }

    return NULL;
}


int sllPush(LStack *l, void *data){
    if(l != NULL){
        SLNode *newnode;
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if(newnode != NULL){

            newnode->data = data;
            newnode->next = NULL;
            if(l->first == NULL){
                l->first = newnode;
            }
            else{
                SLNode *last = l->first;
                while(last->next != NULL){
                    last = last->next;
                }

                last->next = newnode;

            }

            return TRUE;

        }
        
    }

    return FALSE;
}


void *sllPop ( LStack *l){
    if(l != NULL){
        if(l->first != NULL){
            SLNode *last = NULL;
            SLNode *current;
            current = l->first;
            while(current -> next != NULL){
                last = current;
                current = current->next;
            }

            if (last != NULL) {
                last->next = NULL;
            } else {
                
                l->first = NULL;
            }

            return current->data;
        }
    }

    return NULL;
}


void *sllTop(LStack *l){
    if(l != NULL){
        if(l->first != NULL){
            SLNode *current;
            current = l->first;
            while(current -> next != NULL){
                current = current->next;
            }

            return current->data;
        }
    }

    return NULL;
}

int sllDestroy(LStack *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);
            return TRUE;
        }
    }

    return FALSE;
}