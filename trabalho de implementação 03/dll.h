


typedef struct _dlnode_ {
    struct _dlnode_ *next, *prev;
    void * data;
}DLNode;


typedef struct _dllist_
{
    DLNode *first;
    
}DLList;


DLList *dllCreate();

int dllDestroy(DLList *l);



int dllinsertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void*));
int dllInsertAsLast(DLList *l, void *data);
void* removeSpec(DLList *l, void *key, int(*cmp)(void *, void*));
void* dllQuery(DLList *l, void *key, int(*cmp)(void *, void*));
void* removeLast(DLList *l);
int esvaziarLista(DLList *l);
void* dllGetFirst(DLList *l);
void* dllGetNext(DLNode *node);





