#include <stdio.h>
#include "reverse.c"

typedef struct Congruence {
  int a;
  int b;
  int m;
} Congruence;

int mdc(int a, int b){
    if (b == 0){
        return a;
    }

    mdc(b, a % b);
}

int getSolution(int b1, int m1, int b2, int m2, int b3, int m3){
    if (mdc(m1, m2) != 1 || mdc(m2, m3) != 1 || mdc(m1, m3) != 1){
        printf("Nao ha solucao\n");
        return -1;
    }

    int N = m1 * m2 * m3;
    int N1 = N / m1;
    int N2 = N / m2;
    int N3 = N / m3;

    int x1 = getInverse(N1, m1);
    int x2 = getInverse(N2, m2);
    int x3 = getInverse(N3, m3);

    int x = (b1 * N1 * x1 + b2 * N2 * x2 + b3 * N3 * x3) % N;

    printf("Solucao: %d\n", x);
}

int main(){
    int b1, m1, b2, m2, b3, m3;
    printf("Digite os valores de b1, m1: ");
    scanf("%d %d", &b1, &m1);
    printf("Digite os valores de b2, m2: ");
    scanf("%d %d", &b2, &m2);
    printf("Digite os valores de b3, m3: ");
    scanf("%d %d", &b3, &m3);

    getSolution(b1, m1, b2, m2, b3, m3);

}