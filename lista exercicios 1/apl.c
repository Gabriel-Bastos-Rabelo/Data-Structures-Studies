#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    /* testes para a questão 1 a*/

    /*
    Stack *s = stkCreate(5);
    int elemento = 10;
    stkPush(s, &elemento);
    int elm2 = 12;
    stkPush(s, &elm2);
    int elm3 = 13;
    stkPush(s, &elm3);
    int i = 40;
    printf("%d\n", iSegundoElemento(s, &i));
    printf("%d\n", *(int *)stkTop(s));
    */

    /*testes para a questao 1 b*/

    /*
    Stack *s = stkCreate(5);
    int elemento = 10;
    stkPush(s, &elemento);
    int elm2 = 12;
    stkPush(s, &elm2);
    int elm3 = 13;
    stkPush(s, &elm3);
    int i = 40;
    printf("%d\n", iSegundoElementoInalterada(s, &i));
    printf("%d\n", *(int *)stkTop(s));
    printf("%d\n", *(int *)stkPop(s));
    printf("%d\n", *(int *)stkTop(s));*/

    /*teste para a questao 1 c*/
    /*
    Stack *s = stkCreate(5);
    int elemento = 10;
    stkPush(s, &elemento);
    int elm2 = 12;
    stkPush(s, &elm2);
    int elm3 = 13;
    stkPush(s, &elm3);
    int i = 40;
    printf("%d\n", iEnesimoElemento(s, 2, &i));
    printf("%d\n", *(int *)stkTop(s));
    */

    /*teste para a questao 1 d*/

    /*
    Stack *s = stkCreate(5);
    int elemento = 10;
    stkPush(s, &elemento);
    int elm2 = 12;
    stkPush(s, &elm2);
    int elm3 = 13;
    stkPush(s, &elm3);
    int elm4 = 15;
    stkPush(s, &elm4);
    int i = 40;
    printf("%d\n", iEnesimoInalterada(s, 3, &i));
    printf("%d\n", *(int *)stkTop(s));
    */

    // teste para a questao 1 e
    /*
    Stack *s = stkCreate(5);
    int elemento = 10;
    stkPush(s, &elemento);
    int elm2 = 12;
    stkPush(s, &elm2);
    int elm3 = 13;
    stkPush(s, &elm3);
    int elm4 = 15;
    stkPush(s, &elm4);
    int i = 40;
    printf("%d\n", iUltimoElementoVazia(s, &i));
    printf("%d\n", *(int *)stkTop(s));
    */

    // teste para a questao 1 f
    /*
    Stack *s = stkCreate(5);
    int elemento = 10;
    stkPush(s, &elemento);
    int elm2 = 12;
    stkPush(s, &elm2);
    int elm3 = 13;
    stkPush(s, &elm3);
    int elm4 = 15;
    stkPush(s, &elm4);
    int i = 40;
    printf("%d\n", iUltimoElementoInalterada(s, &i));
    printf("%d\n", *(int *)stkTop(s));

    */

    // teste para a questao 1 g
    /*
    Stack *s = stkCreate(5);
    int elemento = 10;
    stkPush(s, &elemento);
    int elm2 = 12;
    stkPush(s, &elm2);
    int elm3 = 13;
    stkPush(s, &elm3);
    int elm4 = 15;
    stkPush(s, &elm4);
    int i = 40;
    printf("%d\n", iterceiroElementoFinal(s, &i));
    printf("%d\n", *(int *)stkPop(s));
    printf("%d\n", *(int *)stkPop(s));
    printf("%d\n", *(int *)stkPop(s));
    printf("%d\n", *(int *)stkPop(s));
    printf("%d\n", *(int *)stkPop(s));

    */

    // testes para a questao 2
    /*
    char frase[] = "ABABCBABA";
    printf("%d\n", xCy(frase));
    char frase2[] = "ABABCBAB";
    printf("%d\n", xCy(frase2));
    char frase3[] = "ABABCBABBBB";
    printf("%d\n", xCy(frase3));
    */

    // testes para a questao 3
    /*
    char frase[] = "ABABDBABDABAB";
    printf("%d", aDbD(frase));
    */

    // testes para a questão 7

    char seq[] = "EDEDEDEDD";
    printf("%d", sequenciaValida(seq));
}
