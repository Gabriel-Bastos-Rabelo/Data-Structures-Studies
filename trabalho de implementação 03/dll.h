


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
DLList *removeByName(DLList *l, void *key, int(*cmp)(void *, void *));
DLList *removeByYear(DLList *l, int key, int(*cmp)(int, void *));
DLList *removeByImdb(DLList *l, float key, int(*cmp)(float, void *));
int removeNode(DLList *l, DLNode *n);
void* removeLast(DLList *l);
int esvaziarLista(DLList *l);
void* dllGetFirst(DLList *l);
void* dllGetNext(DLNode *node);
DLList *queryByName(DLList *l, void *key, int(*cmp)(void *, void*));
DLList *queryByYear(DLList *l, void *key, int(*cmp)(void*, void*));
DLList *queryByImdb(DLList *l, void *key, int(*cmp)(void*, void*));





