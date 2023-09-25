typedef struct _queue_ Queue;

Queue *qcreate(int maxitems);
int qEnqueue(Queue *q, void *data);
int qIsEmpty(Queue *q);
void *qFirst(Queue *q);
void *qDequeue(Queue *q);
int qDestroy(Queue *q);
void *removeElemento(Queue *q, void *x);