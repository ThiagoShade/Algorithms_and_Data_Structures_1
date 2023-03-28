#include <stdio.h>
#include <stdlib.h>

typedef struct Celula Celula;
typedef struct head head;

struct Celula {
    int abre; // índice que o sinal gráfico foi aberto.
    int fecha; // índice que o sinal gráfico foi fechado. -1 caso não tenha sido fechado ainda.

    Celula *prox; // Endereço do próximo sinal gráfico de mesmo tipo. 
};

struct head {
    Celula* inicio;
};

void abre(int c, head *n);
/**
 * @brief função que cria uma célula,que representa um sinal gráfico que foi aberto na lista de head n.
 * 
 * @param c índice da string em que o sinal gráfico foi aberto.
 * @param n endereço do head da lista do sinal gráfico.
 */
int fecha(int c, head *n);
/**
 * @brief Função que confirma que um sinal gráfico foi fechado ao encontrar o sinal gráfico correspondente mais recente que não foi fechado.
 * 
 * @param c índice da string em que o sinal gráfico foi fechado.
 * @param n endereço do head da lista do sinal gráfico.
 * @return 0 se o sinal gráfico foi fechado com sucesso. 1 se não havia nenhum sinal gráfico aberto válido para ser fechado, já tornando a expressão mal-formada.
 */
int check(head *n);
/**
 * @brief Função que verifica se após todas as operações de abre e fecha não sobraram sinais gráficos sem fechar
 * 
 * @param n endereço do head da lista do sinal gráfico.
 * @return 0 se todos os sinais gráficos nessa lista foram fechados corretamente ou não houveram sinais gráficos desse tipo. 1 se sobrou sinais gráficos sem serem fechados, tornando a expressão mal-formada.
 */
void finalizaLista(head *n);
/**
 * @brief Função que libera a memória de todas as células da lista.
 * 
 */

int main(){
    char e[1000];
    int c, i, qtd, ver;
    head n, G, A; // Cada head representa uma lista de cada sinal gráfico, n - parênteses, G - colchetes e A - chaves
    
    n.inicio=NULL;
    G.inicio=NULL;
    A.inicio=NULL;

    scanf("%d%*c", &qtd);

    for(i=0; i<qtd; i++){
        finalizaLista(&n); // Garantindo que as listas estão vazias depois de um ciclo.
        finalizaLista(&G);
        finalizaLista(&A);

        n.inicio=NULL;
        G.inicio=NULL;
        A.inicio=NULL;

        scanf("%[^\n]%*c", e);

        ver = 0;
        for(c=0; e[c]!='\0'; c++){

            if(e[c]=='(') abre(c, &n); 
            if(e[c]==')') {
                if(fecha(c, &n)) { // Se não havia sinal gráfico aberto válido para ser fechado.
                    printf("mal-formada\n");
                    ver = 1;
                    break;
                }
            }

            if(e[c]=='{') abre(c, &A); 
            if(e[c]=='}') {
                if(fecha(c, &A)) { // Se não havia sinal gráfico aberto válido para ser fechado.
                    printf("mal-formada\n");
                    ver = 1;
                    break;
                }
            }

            if(e[c]=='[') abre(c, &G); 
            if(e[c]==']') {
                if(fecha(c, &G)) { // Se não havia sinal gráfico aberto válido para ser fechado.
                    printf("mal-formada\n");
                    ver = 1;
                    break;
                }
            }
        }

        if(ver) continue; // Caso a expressão já tenha sido identificada mal-formada dentro do for.

        if(check(&n) || check(&A) || check(&G)) { // Caso algum dos sinais gráficos tiver sobrado sem ser fechado.
            printf("mal-formada\n");
            continue;
        } else printf("bem-formada\n");
    }

    finalizaLista(&n); // Garantindo que após o último ciclo a memória as listas sejam desalocadas.
    finalizaLista(&G);
    finalizaLista(&A);

    return 0;
}



void abre(int c, head *n){
    
    Celula *t;

    if(n->inicio == NULL){ // Caso seja a primeira célula a ser inserida na lista
        n->inicio = (Celula*) malloc(sizeof(Celula)); // Alocação
        if(!(n->inicio)) { // Verificando alocação
            printf("Erro de alocação\n");
            exit(1);
        }

        n->inicio->abre = c;
        n->inicio->fecha = -1; // Padrão para dizer que o sinal gráfico não foi fechado ainda.
        n->inicio->prox = NULL; 

    } else{ // A adição de novas células está sendo feita de modo que a nova célula é sempre a primeira e o que estava anteriormente passa a ser o próximo da nova.

        t = n->inicio; 
        n->inicio = (Celula*) malloc(sizeof(Celula)); // Alocação
        if(!(n->inicio)) { // Verificando alocação
            printf("Erro de alocação\n");
            exit(1);
        }

        n->inicio->abre = c;
        n->inicio->fecha = -1; // Padrão para dizer que o sinal gráfico não foi fechado ainda.

        n->inicio->prox = t; // o t guardava a antiga primeira célula que agora será o próximo da nova célula, que será a primeira.
    }

    
}

int fecha(int c, head *n){

    Celula *t;

    if(n->inicio==NULL) return 1; // Caso não haja nenhuma célula na lista.
    
    if(n->inicio->fecha==-1){ // Caso só tenha uma célula.
        n->inicio->fecha=c;
        return 0;
    } else{
        t = n->inicio->prox;
        while(t!=NULL){ // O while acha o sinal gráfico não fechado mais recente.
            if(t->fecha==-1) { 
                t->fecha = c;
                return 0;
            }
            t = t->prox;
        }
        return 1; // Caso não ache nenhum sinal gráfico aberto.
    }


}

int check(head *n){

    Celula *t;

    if(n->inicio==NULL) return 0; // Caso não tenha sido aberto nenhum sinal gráfico.
    if(n->inicio->fecha==-1) return 1; // Caso o primeiro sinal gráfico não esteja fechado.
    else{ // Caso nenhum outro sinal gráfico tenha sido fechado.
        t = n->inicio->prox;
        while(t!=NULL){ // Percorre a lista.
            if(t->fecha==-1) return 1; // Caso alguma não tenha sido fechada.
            t=t->prox;
        }
        return 0;
    }

}

void finalizaLista(head *n){

    Celula *t, *i;

    i=n->inicio;

    while(i!=NULL){ //Percorre toda a lista desalocando cada célula.
        t=i->prox;

        free(i);

        i=t;
    }
}
