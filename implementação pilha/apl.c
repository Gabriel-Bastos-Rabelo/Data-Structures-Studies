#include "stack.h"
#include <stdio.h>
#define TRUE 1
#define FALSE 0
int EYOX(char *s, int n);
int main()
{
    char palavra[] = "ABABOBABA";
    int n = 9;
    int resultado = EYOX(palavra, n);
    printf("%d", resultado);
}

int EYOX(char *s, int n)
{
    Stack *stack = stkCreate(n);
    if (stack != NULL)
    {

        int i = 0;
        while (s[i] != 'O')
        {
            stkPush(stack, s[i]);
            
            i++;
        }
        i++;
        char c = stkPop(stack);
        while (i < n && c != '\0')
        {
            printf("%c e %c", c, s[i]);
            if (c != s[i])
            {
                return FALSE;
            }

            c = stkPop(stack);
            i++;
        }

        if (i >= n && c == '\0')
        {
            return TRUE;
        }
    }

    return FALSE;
}
