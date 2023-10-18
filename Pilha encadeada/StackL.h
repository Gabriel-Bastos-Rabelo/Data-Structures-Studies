#define TRUE 1;
#define FALSE 0;

typedef struct _slnode_ SLNode;
typedef struct _sllist_ LStack;

LStack* sllCreate();
int sllPush(LStack *l, void *data);
void *sllPop ( LStack *l);
void *sllTop ( LStack *l);
int sllDestroy( LStack *l );

