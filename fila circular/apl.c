#include <stdio.h>
#include <stdlib.h>
#include "cqueue.h"

int main()
{

    CQueue *c = cqcreate(3);
    int elemento = 10;
    printf("%d\n", cqEnqueue(c, &elemento));
    printf("%d\n", retornarFront(c));
    printf("%d\n", retornarRear(c));
    int *value;
    value = (int *)cqDequeue(c);
    printf("%d\n", *value);
    printf("%d\n", retornarFront(c));
    printf("%d\n", retornarRear(c));

    printf("%d\n", cqEnqueue(c, &elemento));

    printf("%d\n", retornarFront(c));
    printf("%d\n", retornarRear(c));

    printf("%d\n", cqEnqueue(c, &elemento));

    printf("%d\n", retornarFront(c));
    printf("%d\n", retornarRear(c));


    value = (int *)cqDequeue(c);
    printf("%d\n", *value);
    printf("%d\n", retornarFront(c));
    printf("%d\n", retornarRear(c));
}