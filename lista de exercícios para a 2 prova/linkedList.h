typedef struct _dlnode_ {
    struct _dlnode_ *next, *prev;
    void * data;
}DLNode;


typedef struct _dllist_
{
    DLNode *first;
    DLNode *cur;
    
}DLList;


typedef struct _slnode_ {
    struct _slnode_ *next;
    void * data;
}SLNode;


typedef struct _sllist_
{
    SLNode *first;
    SLNode *cur;
    
}SLList;


typedef struct _cslnode_ {
    struct _slnode_ *next;
    void * data;
}CSLNode;


typedef struct _csllist_
{
    CSLNode *first;
    CSLNode *cur;
    
}CSLList;


typedef struct _cdlnode_ {
    struct _slnode_ *next, *prev;
    void * data;
}CDLNode;


typedef struct _cdllist_
{
    CDLNode *first;
    CDLNode *cur;
    
}CDLList;


DLList *dllcreate();
SLList *sllcreate();
CSLList *csllcreate();
CDLList *cdllcreate();
int sllInsertAsFirst(SLList *l, void *data);
int dllInsertAsFirst(DLList *l, void *data);



