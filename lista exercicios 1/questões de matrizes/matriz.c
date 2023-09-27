#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

//questao 8
int *MultiplicaMatrizPelaTRansposta (int *v1, int *v2, int *v3, int n){
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            int soma = 0;
            for(int k = 0; k < n; k++){
                soma += v1[(i*n) + k] * v2[(j*n) + k];
            }
            v3[(i*n) + j] = soma;



        }
    }


    return v3;
}

//questao 8 b
int *Multiplicamatrizes (int *v1, int *v2, int *v3, int n){
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            int soma = 0;
            for(int k = 0; k < n; k++){
                soma += v1[(i*n) + k] * v2[(k*n) + j];
            }
            v3[(i*n) + j] = soma;

        }
    }


    return v3;
}


//questao 9
int *multiMatrizVetor(int *v1, int *v, int n){
    int *v3 = (int *)malloc(n * sizeof(int));
    if(v3 == NULL){
        return NULL;
    }
    for(int i = 0; i< n; i++){
        int soma = 0;
        for(int j = 0; j< n; j++){
            soma += v1[(i * n) + j] * v[j];
        }

        v3[i] = soma;
    }

    return v3;
}

//questao 13
int *ExtraiColuna (int *v, int *vcoluna, int n, int c){
    for(int i = 0; i < n; i++){
        int elemento = v[(n * i) + c];
        vcoluna[i] = elemento;
    }

    return vcoluna;
}


//questao 15

int MaiorElementodaMatrizEmK(int *v, int N, int M, int K){

    if(v != NULL){

        int maior = v[(M * K) + 0];
        for(int i = 1; i< M; i++){
            if(v[(M * K) + i] > maior){
                maior = v[(M * K) + i];
            }
        }

        return maior;

    }

    
    
}


int MaiordaColunadaMatriz(int * v1, int n, int m, int col){
    if(v1 != NULL){
        if(n > 0 && m > 0){
            if(col>= 0 && col < m){
                int maior = v1[(m * 0) + col];
                for(int i = 0; i < n; i++){
                    if(v1[(m * i) + col] > maior){
                        maior = v1[(m * i) + col];
                    }
                }

                return maior;
            }
        }
    }


}