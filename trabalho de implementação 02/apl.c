#include "cofo.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{

    Cofo *cofoa = cofCreate(20);
    char string[] = "palmeiras";
    Time *time = createTime(string, 10, 8, 2);
    int inserir = cofInsert(cofoa, time);
    printf("%d", inserir);
    printf("kjkjjk");
}