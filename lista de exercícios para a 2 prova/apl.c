#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


int main(){


    SLList *sllist = sllcreate();

    int numero = 10;

    int result = sllInsertKPosition(sllist, &numero, 0);
    printf("%d", result);
    
   


}