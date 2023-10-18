#define TRUE 1
#define FALSE 0

typedef struct _slnode_ SLNode;
typedef struct _lqueue_ LQueue;

LQueue * sllCreate();
int lQueueDestroy(LQueue *l);
int lqInsertFirst(LQueue *l, void * data);
int InsertAsLast(LQueue *lq, void *data);
void *RemoveFirst(LQueue *lq);
void *GetFirst(LQueue *lq);
int sllNumElms( LQueue *l);
int sllBeforeSpecified( LQueue *l, void *key, void *data, int (*cmp)(void *, void *));
int sllInsertAfterSpecified( LQueue *l, void *key, void *data, int (*cmp)(void *, void *));