#include "complexos.h"


/**
 * @brief A função cria um número complexo ao alocar espaço para ele.
 * 
 * @param real Representa a parte real do número complexo.
 * @param imag Representa a parte imaginária do número complexo.
 * @return Retorna o endereço do número complexo criado.
 */
Complexo *COMPLEXOcria(float real, float imag) {

    Complexo* z = NULL;
    
    z = (Complexo*) malloc(sizeof(Complexo)); //alocando espaço
    if(!z){ //checando se a alocação foi feita com sucesso
        printf("Erro de alocação.\n");
        exit(1);
    }

    z->re = real;
    z->im = imag;

    return z;
}

/**
 * @brief A função destrói um número complexo ao desaloca-lo.
 * 
 * @param z O endereço do número complexo a ser destruído.
 */
void COMPLEXOlibera(Complexo *z) {

    if(z) free(z); //desalocando espaço
}

/**
 * @brief A função atribui novos valores reais e imaginários para um número complexo já existente.
 * 
 * @param z Endereço do número complexo a ter seus valores mudados.
 * @param real Novo valor real.
 * @param imag Novo valor imaginário.
 */
void COMPLEXOatribui(Complexo *z, float real, float imag) {
  
    z->re = real;
    z->im = imag;

}

/**
 * @brief A função printa o número complexo em notação científica.
 * 
 * @param z Endereço do número complexo a ser printado.
 */
void COMPLEXOmostra(Complexo *z) {
    
    if(z->re < 0){ //Printando o sinal do número real quando negativo, pois o sinal é ignorado na função notacao_cient.
        printf("-");
    }

    notacao_cient(z->re); //Printando número real em notação científica.
    
    if(z->im < 0) printf(" - "); //Printando o sinal do número imaginário, pois o sinal é ignorado na função notacao_cient.
    else printf(" + "); 

    notacao_cient(z->im); //Printando número imaginário em notação científica.
    printf("i\n\n");

}

/**
 * @brief A função cria o conjugado de um número complexo.
 * 
 * @param z Endereço do número complexo a ser conjugado.
 * @return Endereço do número complexo conjugado.
 */
Complexo *COMPLEXOconjuga(Complexo *z) {

    Complexo * zconj = NULL;

    zconj = COMPLEXOcria(z->re, -(z->im)); //O conjugado de um número complexo é o mesmo número, porém com o oposto de sua parte imaginária.

    return zconj;
}

/**
 * @brief A função cria a soma de dois números complexos.
 * 
 * @param z1 Endereço do primeiro número complexo a ser somado.
 * @param z2 Endereço do segundo número complexo a ser somado.
 * @return Endereço da soma dos números complexos.
 */
Complexo *COMPLEXOadiciona(Complexo *z1, Complexo *z2) {
    Complexo *zsoma = NULL;

    zsoma = COMPLEXOcria((z1->re+z2->re),(z1->im+z2->im)); //A parte real do primeiro número é somada com a parte real do segundo número e a parte imaginária do primeiro número é somada com a parte imaginária do segundo número.

    return zsoma;
}

/**
 * @brief A função cria o produto de dois números complexos.
 * 
 * @param z1 Endereço do primeiro número complexo a ser multiplicado.
 * @param z2 Endereço do segundo núero complexo a ser multiplicado.
 * @return Endereço do produto dos números.
 */
Complexo *COMPLEXOmultiplica(Complexo *z1, Complexo *z2) {
    Complexo *zmult = NULL;

    
    // Considerando z1 = a + bi e z2 = c + di
    // A multiplicacao sera z1 * z2 = (ac - bd) + (ad - cb)i
    zmult = COMPLEXOcria(((z1->re*z2->re)-(z1->im*z2->im)),((z1->re*z2->im)+(z2->re*z1->im)));


    return zmult;
}

/**
 * @brief A função calcula a potência de expoente inteiro de um número complexo de maneira recursiva.
 * 
 * @param base Endereço do número complexo.
 * @param expoente 
 * @return Um tipo complexo com o valor da potência.
 */
Complexo COMPLEXOpotencia1(Complexo *base, int expoente) {

    Complexo z;

    if (expoente == 0) { //Caso Trivial 1: retornamos 1 pois o expoente é 0.
        z.re = 1; 
        z.im = 0;
        return z;
    }
    if (expoente == 1) { //Caso Trivial 2: retornamos o próprio número pois o expoente é 1.
        return *(base);
    }
    if(expoente < 0){ // Caso não Trivial 1: invertemos o números e mudamos o sinal do expoente, pois ele era negativo.
        COMPLEXOinverte(base);
        expoente=-expoente;
        return COMPLEXOpotencia1(base, expoente); // Chamada da recursiva da função com o novo expoente positivo.
    }
    else { //Caso não Trivial 2: chamamos a função multiplica com o número e a nova chamada recursiva da função com o expoente uma unidade menor.
        expoente--;
        return multiplica(*(base), COMPLEXOpotencia1(base, expoente));
    }

}

/**
 * @brief A função realiza o cálculo de i^i.
 * 
 * @param base Endereço do número complexo.
 * @param expoente 
 * @return Endereço do número complexo resultante de i^i.
 */
Complexo *COMPLEXOpotencia2(Complexo *base, Complexo *expoente) {
    Complexo *zpot2=NULL;

    
    if((base->re == 0 && base->im == 1) && (expoente->re == 0 && expoente->im == 1)) {
        /*
        A partir de i^i, utilizamos a propriedade de expoenenciação que não altera a expressão:

        e^(ln(i^i))

        A partir da propriedade de logaritmos temos:

        e^(i*(ln(i)))

        A partir da teoria do plano de Argand-Gauss sabemos que ln(i) = i*(pi/2), logo temos:

        e^(i*i*(pi/2))

        Sabemos que i*i = -1, logo:

        e^(-(pi/2))
        */
        zpot2=COMPLEXOcria(pow((euler(30)), -(pi(30)/2)), 0);
    
    } else {
        printf("Não sabemos fazer para qualquer número complexo.\n");
        exit(0);
    }

    return zpot2;
}

/**
 * @brief Função que calcula a magnitude de um número complexo.
 * 
 * @param z Endereço do número complexo.
 * @return Magnitude do número complexo.
 */
float COMPLEXOmagnitude(Complexo *z) {
    float magn;
    
    magn = sqrt((z->re*z->re)+(z->im*z->im)); //A magnitude de um número complexo é calculada por meio da raiz quadrada da soma dos quadrados da componente real e imaginária.

    return magn;
}

/**
 * @brief Função que calcula o ângulo de um número complexo em relação ao eixo real. 
 * 
 * @param z Endereço do número complexo.
 * @return Ângulo do número complexo em graus.
 */
float COMPLEXOangulo(Complexo *z) {
    
    float cos, ang;
        
    cos = z->re/COMPLEXOmagnitude(z); // O cosseno do ângulo pode ser calculado por meio da razão entre a componente real e a magnitude do número complexo.
    ang = (180*acos(cos))/pi(30); // Calculando o ângulo em graus com a função arccos.
     
    return ang;    
}

/**
 * @brief Função que printa em módulo um número em notação científica.
 * 
 * @param num número a ser printado em notação científica.
 */
int notacao_cient(float num){

    int i;

    if(num == 0){ //quando o número for igual a zero

        printf("0.00e+00");
        return 0;
    
    }

    if(num < 0){ //garantindo que o número esteja em módulo

        num = -num;
    }

    if(num >= 1 && num < 10){ //se a mantissa do número já está em notação científica

        printf("%.2fe+00", num);

        return 0;
    }
    
    if(num < 1){ //caso o número seja menor que 1

        for(i=0;!(num >= 1 && num < 10); i--){ //verificando quantas casas é preciso andar para a direita para que a mantissa esteja em notação científica
            num = num*10;
        }
        
        printf("%.2fe%03d", num, i);
        
        return 0;
    }


    if(num >= 10){ //caso o número seja maior que 10

        for(i=0;!(num >= 1 && num < 10); i++){ //verificando quantas casas é preciso andar para a esquerda para que a mantissa esteja em notação científica
            num = num/10;
        }
        
        printf("%.2fe+%02d", num, i);
        
        return 0;
    }

}


/**
 * @brief Função que aproxima o constante de Euler a partir do somatório de n termos de uma série infinita.
 * 
 * @param n quantidade de termos da série a serem computados.
 * @return float aproximação do constante de Euler.
 */
float euler(int n){
    int i, j;
    float f=1, E=1.0;

    for(i=1; i<=n; i++){
        f*=i;
        E=E+1.0/f;
    }

    return E;
}


/**
 * @brief Função que aproxima a constante pi a partir do somatório de n termos de uma série infinita ao ser multiplicado por raiz de 12
 * 
 * @param n quantidade de termos da série a serem computados.
 * @return float aproximação de pi.
 */
float pi(int n){

    float numpi = 0;
    int i;
    float num1 = 1, num2 = 1;

    for(i = 0; i < n; i++) {

        num2 = 2*i +1;
        numpi += num1/num2;
    
        num1 = num1*((float)-1/3);
    }

    return sqrt(12)*numpi;

}
/**
 * @brief funçao que faz a multiplicação de dois números complexos, porém diferentemente da função COMPLEXOmultiplica ela retorna um tipo complexo;
 * 
 * @param z1 primeiro número complexo;
 * @param z2 segundo número complexos;
 * @return número complexo resultante; 
 */

Complexo multiplica(Complexo z1, Complexo z2) {

    Complexo z3;

    /* para calcular o produto de dois numeros complexos precisamos calcular a parte real e a parte imaginária separada:
    
        --> para o produto real de dois numeros complexos multiplicamos primeiro os dois numeros reais, e depois subtraimos o resultado pelo produto dos dois numeros imaginários;

        --> para calcular o produto imaginário , precisamos multiplicar a parte real do primeiro número pela a parte imaginária do segundo numero complexo,
        esse produto será somado mais o produto do da parte real do segundo número complexo pela a parte imaginária do primeiro número complexo.
    
    */
    
    z3.re = (z1.re*z2.re)-(z1.im*z2.im);
    z3.im = (z1.re*z2.im)+(z2.re*z1.im);

    return z3;

}

/**
 * @brief Função que calcula o inverso de um número complexo.
 * 
 * @param z Endereço do número complexo
 */

void COMPLEXOinverte(Complexo * z) {
    
    float num;
    
    /*
    Seja um número complexo z = a + bi o inverso desse número pode ser obtido pela fórmula:

    z = (a-bi)/(a^2 + b^2)
    */

    num = (z->re*z->re) + (z->im*z->im);
    
    z->re = z->re/num;
    z->im = -(z->im/num);
}
    
