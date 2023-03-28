#include"casa.h"

void forma_Instru(head * h) {

    char dir;
    char rua[10];

    while(1) {

        scanf("%*c"); // Ignorando o primeiro parêntese.
        scanf("%c", &dir); // Lendo a direção da instrução.
        scanf("%*c%*c"); // Ignorando a vírgula e o espaço.
        scanf("%[^)]", rua); // Lendo a rua da instrução.
        scanf("%*c%*c"); // Ignorando o parêntese e o \n.
        
        if (rua[0] == 'e') { // Caso seja a última instrução
            coloca_Instru(h, dir, rua); //coloca os elementos na lista em formato de uma pilha 
            break;
        }
        coloca_Instru(h, dir, rua); 
    }

}

void coloca_Instru(head * h, char dir, char * rua) {
    
        Instru *i = NULL;
    
        i = (Instru *) malloc(sizeof(Instru)); // alocando novo espaço na lista 

        if(!i) { // Verificando se a alocação foi bem sucedida
            printf("Erro de alocação!\n");
            exit(1);
        }
        
        i->dir = dir; // Colocando os valores
        strcpy(i->rua, rua);

        i->prox = h->inicio; // Colocando o termo no inicio da lista como uma pilha, e o início anterior se torna o próximo
        h->inicio = i;
}

void print_Instru_rev(head * h){

    Instru *i = NULL;

    i = h->inicio;
    
    while(i != NULL){  // loop que irá percorrer a pilha printando todas as intruções de volta para casa 
        
        printf("Vire a ");
        print_dir_rev(i->dir);// printa o lado que deve-se virar 
        if (i->prox != NULL) printf(" na rua ");// se ainda nao estiver chegado na casa
        else printf(" na sua ");// caso ja esteja no destino final (casa)
        print_rua_prox(i);// printa o nome da rua, ou a casa;
        printf("\n");// pula uma linha 
        
        i = i->prox; // passa para a proxima instruçao

    }

}

void print_dir_rev(char dir){
    if(dir == 'd') printf("ESQUERDA"); // inverte o sentido da instrução pois estaremos voltando em direção à casa 
    if(dir == 'e') printf("DIREITA");// inverte o sentido da instrução pois agora estaremos voltando em direção à casa
    
    return;
}

void print_rua_prox(Instru * i){

    if(i->prox == NULL) printf("CASA"); // caso seja o destino final
    else if(i->prox->rua[0] == 'p') printf("PRINCIPAL"); // printa o nome da rua principal
    else if(i->prox->rua[0] == 'r') printf("%c%s", (i->prox->rua[0])-32, i->prox->rua+1); // printa a sigla da rua em maiúsculo
    else print_extenso(i->prox->rua); // printa o numero da rua por extenso 

}

void limpa_Instru(head * h){
    Instru * i;

    while(h->inicio != NULL){
        i = h->inicio; // recebe o primeiro elemento da pilha 
        h->inicio = h->inicio->prox;// passa para o proximo 
        free(i);// desaloca a pilha um elemento de cada vez 
    }
}


