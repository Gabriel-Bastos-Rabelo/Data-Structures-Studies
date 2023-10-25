#define TRUE 1
#define FALSE 0


typedef struct _dlnode_  DLNode;
typedef struct _dllist_ DLList;

DLList *dllCreate();
int dllDestroy(DLList *);
int dllInsertAfterSpec(DLList *l, void *key, void *data, int(*cmp)(void *, void *));
void * dllRemoveSpec(DLList *l, void *key, int(*cmp)(void *, void *));
int dllDestroyNotEmpty(DLList *l, int(*myfree)(void *));
int dllInsertAsFirst(DLList *l, void *data);
int dllInsertAsLast(DLList *l, void *data);
int dllInsertBeforeSpec( DLList *l, void *key, void * data, int (*cmp)(void *, void *));
void * dllREmoveAfterSpec( DLList *l, void *key, int (*cmp)(void *, void *));
void * dllREmoveBeforeSpec( DLList *l, void *key, int (*cmp)(void *, void *));
