#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{

    // testes para a questão 6
    Queue *q = qcreate(3);
    int elemento = 10;
    int elemento2 = 11;
    int elemento3 = 12;
    printf("%d\n", qEnqueue(q, &elemento));
    printf("%d\n", qEnqueue(q, &elemento2));
    printf("%d\n", qEnqueue(q, &elemento3));
    int elementoRetirar = 11;

    void *value = removeElemento(q, &elementoRetirar);
    if (value == NULL)
    {
        printf("O valor não pode ser removido ou não foi encontrado\n");
    }
    else
    {
        printf("%d\n", *(int *)value);
    }
    printf("%d\n", *(int *)qDequeue(q));
    printf("%d\n", *(int *)qDequeue(q));
}