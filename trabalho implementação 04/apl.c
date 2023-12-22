#include <stdio.h>
#include "arvore.h"
#include <stdlib.h>
#include <string.h>
#define True 1
#define False 0

typedef struct
{
    char nome[30];
    int anoLançamento;
    float notaImdb;
} Filme;

int comparaFilmePorAno(void* chave, void *elemento);
int compararFilmePorNome(void* chave, void *elemento);
int comparaFilmePorNota(void* chave, void *elemento);
void listarElementos(TNode *t);
void listarElementosAux(TNode *t);



int main(){
   int opcao;
   int arvoreCriada = 0;
   TNode *arvore = NULL;

    while (True) {
        printf("\n===== MENU =====\n");
        printf("1. Criar árvore vazia\n");
        printf("2. Inserir elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Consultar elemento\n");
        printf("5. Listar elementos\n");
        printf("6. Destruir árvore vazia\n");
        printf("0. Sair\n");
        printf("================\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                if (arvoreCriada == 0) {
                    arvore = abpCreate();
                    arvoreCriada = 1;
                    printf("Árvore criada.\n");
                } else {
                    printf("A árvore já foi criada.\n");
                }
                break;
            case 2:

                if (arvoreCriada == 0) {
                    printf("A árvore não foi criada ainda.\n");
                } else {
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
                scanf("%d", &novoFilme->anoLançamento);

                printf("Digite a nota imdb do filme: \n");
                scanf("%f", &novoFilme->notaImdb);

                
                arvore = abpInsert(arvore, novoFilme, comparaFilmePorAno);
                printf("Filme inserido na árvore.\n");
                }

              break;
                

            case 3: 
                if(arvoreCriada == 0){
                    printf("A árvore não foi criada ainda.\n");
                }else{
              
                    printf("1. Remover por nome\n");
                    printf("2. Remover por ano\n");
                    printf("3. Remover por nota imdb\n");
                    printf("0. Voltar\n");
                    printf("=========================\n");

                    printf("Escolha um critério para remover: ");
                    int opcaoRemocao;
                    scanf("%d", &opcaoRemocao);

                    switch (opcaoRemocao) {
                        case 1: 
                            printf("Remover Filme por nome.\n");

                            char nomeRemover[30];
                            printf("Digite o nome do Filme a ser removido: ");
                            scanf("%s", nomeRemover);

                            Filme FilmeNome = {.nome = ""};
                            strcpy(FilmeNome.nome, nomeRemover);

                            
                            void *FilmeRemovidoPorNome = NULL;
                            arvore = abpRemoveNome(arvore, &FilmeNome, compararFilmePorNome, &FilmeRemovidoPorNome);

                            if (FilmeRemovidoPorNome != NULL) {
                                printf("Filme removido: %s\n", ((Filme *)FilmeRemovidoPorNome)->nome);
                                free(FilmeRemovidoPorNome);
                            } else {
                                printf("Filme não encontrado na árvore.\n");
                            }
                            break;

                        case 2: 
                            printf("Remover Filme por ano.\n");

                            int anoRemover;
                            printf("Digite o ano do Filme a ser removido: ");
                            scanf("%d", &anoRemover);

                            Filme filmeAno = {.anoLançamento = anoRemover};
                            void *FilmeRemovidoAno = NULL;
                            arvore = abpRemoveAno(arvore, &filmeAno, comparaFilmePorAno, &FilmeRemovidoAno);

                            if (FilmeRemovidoAno != NULL) {
                                printf("Filme removido: %s\n", ((Filme *)FilmeRemovidoAno)->nome);
                                free(FilmeRemovidoAno);
                            } else {
                                printf("Filme não encontrado na árvore.\n");
                            }

                            break;

                        case 3: 
                            
                            printf("Digite a nota imdb do filme a ser removido: ");
                            float notaRemover;
                            scanf("%f", &notaRemover);

                            
                            Filme filmeNota = {.notaImdb = notaRemover};

                            void *filmeRemovidoPorNota = NULL;
                            arvore = abpRemoveNota(arvore, &filmeNota, comparaFilmePorNota, &filmeRemovidoPorNota);

                            if (filmeRemovidoPorNota != NULL) {
                                printf("Filme removido: %s\n", ((Filme *)filmeRemovidoPorNota)->nome);
                                free(filmeRemovidoPorNota);
                            } else {
                                printf("Jogador não encontrado na árvore.\n");
                            }

                            break;
                    }

                      
                    
              

                } 

                break;   
            
               

            case 4:
                
                
                if(arvoreCriada == 0){
                    printf("A árvore não foi criada ainda.\n");
                }else{
              
                    printf("1. Consultar por nome\n");
                    printf("2. Consultar por ano\n");
                    printf("3. Consultar por nota imdb\n");
                    printf("0. Voltar\n");
                    printf("=========================\n");

                    printf("Escolha um critério para consultar: ");
                    int opcaoRemocao;
                    scanf("%d", &opcaoRemocao);

                    switch (opcaoRemocao) {
                        case 1: 
                            printf("Consultar Filme por nome.\n");

                            char nomeConsultar[30];
                            printf("Digite o nome do Filme a ser consultado: ");
                            scanf("%s", nomeConsultar);

                            Filme FilmeNome = {.nome = ""};
                            strcpy(FilmeNome.nome, nomeConsultar);

                            
                            void *FilmeConsultadoPorNome = NULL;
                            abpConsultarNome(arvore, &FilmeNome, compararFilmePorNome, &FilmeConsultadoPorNome);

                            if (FilmeConsultadoPorNome != NULL) {
                                printf("Filme consultado: %s\n", ((Filme *)FilmeConsultadoPorNome)->nome);
                                
                            } else {
                                printf("Filme não encontrado na árvore.\n");
                            }
                            break;

                        case 2: 
                            printf("Consultar Filme por ano.\n");

                            int anoConsultar;
                            printf("Digite o ano do Filme a ser consultado: ");
                            scanf("%d", &anoConsultar);

                            Filme filmeAno = {.anoLançamento = anoConsultar};
                            void *FilmeConsultadoAno = NULL;
                            abpConsultarAno(arvore, &filmeAno, comparaFilmePorAno, &FilmeConsultadoAno);

                            if (FilmeConsultadoAno != NULL) {
                                printf("Filme removido: %s\n", ((Filme *)FilmeConsultadoAno)->nome);
                                
                            } else {
                                printf("Filme não encontrado na árvore.\n");
                            }

                            break;

                        case 3: 
                            
                            printf("Digite a nota imdb do filme a ser consultado: ");
                            float notaConsultar;
                            scanf("%f", &notaConsultar);

                            
                            Filme filmeNota = {.notaImdb = notaConsultar};

                            void *filmeConsultadoPorNota = NULL;
                            abpConsultarNota(arvore, &filmeNota, comparaFilmePorNota, &filmeConsultadoPorNota);

                            if (filmeConsultadoPorNota != NULL) {
                                printf("Filme removido: %s\n", ((Filme *)filmeConsultadoPorNota)->nome);
                                
                            } else {
                                printf("Jogador não encontrado na árvore.\n");
                            }

                            break;
                    }

                      
                    
              

                } 

                break;   

            case 5: 
               
                if (arvoreCriada == 0) {
                  printf("Crie a árvore primeiro (Opção 1).\n");
                } else {
                  printf("Listar os elementos da árvore.\n");
                  listarElementos(arvore);
                }
                break;
                

            case 6: 

                abpEsvaziar(arvore);
                arvore = NULL;
                printf("Árvore destruída.\n");
                break;

            case 0:
                
                exit(0);
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    }

    return 0;
}


int comparaFilmePorAno(void* chave, void *elemento){
    Filme *dataItem = (Filme *)elemento;
    Filme *key = (Filme *)chave;
    int keyYear = key->anoLançamento;

    if(keyYear == dataItem->anoLançamento){
        return 0;
    }

    else if(keyYear > dataItem->anoLançamento){
        return 1;
    }

    else{
        return -1;
    }
}


int compararFilmePorNome(void* chave, void *elemento){
    Filme *dataItem = (Filme *)elemento;
    Filme *key = (Filme *)chave;


    int stat = strcmp(dataItem->nome, key->nome);

    if(stat == 0){
        return 0;
    }

    return -1;
}

int comparaFilmePorNota(void* chave, void *elemento){
    Filme *dataItem = (Filme *)elemento;
    Filme *key = (Filme *)chave;

    if(key->notaImdb == dataItem->notaImdb){
        return 0;
    }

    return -1;
}

void listarElementosAux(TNode *t) {
    if (t == NULL) {
        return;
    }

    listarElementosAux(t->l);
    Filme *filme = (Filme *)t->data;
    printf("Nome: %s, Ano: %d, Nota: %.2f\n", filme->nome, filme->anoLançamento, filme->notaImdb);
    listarElementosAux(t->r);
}

void listarElementos(TNode *t) {
    if (t == NULL) {
        printf("A árvore está vazia.\n");
        return;
    }

    printf("Elementos na árvore (em ordem):\n");
    listarElementosAux(t);
}
