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

    /* char seq[] = "EDEDEDEDD";
     printf("%d", sequenciaValida(seq));
     */

    /*
        int v1[4] = {1, 2, 3, 4};
        int v2[4] = {2, 5, 6, 3};
        int v3[4];
        MultiplicaMatrizPelaTRansposta(v1, v2, v3, 2);

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                printf("%d ", v3[(i * 2) + j]);
            }

            printf("\n");
        }

        */

    /*
    int v1[4] = {2, 3, 4, 5};
    int v[2] = {2, 3};
    int *v3 = multiMatrizVetor(v1, v, 2);

    for (int i = 0; i < 2; i++)
    {
        printf("%d ", v3[i]);
    }

    */

    // testes para a questao 8 d

    /*
    Stack *s = stkCreate(3);
    int elemento1 = 8;
    int elemento2 = 9;
    int elemento3 = 10;
    int value = 9;
    stkPush(s, &elemento1);
    stkPush(s, &elemento2);
    stkPush(s, &elemento3);
    menorQueChave(s, &value);
    */

    // testes para a questao 10
    /*
    Stack *s = stkCreate(3);
    int elemento1 = 8;
    int elemento2 = 9;
    int elemento3 = 10;
    int value = 2;
    stkPush(s, &elemento1);
    stkPush(s, &elemento2);
    stkPush(s, &elemento3);
    puneNParatraz(s, value);
    printf("%d\n", *(int *)stkPop(s));
    printf("%d\n", *(int *)stkPop(s));
    printf("%d\n", *(int *)stkPop(s));
    */

    // testes para a questao 1 da prova 2023.1

    /*
    char s[] = "ESTE EXERCÍCIO É MUITO FÁCIL.";
    char *string;
    string = inverteString(s, 33);

    for(int i = 0; i < 33; i++){
        printf("%c", string[i]);
    }

    */

   Stack *s = stkCreate(4);
   int elemento = 1;
   int elemento2 = 2;
   int elemento3 = 3;
   int elemento4 = 4;
   stkPush(s, &elemento);
   stkPush(s, &elemento2);
   stkPush(s, &elemento3);
   stkPush(s, &elemento4);
   printf("%d\n", stkPromove(s, 2));
   void *value;
   value = stkTop(s);
   printf("%d\n", *(int *)value);


}
