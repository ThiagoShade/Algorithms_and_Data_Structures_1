#include <stdio.h>

unsigned long long int fibonacci(int n);
unsigned long long int DecompNumPrimo(unsigned long long int N);

int main(){

    int i;
    int n, vezes;

    scanf("%d", &vezes);
    
    for (i = 0; i < vezes; i++) {
        scanf("%d", &n);

        DecompNumPrimo(fibonacci(n));
    }

    return 0;
}

unsigned long long int fibonacci(int n) {
    unsigned long long int n1 = 0, ans = 0, num1 = 0, num2 = 0;

    while(n1 != n) {
        if (n1 == 0) {
            num1 = 0;
            num2 = 1;
            ans = num1+num2;
            n1++;
            continue;
        }

        ans = num1 + num2;
        num1 = num2;
        num2 = ans;


        n1++;
    }

    return ans;

}

unsigned long long int DecompNumPrimo(unsigned long long int N){  
    unsigned long long int num, primo, div, contador, verificador_primo, verificador_divisao, prim_divs=0, c, c1 = 0;
    int primo_certezas[20]={0};
     
    primo = 2;
    contador = 0;
    num = N;

    while (num != 1) {
    
        div = primo;
        verificador_primo = 1;
        while (div > 1) {
            if (primo % div == 0) {
                if (div != primo) verificador_primo = 0;
            }
            if (verificador_primo == 1) break;
            div--;
        }
     
        while (num%primo==0){
            primo_certezas[prim_divs]=primo;
            prim_divs++;
            num/=primo;
        }
            
        primo++;
    }

    if(primo_certezas[1]==0)printf("%d\n", primo_certezas[0]);
    else {
        printf("%llu = ", N);
        while (primo_certezas[c1]!=0){
        
            if(c1!=0)printf(" x ");
            printf("%d", primo_certezas[c1]);
            c1++;
        }
        printf("\n");
    }
     
}