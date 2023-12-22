

typedef struct tnode{
  void* data;
  struct tnode *l;
  struct tnode *r;
}TNode;

TNode* abpCreate();
void abpDestroyIfEmpty(TNode *t);
void abpEsvaziar(TNode *t);
TNode *abpInsert(TNode *t, void *data, int(*cmp)(void *, void*));
TNode *abpRemoveMaior(TNode *t, int(*cmp)(void *, void *), void **data);
TNode *abpRemoveAno(TNode *t, void *key, int(*cmp)(void *, void *), void **data);
TNode *abpRemoveNome(TNode *t, void *key, int(*cmp)(void *, void *), void **data);
TNode *abpRemoveNota(TNode *t, void *key, int(*cmp)(void *, void *), void **data);
void abpConsultarNome(TNode *t, void *key, int(*cmp)(void *, void *), void **data);
void abpConsultarAno(TNode *t, void *key, int(*cmp)(void *, void *), void **data);
void abpConsultarNota(TNode *t, void *key, int(*cmp)(void *, void *), void **data);

