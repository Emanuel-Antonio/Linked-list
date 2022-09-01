#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

void inserir_elemento_inicio(No **lista, int num)
{
    No *novo = malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("Erro ao alocar memoria\n");
    }
}

void inserir_elemento_final(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if (*lista == NULL)
        {
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memoria\n");
    }
}

void inserir_elemento_meio(No **lista, int num, int ant)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->valor = num;
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->valor != ant && aux->proximo)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memoria\n");
    }
}

void inserir_elemento_ordenado(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->valor = num;
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }
        else if (novo->valor < (*lista)->valor)
        {
            novo->proximo = *lista;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memoria");
    }
}

void imprimir(No *lista){
    printf("\nLista: ");
    while(lista){
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }
    printf("\n\n");

}
int main()
{
    int valor, ant, opcao;
    No *lista = NULL;

    do{
        printf("\n\t0 - sair\n\t1 - inserirI\n\t2 - inserirM\n\t3 - inserirF\n\t4 - imprimir\n\t");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_elemento_inicio(&lista,valor);
                break;
            case 2:
                printf("Digite um valor e o valor de referencia: ");
                scanf("%d%d", &valor, &ant);
                inserir_elemento_meio(&lista,valor,ant);
                break;
            case 3:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_elemento_final(&lista,valor);
                break;
            case 4:
                imprimir(lista);
                break;
            default:
                if(opcao != 0){
                    printf("opção invalida!");
                }
        }
    }
    while(opcao!=0);


    // inserir_elemento_ordenado(&lista,valor);

    return 0;
}