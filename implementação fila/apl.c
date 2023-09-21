#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{

    Queue *q = qcreate(10);
    int valor = 8;
    int botou = qEnqueue(q, &valor);
    printf("%d", botou);
    int valor2 = 10;
    botou = qEnqueue(q, &valor2);

    printf("%d", botou);

    int *value = (int *)qDequeue(q);
    printf("%d", *value);
    value = (int *)qDequeue(q);
    printf("%d", *value);
}