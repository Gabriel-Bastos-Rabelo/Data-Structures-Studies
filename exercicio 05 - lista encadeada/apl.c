#include "Lqueue.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    LQueue *l = sllCreate();
    int elemento = 10;
    printf("%d", InsertAsLast(l, &elemento));


}