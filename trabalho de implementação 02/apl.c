#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cofo.h"
#define TRUE 1
#define FALSE 0

typedef struct
{
    char nome[30];
    int anoLancamento;
    float imdb;
} Filme;

int compararFilmes(void *chave, void *elemento)
{
    char *chaveNome = (char *)chave;
    Filme *filme = (Filme *)elemento;
    int stat = strcmp(chaveNome, filme->nome);
    if (stat == 0)
    {
        return TRUE;
    }
    return FALSE;
}

int main(void)
{
    int n = 0;
    gCofo *cofo = NULL;

    while (TRUE)
    {

        printf("Digite 1 para criar um cofo\n");
        printf("Digite 2 para inserir um Filme no cofo\n");
        printf("Digite 3 para remover um Filme do cofo\n");
        printf("Digite 4 para ver um Filme no cofo\n");
        printf("Digite 5 para listar os elementos do cofo\n");
        printf("Digite 6 para esvaziar o cofo\n");
        printf("Digite 7 para destruir o cofo\n");
        printf("Digite 8 para sair\n");
        int result = scanf("%d", &n);
        if (result == 1)
        {
            switch (n)
            {
            case 1:
            {
                int maxFilmes;
                printf("Digite o número máximo de Filmes no cofo: ");
                if (scanf("%d", &maxFilmes) == 1)
                {
                    cofo = gcofCreate(maxFilmes);
                    if (cofo != NULL)
                    {
                        printf("Cofo de Filmes criado com sucesso.\n");
                    }
                    else
                    {
                        printf("Falha ao criar o cofo de Filmes.\n");
                    }
                }
                else
                {
                    printf("Entrada inválida. Por favor, digite um número inteiro.\n");
                }
                break;
            }
            case 2:
            {
                if (cofo == NULL)
                {
                    printf("O cofo de Filmes não foi criado. Crie um cofo primeiro (opção 1).\n");
                }
                else
                {
                    if (cofo->numItens < cofo->maxItens)
                    {
                        Filme *novoFilme = (Filme *)malloc(sizeof(Filme));
                        if (novoFilme != NULL)
                        {
                            printf("Digite o nome do Filme: ");
                           
                            while ((getchar()) != '\n');
                            fgets(novoFilme->nome, sizeof(novoFilme->nome), stdin);
                          
                            size_t len = strlen(novoFilme->nome);
                            if (len > 0 && novoFilme->nome[len - 1] == '\n') {
                                novoFilme->nome[len - 1] = '\0';
                            }

                            printf("Digite o ano de lançamento do Filme: ");
                            scanf("%d", &novoFilme->anoLancamento);

                            printf("Digite a nota imdb do Filme: ");
                            scanf("%f", &novoFilme->imdb);


                            if (gcofInsert(cofo, novoFilme))
                            {
                                printf("Filme adicionado ao cofo com sucesso.\n");
                            }
                            else
                            {
                                printf("Falha ao adicionar o Filme ao cofo.\n");
                                free(novoFilme);
                            }
                        }
                        else
                        {
                            printf("Falha ao alocar memória para o novo Filme.\n");
                        }
                    }
                    else
                    {
                        printf("O cofo de Filmes está cheio. Remova alguns Filmes ou aumente o tamanho do cofo (opção 6).\n");
                    }
                }
                break;
            }
            case 3:
            {
                if (cofo == NULL)
                {
                    printf("O cofo de Filmes não foi criado. Crie um cofo primeiro (opção 1).\n");
                }
                else
                {
                    char chave[30];
                    printf("Digite o nome do Filme que deseja remover: ");
                    scanf("%s", chave);

                    Filme chaveFilme;
                    strcpy(chaveFilme.nome, chave);

                    Filme *FilmeRemovido = (Filme *)gcofRemove(cofo, &chaveFilme, compararFilmes);
                    if (FilmeRemovido != NULL)
                    {
                        printf("Filme '%s' removido do cofo com sucesso.\n", chave);
                        free(FilmeRemovido);
                    }
                    else
                    {
                        printf("Filme '%s' não encontrado no cofo.\n", chave);
                    }
                }
                break;
            }
            case 4:
            {
                if (cofo == NULL)
                {
                    printf("O cofo de Filmes não foi criado. Crie um cofo primeiro (opção 1).\n");
                }
                else
                {
                    char chave[30];
                    printf("Digite o nome do Filme que deseja consultar: ");
                    scanf("%s", chave);

                    Filme *FilmeConsultado = (Filme *)gcofQuery(cofo, chave, compararFilmes);

                    if (FilmeConsultado != NULL)
                    {
                        printf("Filme '%s' encontrado no cofo:\n", chave);
                        printf("Nome: %s\n", FilmeConsultado->nome);
                        printf("Ano de Fundação: %d\n", FilmeConsultado->anoLancamento);
                        printf("Orçamento: %.2f\n", FilmeConsultado->imdb);
                    }
                    else
                    {
                        printf("Filme '%s' não encontrado no cofo.\n", chave);
                    }
                }
                break;
            }
            case 5:
            {
                if (cofo == NULL)
                {
                    printf("O cofo de Filmes não foi criado. Crie um cofo primeiro (opção 1).\n");
                }
                else
                {
                    printf("Elementos do cofo:\n");

                    Filme *elemento = (Filme *)gcofGetFirst(cofo);

                    while (elemento != NULL)
                    {
                        printf("Nome: %s\n", elemento->nome);
                        printf("Ano de lançamento: %d\n", elemento->anoLancamento);
                        printf("Orçamento: %.2f\n", elemento->imdb);

                        elemento = (Filme *)gcofGetNext(cofo);
                    }
                }
                break;
            }
            case 6:
            {
                if (cofo == NULL)
                {
                    printf("O cofo de Filmes não foi criado. Crie um cofo primeiro (opção 1).\n");
                }
                else
                {
                    for (int i = 0; i < cofo->numItens; i++)
                    {
                        free(cofo->item[i]);
                    }
                    cofo->numItens = 0;

                    if (gcofDestroy(cofo))
                    {
                        printf("O cofo foi esvaziado com sucesso.\n");
                    }
                    else
                    {
                        printf("Falha ao esvaziar o cofo.\n");
                    }
                }
                break;
            }
            case 7:
            {
                if (cofo != NULL)
                {

                    for (int i = cofo->numItens - 1; i > -1; i--)
                    {
                        free(cofo->item[i]);
                    }
                    cofo->numItens = 0;

                    if (gcofDestroy(cofo))
                    {
                        printf("O cofo foi destruído com sucesso.\n");
                        cofo = NULL;
                    }
                    else
                    {
                        printf("Falha ao destruir o cofo.\n");
                    }
                }

                break;
            }
            default:
            {
                printf("Opção inválida. Tente novamente.\n");
            }
            }
        }
        else
        {
            while (getchar() != '\n')
            {
            }
            printf("Entrada inválida. Por favor, digite um número inteiro.\n");
        }
    }

    return TRUE;
}