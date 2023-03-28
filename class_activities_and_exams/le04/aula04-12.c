#include <stdio.h>
#define N 100

typedef struct{

    int x;
    int y;

}coordenada;

int VencePreso(coordenada lab[][N], coordenada p, int qtd);
/*
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

int rep[N][2];

int main() {

    int i, j;
    int tamX, tamY;

    coordenada labirinto[N][N], pos;

    scanf("%d%d",&tamX,&tamY);

    for(i = 0; i < tamX; i++){
        for(j = 0; j < tamY; j++) scanf("%d %d", &labirinto[i][j].x, &labirinto[i][j].y);
    }

     scanf("%d %d", &pos.x, &pos.y);

    if (VencePreso(labirinto, pos, 0) == 1) printf("vence\n");
    else printf("preso\n");


    return 0;
}

int VencePreso(coordenada lab[][N], coordenada p, int qtd){
    
    int tempx = p.x, tempy = p.y;

    rep[qtd][0] = p.x;
    rep[qtd][1] = p.y;

    qtd++;

    p.x = lab[tempx][tempy].x;
    p.y = lab[tempx][tempy].y;


    if (p.x == 0 && p.y == 0) return 1;

    if (rep_check(p.x, p.y, rep, qtd) == 1) return 0;

    return VencePreso(lab, p, qtd);


}

int rep_check(int a, int b, int c[][2], int q){
    int j;

    for(j=0; j<q; j++) if(c[j][0]==a && c[j][1]==b) return 1;
        
    return 0;
}