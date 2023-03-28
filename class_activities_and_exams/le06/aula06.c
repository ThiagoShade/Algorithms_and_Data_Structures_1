#include <stdio.h>
#include <stdlib.h>

typedef struct p pessoa;
typedef struct h head;

struct p {
    int id;
    pessoa * prox;
};
struct h {
    pessoa * inicio;
};


int fim = 0;
int removidos = 0;

void inserirpessoa(int n, head * h);
void removersenha(int r, head * h);
void printarfila(head * h);
void liberafila(head * h);


int main (){

    head * h = NULL;
    int n, s;

    h = (head *) malloc(sizeof(head));
    if (!h) {
        printf("Erro de alocação\n");
        exit(1);
    }

    scanf("%d", &n);
    inserirpessoa(n, h);
    scanf("%d", &s);
    removersenha(s, h);
    printarfila(h);

    liberafila(h);
    
    return 0;
}

/**
 * @brief Função que coloca n quantidade de pessoas dentro de uma fila
 * 
 * @param n quantidade de pessoas a entrarem na fila
 * @param h ponteiro que aponta para o início da fila
 */
void inserirpessoa(int n, head * h){

    int i;
    int d;
    pessoa * aux = NULL;      

    if(fim == n) return; // Caso todos os elementos já tenham sido colocados na fila.

    scanf("%d", &d);

    if(h->inicio == NULL) { // Caso a fila esteja vazia.
        h->inicio = (pessoa *) malloc(sizeof(pessoa)); 

        if (!(h->inicio)) {
            printf("Erro de alocação\n");
            exit(1);
        }

        h->inicio->prox = NULL;
        aux = h->inicio;

        aux->id = d;
        fim++;
        inserirpessoa(n, h);

    } else {
        aux = h->inicio;
        for (i = 1; i < fim; i++) aux = aux->prox; // Colocando o aux no último elemento da fila.
    }
    aux->prox = (pessoa *) malloc(sizeof(pessoa)); // Adicionando um elemento na fila.
    if (!(aux->prox)) {
        printf("Erro de alocação\n");
        exit(1);
    }
    aux = aux->prox; // Colocando o aux no novo último elemento da fila.
    aux->prox = NULL;
    
    aux->id = d;

    fim++;

    inserirpessoa(n, h);
}



/**
 * @brief Função que tira s pessoas de uma fila.
 * 
 * @param s quantidade de pessoas a saírem da fila.
 * @param h ponteiro que aponta para o inicio da fila.
 */
void removersenha(int s, head * h){
    
    pessoa * aux = NULL, * aux2 = NULL;
    int i;
    int r;

    if(removidos == s)return;

    scanf("%d", &r);

    aux = h->inicio;
    if (aux->id == r) {
        h->inicio = h->inicio->prox;
        free(aux);
        removidos++;
        removersenha(s, h);
        return;
    }
    for(i = 1; i < fim; i++) {
        if(aux->prox->id == r) {
            aux2 = aux->prox;
            aux->prox = NULL;
            free(aux2);
            removidos++;
            removersenha(s, h);
            return;
        }
        aux = aux->prox;
        
    }
    
    printf("Elemento %d não encontrado na fila", r);
    removidos++;

}    

/**
 * @brief Função que printa os identificadores da fila de pessoas.
 * 
 * @param h Ponteiro que aponta para o começo da fila.
 */
void printarfila(head * h){
    int i;
    pessoa * aux = NULL;

    aux = h->inicio;

    for(i = 0; i < fim; i++) {
        printf("%d ", aux->id);
        aux = aux->prox;
    }

}

void liberafila(head * h) {

    pessoa * aux = NULL, * aux2 = NULL;

    aux = h->inicio;
    aux2 = aux->prox;
    free(aux);
    while(aux2 != NULL) {
        aux = aux2;
        aux2 = aux->prox;
        free(aux);
    }

    free(h);
}
