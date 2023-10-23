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

int sllInsertAfterSpecified( LQueue *l, void *key, void *data, int (*cmp)(void *, void *)){
    if(l != NULL){
        if(l -> first != NULL){
            SLNode * current;
            SLNode * newnode;

            current = l -> first;
            while(cmp(current->data, key) == FALSE){
                current = current -> next;

            }

            newnode = (SLNode *)malloc(sizeof(SLNode));
            if(newnode != NULL){

                newnode->data = data;
                newnode->next = current->next;
                current->next = newnode;
                return TRUE;


            }
           
        }
    }

    return FALSE;
}


int sllBeforeSpecified( LQueue *l, void *key, void *data, int (*cmp)(void *, void *)){
    if(l != NULL){
        if(l -> first != NULL){
            SLNode *last;
            SLNode *current;
            SLNode *newnode;
            current = l -> first;
            last = NULL;
        

            while(cmp(current->data, key) == FALSE){
                last = current;
                current = current->next;
                
            }

            newnode = (SLNode *)malloc(sizeof(SLNode));
            if(newnode != NULL){
                newnode->data = data;
                newnode->next = current;
                if(last != NULL){
                    last->next = newnode;
                }
                else{
                    l->first = newnode;
                }
                
            
                return TRUE;
            }


        }
    }

    return FALSE;
}


int sllInsertAfterPEsimo(LQueue *l, int p, void *data){
    if(l != NULL){
        if(l->first != NULL){

            int i = 0;

            SLNode *aux = l->first;

            while(i < p && aux->next != NULL){

                aux = aux -> next;
                i++;
            }

            SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));

            if(newnode != NULL){
                newnode->data = data;
                newnode->next = aux->next;
                aux->next = newnode;
                return TRUE;
            }
        }



    }
       

    return FALSE;
}


int sllInsetBeforePEsimo(LQueue *l, int p, void *data){
    if(l != NULL){
        if(l->first != NULL){
            SLNode *current;
            SLNode *last;

            last = NULL;
            current = l->first;

            int i = 0;
            while(i < p && current -> next != NULL){
                last = current;
                current = current->next;
                i++;
            }

            SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));

            if(newnode != NULL){

                newnode->data = data;
                newnode->next = current;

                if(last != NULL){
                    
                    last->next = newnode;
                }
                else{
        
                    l->first = newnode;
                }


                return TRUE;
                
        
            }


        }
    }

    return FALSE;
}

void* sllRemovePEsimo(LQueue *l, int p){
    if(l != NULL){
        if(l -> first != NULL){
            SLNode *last;
            SLNode *current;

            last = NULL;
            current = l->first;

            int i = 0;

            while(i < p && current->next != NULL){
                last = current;
                current = current->next;
                i++;
            }

            void *data = current->data;

            if(last != NULL){
                last->next = current->next;
                current->next = NULL;
            }
            else{
                l->first = current->next;
            }

            free(current);
            return data;

            
        }
    }

    return NULL;
}

void *sllQuerySpec(LQueue *l, void *key, int (*cmp)(void *, void *)){
    if(l != NULL){
        if(l -> first != NULL){

            SLNode *current;
            current = l-> first;

            int achou = FALSE;

            while(current -> next != NULL){

                if(cmp(current->data, key)){
                    achou = TRUE;
                    break;
                }

                current = current->next;

            }

            if(achou){

                void *data = current->data;
                return data;

            }



        }
    }

    return NULL;
}


void *sllRemoveSpec(LQueue *l, void *key, int (*cmp)(void *, void*)){
    if(l != NULL){
        if(l->first != NULL){
            SLNode *current;
            SLNode *last;
            last = NULL;
            current = l->first;


            int achou = FALSE;

            while(current->next != NULL){
                last = current;
                if(cmp(current->data, key)){
                    achou = TRUE;
                    break;

                }

                current = current->next;
            }

            if(achou){

                void *data = current->data;
                if(last != NULL){
                    last->next = current->next;
                }

                else{
                    l->first = current->next;
                }

                free(current);
                return data;

            }
        }
    }

    return NULL;
}

