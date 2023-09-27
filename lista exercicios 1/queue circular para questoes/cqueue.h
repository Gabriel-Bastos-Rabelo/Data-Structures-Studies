typedef struct _cqueue_ CQueue;

CQueue *cqcreate(int maxitems);
int cqEnqueue(CQueue *q, void *data);
int cqIsEmpty(CQueue *q);
void *cqFirst(CQueue *q);
void *cqDequeue(CQueue *q);
int cqDestroy(CQueue *q);
int incCirc(int i, int max);
int retornarRear(CQueue *q);
int retornarFront(CQueue *q);
int removeElementosOrdemImpar(CQueue *q);
int decCirc(int i, int max);

int punirNPosicoes(CQueue *q, int n);

int PuneFuraFila(CQueue *f);

int primeiroElmPrimeiraPos(CQueue *f);
int FuraFila(CQueue* q, void *value);
int qRemoveLessThanKey (CQueue * q, void * key);
