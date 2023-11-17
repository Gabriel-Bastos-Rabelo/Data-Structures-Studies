#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

DLList* dllCreate(){
    DLList *l = (DLList *)malloc(sizeof(DLList));

    if(l != NULL){
        l->first = NULL;
        
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


int dllinsertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void*)){
    if(l != NULL){
        if(l -> first != NULL && key != NULL && data != NULL){

            DLNode *spec;

            spec = l->first;

            int stat = cmp(key, spec->data);

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
        DLNode *last;
        if(l -> first  == NULL){
            last = NULL;
        }

        else{
            last = l->first;

            while(last -> next != NULL){
                last = last->next;
            }
        }

        DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));

        if(newnode != NULL){
            newnode -> data = data;
            newnode -> next = NULL;
            

            if(last == NULL){
                l->first = newnode;
                newnode->prev = NULL;
            }
            else{
                last -> next = newnode;
                newnode -> prev = last;
            }

            

            return TRUE;
        }

       

    }

    
    return FALSE;
         
}


void* removeSpec(DLList *l, void *key, int(*cmp)(void *, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            DLNode *last;
            last = l->first;
            int stat = cmp(key, last->data);
            while(stat != TRUE && last->next != NULL){
                last = last->next;
                stat = cmp(key, last->data);
            }

            if(stat == TRUE){
                DLNode *data = last->data;
                DLNode *next = last->next;
                DLNode *prev = last->prev;

                if(next != NULL){
                    next->prev = prev;
                }

                if(prev != NULL){
                    prev->next = next;
                }
                else{
                    l->first = next;
                }


                free(last);
                return data;


            }
        }
    }

    return NULL;
}


void* removeLast(DLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            DLNode *spec;
            spec = l->first;

            while(spec -> next != NULL){
                spec = spec -> next;
            }

            void *data = spec->data;
            if(spec->prev == NULL){
                l->first = NULL;
            }
            else{
                spec->prev->next = NULL;
            }

            return data;
        }
    }


    return NULL;

}


int esvaziarLista(DLList *l){
    if(l != NULL){
        if(l -> first != NULL){

            while(l -> first != NULL){
                removeLast(l);
            }

            return TRUE;
        }
    }

    return FALSE;
}




void* dllGetFirst(DLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            return l->first;
        }
    }


    return NULL;
}


void* dllGetNext(DLNode *node){

    if(node != NULL){
        return node->next;
    }

    return NULL;


}


DLList *queryByName(DLList *l, void *key, int(*cmp)(void *, void*)){
    if(l != NULL){
        DLList *aux = dllCreate();

        if(aux != NULL){
            DLNode *current = l->first;
            if(current != NULL){
                int stat = cmp(key, current->data);
                if(stat){
                    
                    dllInsertAsLast(aux, current->data);
                }


                while(current -> next != NULL){
                    current = current -> next;
                    stat = cmp(key, current->data);
                    if(stat){
                        
                        dllInsertAsLast(aux, current->data);
                    }
                    
                }

                return aux;
            }


        }
    }

    return NULL;
}

DLList *queryByYear(DLList *l, int key, int(*cmp)(int, void*)){
    if(l != NULL){
        DLList *aux = dllCreate();

        if(aux != NULL){
            DLNode *current = l->first;
            if(current != NULL){
                int stat = cmp(key, current->data);
                if(stat){
                    
                    dllInsertAsLast(aux, current->data);
                }


                while(current -> next != NULL){
                    current = current -> next;
                    stat = cmp(key, current->data);
                    if(stat){
                        
                        dllInsertAsLast(aux, current->data);
                    }
                    
                }

                return aux;
            }


        }
    }

    return NULL;
}


DLList *queryByImdb(DLList *l, float key, int(*cmp)(float, void*)){
    if(l != NULL){
        DLList *aux = dllCreate();

        if(aux != NULL){
            DLNode *current = l->first;
            if(current != NULL){
                int stat = cmp(key, current->data);
                if(stat){
                    
                    dllInsertAsLast(aux, current->data);
                }


                while(current -> next != NULL){
                    current = current -> next;
                    stat = cmp(key, current->data);
                    if(stat){
                        
                        dllInsertAsLast(aux, current->data);
                    }
                    
                }

                return aux;
            }


        }
    }

    return NULL;
}


DLList *removeByName(DLList *l, void *key, int(*cmp)(void *, void *)){
    if(l != NULL){
        DLList *aux = dllCreate();

        if(aux != NULL){
            DLNode *current = l->first;
            if(current != NULL){
                int stat = cmp(key, current->data);
                if(stat){
                    
                    dllInsertAsLast(aux, current->data);
                    
                }


                while(current -> next != NULL){
                    current = current -> next;
                    stat = cmp(key, current->data);
                    if(stat){
                        
                        dllInsertAsLast(aux, current->data);
                        
                    }
                    
                }
                current = aux -> first;

                while(current != NULL){
                    removeNode(l, current);
                    current = current -> next;
                }
                return aux;
            }


        }
    }

    return NULL;
}

DLList *removeByYear(DLList *l, int key, int(*cmp)(int, void *)){
    if(l != NULL){
        DLList *aux = dllCreate();

        if(aux != NULL){
            DLNode *current = l->first;
            if(current != NULL){
                int stat = cmp(key, current->data);
                if(stat){
                    
                    dllInsertAsLast(aux, current->data);
                    
                }


                while(current -> next != NULL){
                    current = current -> next;
                    stat = cmp(key, current->data);
                    if(stat){
                        
                        dllInsertAsLast(aux, current->data);
                        
                    }
                    
                }
                current = aux -> first;

                while(current != NULL){
                    removeNode(l, current);
                    current = current -> next;
                }
                return aux;
            }


        }
    }

    return NULL;
}


DLList *removeByImdb(DLList *l, float key, int(*cmp)(float, void *)){


    if(l != NULL){
        DLList *aux = dllCreate();

        if(aux != NULL){
            DLNode *current = l->first;
            if(current != NULL){
                int stat = cmp(key, current->data);
                if(stat){
                    
                    dllInsertAsLast(aux, current->data);
                    
                }


                while(current -> next != NULL){
                    current = current -> next;
                    stat = cmp(key, current->data);
                    if(stat){
                        
                        dllInsertAsLast(aux, current->data);
                        
                    }
                    
                }

                
                return aux;
            }


        }
    }

    return NULL;

}


int removeNode(DLList *l, DLNode *n){
    if(l != NULL){
        if(l -> first != NULL){
            if(l -> first == n){
                l->first = n -> next;
            }
            else{
                n->prev->next = n->next;
                if(n -> next != NULL){
                    n->next->prev = n->prev;
                }
            }
            free(n);
            return TRUE;
        }
    }

    return FALSE;
}