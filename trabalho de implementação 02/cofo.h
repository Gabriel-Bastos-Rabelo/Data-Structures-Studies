#ifndef GCOFO_H
#define GCOFO_H

typedef struct gcofo {
    int numItens;
    int maxItens;
    int cur;
    void **item;
} gCofo;

gCofo *gcofCreate(int max_itens);
int gcofInsert(gCofo *c, void *item);
void *gcofRemove(gCofo *c, void *key, int (*cmp)(void *, void *));
void *gcofQuery(gCofo *c, void *key, int (*cmp)(void *, void *));
void *gcofGetFirst(gCofo *c);
void *gcofGetNext(gCofo *c);
int gcofDestroy(gCofo *c); 

#endif