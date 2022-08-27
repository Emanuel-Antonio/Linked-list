#include <stdio.h>    
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_elemento_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else{
        printf("Erro ao alocar memoria\n");
    }
}

void inserir_elemento_final(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*lista == NULL){
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo){
                aux = aux->proximo;
            aux->proximo = novo;
            }
        }
    }
    else{
        printf("Erro ao alocar memoria\n");
    }
}

void inserir_elemento_meio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
            }
        }
    }
    else{
        printf("Erro ao alocar memoria\n");
    }
}

void inserir_elemento_ordenado(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        else if(novo->valor < (*lista)->valor){
            novo->proximo = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor){
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
            }
        }
    }
    else{
        printf("Erro ao alocar memoria");
    }
}

int main(){
    int valor, ant;
    No *lista = NULL;

    //inserir_elemento_inicio(&lista,valor);

    //inserir_elemento_final(&lista,valor);

    //inserir_elemento_meio(&lista,valor,ant);

    //inserir_elemento_ordenado(&lista,valor);

    return 0;
}