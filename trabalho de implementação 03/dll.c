#include "dll.h"

DLList* dllCreate(){
    l = (DLList *)malloc(sizeof(DLList));

    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}


int dllDestroy(DLList *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);
            return TRUE;
        }
    }

    return FALSE;
}


int insertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void*)){
    if(l != NULL){
        if(l -> first != NULL && key != NULL && data != NULL){

            DLNode *spec;

            spec = l->first;

            int stat = cmp(key, spec->data)

            while(stat != TRUE && spec->next != NULL){
                spec = spec -> next;
                stat = cmp(key, spec->data);
            }



            if(stat == TRUE){
                DLNode *newnode = (DLNode *)malloc(sizeof(DLNode *));
                if(newnode != NULL){
                    newnode -> data = data;
                    newnode -> prev = spec;
                    newnode -> next = spec->next;
                    spec->next = newnode;

                    if(spec -> next != NULL){
                        spec->next->prev = newnode;
                    }

                    return TRUE;
                }
            }
            
        }
    }


    return FALSE;
}


int dllInsertAsLast(DLList *l, void *data){
    if(l != NULL){
       if(l -> first  == NULL){
            DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
            newnode->data = data;
            newnode->prev = NULL;
            newnode -> next = NULL;
            l->first = newnode;

            return TRUE;
       }
       else{
            DLNode *current;
            current = l->first;

            while(current -> next != NULL){
                current = current -> next;
            }

            DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
            newnode -> data = data;
            newnode -> next = NULL;
            newnode -> prev = current;

            current->next = newnode;


            return TRUE;


       }

    }

    return FALSE;
}
