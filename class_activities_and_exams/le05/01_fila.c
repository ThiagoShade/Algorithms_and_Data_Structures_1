
#include <stdio.h>
#include <stdlib.h>

// TAD - Variaveis globais
typedef struct no No;
typedef struct head Head;

// Estruturas de dados
struct no {
    int data;
    struct no* prox;
};

struct head {
    No* inicio;
};

// Prototipos
No* criaFila(int* data);
void insereElemento(Head* h, int* data);
int removeElemento(Head* h);
void mostraFila(Head* h);

// Programa principal
int main() {
    Head* h = NULL;
    int a;

    h = (Head*) malloc(sizeof(Head));
    h->inicio = NULL;
    a = 10;
    insereElemento(h, &a);
    a = 20;
    insereElemento(h, &a);
    a = 30;
    insereElemento(h, &a);
    a = 40;
    insereElemento(h, &a);
    a = 50;
    insereElemento(h, &a);
    mostraFila(h);
    removeElemento(h);
    mostraFila(h);
    removeElemento(h);
    mostraFila(h);

    return(EXIT_SUCCESS);
}

No* criaFila(int* data) {
    No* no = NULL;
    
    no = (No*) malloc(sizeof(No));
    if(no) {
        no->data = *data;
        no->prox = NULL;
    }

    return no;
}

void insereElemento(Head* h, int* data) {
    No* x = criaFila(data);

    if(h == NULL || x == NULL)
        return;
    if(h->inicio == NULL)
        h->inicio = x;
    else {
        No* a = h->inicio;
        while(a->prox != NULL)
            a = a->prox;

        a->prox = x;
    }
}

int removeElemento(Head* h) {

    No * a = NULL;

    if(h == NULL || h->inicio == NULL) return 0;

    if(h->inicio->prox != NULL) a = h->inicio->prox;

    free(h->inicio);

    h->inicio = a;

    return 0;
   
}

void mostraFila(Head* h) {

    No * a = NULL;
    
    if (h != NULL && h->inicio != NULL) {
        a = h->inicio;
        while(a != NULL) {
            printf("%d\n", a->data);
            a = a->prox;
        }
    }
    printf("\n");

}
