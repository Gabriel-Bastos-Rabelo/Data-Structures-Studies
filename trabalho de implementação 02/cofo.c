#include <stdlib.h>
#include <stdio.h>
#include "cofo.h"
#define FALSE 0
#define TRUE 1

gCofo *gcofCreate(int max_itens) {
    gCofo *gc;
    if (max_itens > 0) {
        gc = (gCofo *)malloc(sizeof(gCofo));
        if (gc != NULL) {
            gc->item = (void **)malloc(sizeof(void *) * max_itens);
            if (gc->item != NULL) {
                gc->numItens = 0;
                gc->maxItens = max_itens;
                gc->cur = -1;
                return gc;
            }
            free(gc);
        }
    }
    return NULL;
}

int gcofDestroy(gCofo *gc) {
    if (gc != NULL) {
        if (gc->numItens == 0) {
            free(gc->item);
            free(gc);
            return TRUE;
        }
    }
    return FALSE;
}

int gcofInsert(gCofo *gc, void *item) {
    if (gc != NULL) {
        if (gc->numItens < gc->maxItens) {
            gc->item[gc->numItens] = item;
            gc->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void *gcofQuery(gCofo *c, void *key, int (*cmp)(void *, void *)) {
    void *data;
    int i, stat;
    if (c != NULL) {
        if (c->numItens > 0) {
            i = 0;
            stat = cmp(key, c->item[i]);
            while (i < c->numItens && stat != TRUE) {
                
                stat = cmp(key, c->item[i]);
                i++;
            }
            if (stat == TRUE) {
                data = c->item[i];
                return data;
            }
        }
    }
    return NULL;
}

void *gcofRemove(gCofo *c, void *key, int (*cmp)(void *, void *)) {
    int i;
    void *data;
    int stat;
    if (c != NULL) {
        if (c->numItens > 0) {
            i = 0;
            stat = cmp(key, c->item[i]);
            while (i < c->numItens && stat != TRUE) {
                i++;
                stat = cmp(key, c->item[i]);
            }

            if (stat == TRUE) {
                data = c->item[i];
                for (int j = i; j < c->numItens - 1; j++) {
                    c->item[j] = c->item[j + 1];
                }
                c->numItens--;
                return data;
            }
        }
    }
    return NULL;
}

void *gcofGetFirst(gCofo *gc) {
    if (gc != NULL) {
        if (gc->numItens > 0) {
            gc->cur = 0;
            return gc->item[gc->cur];
        }
    }
    return NULL;
}

void *gcofGetNext(gCofo *gc) {
    if (gc != NULL) {
        if (gc->cur < gc->numItens - 1) {
            gc->cur++;
            return gc->item[gc->cur];
        }
    }
    return NULL;
}