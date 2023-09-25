typedef struct _queue_ Queue;

Queue *qcreate(int maxItems);
int qEnqueue(Queue *q, void *data);
int qIsEmpty(Queue *q);
void *qDequeue(Queue *q);
int qDestroy(Queue *q);
void *stkPop( Queue *s);