#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"
#define TRUE 1
#define FALSE 0

/*
Roteiro para teste:

1 - Crie uma coleção
2 - Insira tres elementos na coleção
3- Liste os elementos da Colecao
4 - Consulte um dos elementos da coleçào
5 - remova o segundo elemento inserido na colecao
6- Liste os elementos da coleçào
7 - Esvazie a colecao
8- Liste os elementos da coleção

*/

int compareByName(void *key, void *data);

typedef struct
{
    char nome[30];
    int anoLancamento;
    float imdb;
} Filme;

int main()
{

    int n = 0;
    DLList *dllCollection = NULL;

    while (TRUE)
    {
        printf("Digite 1 para criar uma coleção\n");
        printf("Digite 2 para inserir um Filme na coleção\n");
        printf("Digite 3 para remover um Filme da coleção\n");
        printf("Digite 4 para ver um Filme na coleção\n");
        printf("Digite 5 para listar os elementos da coleção\n");
        printf("Digite 6 para esvaziar a coleção\n");
        printf("Digite 7 para destruir a coleção\n");
        printf("Digite 8 para sair\n");
        scanf("%d", &n);

        if (n == 8)
        {
            break;
        }

        switch (n)
        {
        case 1:
        {
            dllCollection = dllCreate();
            if (dllCollection != NULL)
            {
                printf("Coleção criada com sucesso!\n");
            }
            else
            {
                printf("Falha na criação da coleção\n");
            }

            break;
        }

        case 2:
        {
            if (dllCollection != NULL)
            {

                Filme *novoFilme = (Filme *)malloc(sizeof(Filme));
                printf("Digite o nome do filme: \n");
                while ((getchar()) != '\n')
                    ;
                fgets(novoFilme->nome, sizeof(novoFilme->nome), stdin);

                size_t len = strlen(novoFilme->nome);
                if (len > 0 && novoFilme->nome[len - 1] == '\n')
                {
                    novoFilme->nome[len - 1] = '\0';
                }

                printf("Digite o ano de lançamento: \n");
                scanf("%d", &novoFilme->anoLancamento);

                printf("Digite a nota imdb do filme: \n");
                scanf("%f", &novoFilme->imdb);

                if (dllInsertAsLast(dllCollection, novoFilme) == TRUE)
                {
                    printf("Filme adicionado a coleção com sucesso\n");
                }
                else
                {
                    printf("Falha ao adicionar o filme na coleção\n");
                    free(novoFilme);
                }
            }
            else
            {
                printf("Crie uma coleção antes!\n");
            }

            break;
        }

        case 3:
        {

            if (dllCollection != NULL)
            {
                printf("Digite o nome do filme a ser removido: \n");

                char key[30];

                while ((getchar()) != '\n')
                    ;
                fgets(key, sizeof(key), stdin);

                size_t len = strlen(key);
                if (len > 0 && key[len - 1] == '\n')
                {
                    key[len - 1] = '\0';
                }

                Filme *FilmeRemovido = (Filme *)removeSpec(dllCollection, &key, compareByName);

                if (FilmeRemovido != NULL)
                {
                    printf("Filme removido com sucesso\n");
                }
                else
                {
                    printf("Filme não foi encontrado\n");
                }
            }
            else
            {
                printf("Crie uma coleção antes!\n");
            }

            break;
        }

        case 4:
        {
            if (dllCollection != NULL)
            {
                printf("Digite o nome do filme a ser buscado: \n");
                char key[30];

                while ((getchar()) != '\n')
                    ;
                fgets(key, sizeof(key), stdin);

                size_t len = strlen(key);
                if (len > 0 && key[len - 1] == '\n')
                {
                    key[len - 1] = '\0';
                }

                Filme *FilmeBuscado = (Filme *)dllQuery(dllCollection, key, compareByName);

                if (FilmeBuscado != NULL)
                {
                    printf("Filme Encontrado\n");
                    printf("Nome: %s\n", FilmeBuscado->nome);
                    printf("Ano de lançamento: %d\n", FilmeBuscado->anoLancamento);
                    printf("Nota imdb: %f\n", FilmeBuscado->imdb);
                }
                else
                {
                    printf("Filme não encontrado\n");
                }
            }
            else
            {
                printf("Crie uma coleção antes!\n");
            }

            break;
        }

        case 5:
        {

            if (dllCollection != NULL)
            {

                DLNode *current = dllGetFirst(dllCollection);
                Filme *filme;

                while (current != NULL)
                {
                    filme = current->data;
                    printf("Nome: %s\n", filme->nome);
                    printf("Ano de lançamento: %d\n", filme->anoLancamento);
                    printf("Nota imdb: %f\n", filme->imdb);
                    printf("------------------------------------\n\n");
                    current = dllGetNext(current);
                }
            }
            else
            {
                printf("Crie uma coleção antes!\n");
            }

            break;
        }

        case 6:
        {
            if (dllCollection != NULL)
            {
                if (esvaziarLista(dllCollection))
                {
                    printf("Coleção esvaziada com sucesso!!\n");
                }
                else
                {
                    printf("Falha ao esvaziar a coleção\n");
                }
            }
            else
            {
                printf("Crie uma coleção antes!\n");
            }

            break;
        }

        case 7:
        {
            if (dllCollection != NULL)
            {
                if (dllDestroy(dllCollection))
                {
                    printf("Coleção destruída com sucesso!!\n");
                    dllCollection = NULL;
                }
                else
                {
                    printf("Falha ao destruir a coleção\n");
                }
            }
            else
            {
                printf("Crie uma coleção antes!\n");
            }

            break;
        }

        default:
        {
            printf("Opção inválida\n");
            break;
        }
        }
    }
}

int compareByName(void *key, void *data)
{
    char *keyStr = (char *)key;
    Filme *dataItem = (Filme *)data;

    if (strcmp(keyStr, dataItem->nome) == 0)
    {
        return TRUE;
    }
    return FALSE;
}
