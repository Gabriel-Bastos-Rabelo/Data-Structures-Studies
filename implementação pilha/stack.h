typedef struct _stack_ Stack;
Stack *stkCreate(int max);
int stkPush(Stack *, char elm);
char stkPop(Stack *s);
char stkTop(Stack *s);
int stkIsEmpty(Stack *s);
int stkDestroy(Stack *s);