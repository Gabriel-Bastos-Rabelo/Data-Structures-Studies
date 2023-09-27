#include <stdio.h>
#include <stdlib.h>
#include "cqueue.h"

int main()
{
    // testes para a questao 8 c
    /*
    CQueue *q = cqcreate(3);
    int elemento = 1;
    cqEnqueue(q, &elemento);
    int elemento2 = 2;
    int elemento3 = 3;
    cqEnqueue(q, &elemento2);
    cqEnqueue(q, &elemento3);
    removeElementosOrdemImpar(q);
    */
    // testes para a questao 8 e

    /*
    CQueue *q = cqcreate(3);
    int elemento = 1;
    int elemento2 = 2;
    int elemento3 = 3;
    cqEnqueue(q, &elemento);
    cqEnqueue(q, &elemento2);
    cqEnqueue(q, &elemento3);
    punirNPosicoes(q, 2);
    int *value;
    value = (int *)cqDequeue(q);
    printf("%d", *value);
    value = (int *)cqDequeue(q);
    printf("%d", *value);
    value = (int *)cqDequeue(q);
    printf("%d", *value);

    */

    // testes para a questao 10
    /*
    CQueue *q = cqcreate(5);
    int elemento = 1;
    int elemento2 = 2;
    int elemento3 = 3;
    int elemento4 = 4;
    int elemento5 = 5;

    printf("%d", cqEnqueue(q, &elemento));
    printf("%d", cqEnqueue(q, &elemento2));
    printf("%d", cqEnqueue(q, &elemento3));
    printf("%d", cqEnqueue(q, &elemento4));
    printf("%d\n", cqEnqueue(q, &elemento5));

    PuneFuraFila(q);
    int *value;
    value = (int *)cqDequeue(q);
    printf("%d", *value);
    value = (int *)cqDequeue(q);
    printf("%d", *value);
    value = (int *)cqDequeue(q);
    printf("%d", *value);
    value = (int *)cqDequeue(q);
    printf("%d", *value);
    value = (int *)cqDequeue(q);
    printf("%d", *value);
    */

    // testes para a questao 17

    /*
    CQueue *q = cqcreate(5);
    int elemento = 1;
    int elemento2 = 2;
    int elemento3 = 3;
    int elemento4 = 4;
    cqEnqueue(q, &elemento);
    cqEnqueue(q, &elemento2);
    cqEnqueue(q, &elemento3);
    cqEnqueue(q, &elemento4);
    int value = 5;
    FuraFila(q, &value);
    int *result;
    result = (int *)cqDequeue(q);
    printf("%d", *result);

    */
    CQueue *q = cqcreate(5);
    int elemento = 10;
    int elemento2 = 8;
    int elemento3 = 7;
    int elemento4 = 11;
    int elemento5 = 12;
    cqEnqueue(q, &elemento);
    cqEnqueue(q, &elemento2);
    cqEnqueue(q, &elemento3);
    cqEnqueue(q, &elemento4);
    cqEnqueue(q, &elemento5);
    int value = 8;
    printf("%d\n", qRemoveLessThanKey(q, &value));
    printf("%d\n", retornarFront(q));
    printf("%d\n", retornarRear(q));
}