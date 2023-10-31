#ifndef GCOFO_H
#define GCOFO_H

typedef struct _dllist_
{
    DLNode *first;
    DLNode *cur;
}DLList;


typedef struct _dlnode_ {
    struct _dlnode_ *next, *prev;
    void * data;
}DLNode;


DLList *dllCreate();

int dllDestroy(DLList *l);

int insertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void*));




