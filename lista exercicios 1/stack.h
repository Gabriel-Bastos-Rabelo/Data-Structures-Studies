typedef struct _stack_ Stack;
Stack *stkCreate(int max);
int stkPush(Stack *s, void *elm);
void *stkPop(Stack *s);
void *stkTop(Stack *s);
int stkIsEmpty(Stack *s);
int stkDestroy(Stack *s);
int iSegundoElemento(Stack *s, void *i);
int iSegundoElementoInalterada(Stack *s, void *i);
int iEnesimoElemento(Stack *s, int n, void *i);
int iEnesimoInalterada(Stack *s, int n, void *i);
int iUltimoElementoVazia(Stack *s, void *i);
int iUltimoElementoInalterada(Stack *s, void *i);
int iterceiroElementoFinal(Stack *s, void *i);
int xCy(void *frase);
int aDbD(void *frase);
int sequenciaValida(void *seq);
int menorQueChave(Stack *s, void *value);
int puneNParatraz(Stack *s, int n);
char *inverteString(char *s, int n);
int stkPromove(Stack * s, int n);

