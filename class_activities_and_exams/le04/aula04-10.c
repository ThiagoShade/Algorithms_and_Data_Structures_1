#include <stdio.h>
#include <string.h>
#define N 500

int rep[N][2]; //matriz que guarda quais pares já foram "andados" em um mesmo ciclo.

/**
 * @brief Função que anda no tabuleiro a partir de uma célula inicial e define se a célula é segura ou não.
 * 
 * @param t matriz que contém o tabuleiro
 * @param dim dimensão do tabuleiro
 * @param l linha atual da posição
 * @param c coluna atual da posição
 * @param qtd_rep variável que guarda quabtos pares já foram "andados" em um mesmo ciclo.
 * 
 * @return int 0 - não é célula segura, 1 - célula segura 
 */
int andar(char t[][N], int dim, int l, int c, int qtd_rep); 
/**
 * @brief Função que checa se determinado par está presente em uma matriz
 * 
 * @param a linha
 * @param b coluna
 * @param c matriz
 * @param q quantidade de pares a serem olhados
 * 
 * @return 0 - Se não houve repetição, 1 - Houve repetição.
 */
int rep_check(int a, int b, int c[][2], int q);

int main(){
    int c, j;
    int dimensao;
    char tabuleiro[N][N];
    int seguros = 0;

    scanf("%d%*c", &dimensao);
    for(c = 0; c < dimensao; c++) {
        for (j = 0; j < dimensao; j++) {
            scanf("%c%*c", &tabuleiro[c][j]);
        }
    }

    memset(rep, 0, (N*2)*sizeof(int));

    for (c = 0; c < dimensao; c++) {
        for (j = 0; j < dimensao; j++) {
            if (andar(tabuleiro, dimensao, c, j, 0) == 1) seguros++;
            memset(rep, 0, (N*2)*sizeof(int));
        }
    }

    printf("%d\n", seguros);

    return 0;
}

int andar(char t[][N], int dim, int l, int c, int qtd_rep) {

    rep[qtd_rep][0] = l;
    rep[qtd_rep][1] = c;
    qtd_rep++;

    if(t[l][c] == 'v') l++;
    if(t[l][c] == '<') c--;
    if(t[l][c] == '>') c++;
    if(t[l][c] == 'a') l--;

    if ((l == dim || l < 0) || (c == dim || c < 0)) return 0;
    if (rep_check(l, c, rep, qtd_rep) == 1) return 1;
    return andar(t, dim, l, c, qtd_rep);
}

int rep_check(int a, int b, int c[][2], int q){
    int j;

    for(j=0; j<q; j++) if(c[j][0]==a && c[j][1]==b) return 1;
        
    return 0;
}