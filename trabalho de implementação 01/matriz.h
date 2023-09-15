#define TRUE 1
#define FALSE 0

typedef struct matriz Matriz;

Matriz *create(int row, int col);
void insert(Matriz *mat, int value, int col, int row);
int *multiplication(Matriz *mata, Matriz *matb);
int destroy(Matriz *mat);
int matGetElemIJ(Matriz *mat, int i, int j);
int *transposta(Matriz *mat);
int getNumCol(Matriz *mat);
int getNumRow(Matriz *mat);