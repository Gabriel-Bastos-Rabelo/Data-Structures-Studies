#include "Lqueue.h"
#include <stdio.h>
#include <stdlib.h>




typedef struct _slnode_ {
    void *data;
    struct _slnode_ *next;
} SLNode;

typedef struct _lqueue_ {
    SLNode *first;
}LQueue;


LQueue * sllCreate(){
    LQueue *l;
    l = (LQueue * ) malloc(sizeof(LQueue ));
    if ( l != NULL ) {
        l->first = NULL;
        return l;
    }
}


int lQueueDestroy(LQueue *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);
            return TRUE;
        }
    }


    return FALSE;
}


int lqInsertFirst(LQueue *l, void * data){
    SLNode *n;
    if(l != NULL){
        n = (SLNode *)malloc(sizeof(SLNode));
        if(n != NULL){
            n -> data = data;
            n -> next = l->first;
            l -> first = n;
            return TRUE;
        }
    }


    return FALSE;
}




int InsertAsLast(LQueue *lq, void *data){
    SLNode *newnode;
    SLNode *last;
    if(lq != NULL){
        newnode = (SLNode *)malloc(sizeof(SLNode));
        newnode -> data = data;
        newnode -> next = NULL;
        if(lq -> first == NULL){
            lq -> first = newnode;
            return TRUE;
        }
        else{
            last = lq -> first;
            while(last != NULL){
                last = last -> next;
            }

            last -> next = newnode;

            return TRUE;
        }

    }
    return FALSE;
}


void *RemoveFirst(LQueue *lq){
    if(lq != NULL){
        SLNode *first;
        void *data;
        first = lq->first;
        data = first;
        lq->first = first->next;
        free(first);
        return data;
    }

    return NULL;
}


void *GetFirst(LQueue *lq){
    if(lq != NULL){
        if(lq -> first != NULL){
            return (lq->first)->data;
        }
    }

    return NULL;
}



int sllNumElms( LQueue *l){

    if(l != NULL){
        SLNode *current;
        if(l -> first != NULL){
            current = l->first;
            int i = 1;
            while(current != NULL){
                current = current -> next;
                i++;
            }

            return i;
        }
    }

    return 0;
}


