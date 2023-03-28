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
No* criaPilha(int* data);
void insereElemento(Head* h, int* data);
int removeElemento(Head* h);
void mostraPilha(Head* h);

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
    mostraPilha(h);
    removeElemento(h);
    mostraPilha(h);
    removeElemento(h);
    mostraPilha(h);

    return(EXIT_SUCCESS);
}

No* criaPilha(int* data) {
    No* no = NULL;
    
    no = (No*) malloc(sizeof(No));
    if(no) {
        no->data = *data;
        no->prox = NULL;
    }

    return no;
}

void insereElemento(Head* h, int* data) {
    No* x = criaPilha(data);

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
    else{
        a = h->inicio;

        if(a->prox == NULL) {
            free(a);
            return 0;
        }
        while(a->prox->prox != NULL) a = a->prox;
        free(a->prox);
        a->prox = NULL;
    }

    return 0;
}

void mostraPilha(Head* h) {
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
