
#include <stdio.h>
#include "libs/reverse.c"

void solveCongruences(int b[], int m[], int n){
    int M = 1;
    for (int i = 0; i < n; i++){
        M *= m[i];
    }

    int x = 0;

    for (int i = 0; i < n; i++){
        int Mi = M / m[i];
        int yi = getInverse(Mi, m[i]);
        x += b[i] * Mi * yi;
    }

    printf("\nSolucao: %d\n", x%M);
    printf("M: %d\n", M);
}

int main(){
    int n;
    printf("Digite o numero de congruencias: ");
    scanf("%d", &n);
  
    int b[n], m[n];

    for (int i = 0; i < n; i++){
        printf("Digite os valores de b%d, m%d: ", i+1, i+1);
        scanf("%d %d", &b[i], &m[i]);
    }

    solveCongruences(b, m, n);
}