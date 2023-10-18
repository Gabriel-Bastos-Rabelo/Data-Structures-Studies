#include "StackL.h"
#include <stdio.h>
#include <stdlib.h>




int main(){

    LStack *pilhaEncadeada = sllCreate();
    int elemento = 10;
    int elemento2 = 11;
    int elemento3 = 12;
    int elemento4 = 13;
    int elemento5 = 14;
    int elemento6 = 15;
    sllPush(pilhaEncadeada, &elemento);
    sllPush(pilhaEncadeada, &elemento2);
    sllPush(pilhaEncadeada, &elemento3);
    sllPush(pilhaEncadeada, &elemento4);
    sllPush(pilhaEncadeada, &elemento5);
    sllPush(pilhaEncadeada, &elemento6);


    printf("%d", *(int *)sllPop(pilhaEncadeada));
    printf("%d", *(int *)sllPop(pilhaEncadeada));
    printf("%d", *(int *)sllPop(pilhaEncadeada));
    printf("%d", *(int *)sllPop(pilhaEncadeada));
    printf("%d", *(int *)sllPop(pilhaEncadeada));
    printf("%d", *(int *)sllTop(pilhaEncadeada));

}