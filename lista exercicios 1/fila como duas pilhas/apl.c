#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    Queue *q = qcreate(5);
    int elemento = 10;
    printf("%d\n", qEnqueue(q, &elemento));
    int elemento2 = 12;
    printf("%d\n", qEnqueue(q, &elemento2));
    int elemento3 = 13;
    printf("%d\n", qEnqueue(q, &elemento3));
    printf("%d\n", *(int *)qDequeue(q));
    printf("%d\n", *(int *)qDequeue(q));
}