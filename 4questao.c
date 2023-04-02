#include <stdio.h>
#include <math.h>

void listar_Primo (int lista_primos[], int i, int num, int aux){
  if (i == 100)
      return;
  else{
      if (aux > sqrt(num)){ //Primo
          lista_primos[i] = num;
          listar_Primo(lista_primos, i+1, num+2, 2);
      }
      else{
          if (num % aux == 0) //NaoPrimo
             listar_Primo(lista_primos, i, num+2, 2);
          else
              listar_Primo(lista_primos, i, num, aux+1);
      }
  }
}

void decompor (int num, int lista_primos[], int i, int expoentes[]){
   if (num == 1) return;
  
    int primo = lista_primos[i];
    if (num % primo == 0){
        expoentes[i]++;
        decompor(num/primo, lista_primos, i, expoentes);
    }
    else{
            decompor(num, lista_primos, i+1, expoentes);
    }  
}

int mdcCalculator (int lista_primos[], int expoente1[], int expoente2[], int i, int mdc){
    if (i == 100) return mdc;

    if (expoente1[i] < expoente2[i])
        mdc = mdc * pow(lista_primos[i], expoente1[i]);
    else
        mdc = mdc * pow(lista_primos[i], expoente2[i]);

    mdcCalculator(lista_primos, expoente1, expoente2, i+1, mdc);
}

int mmcCalculator (int lista_primos[], int expoente1[], int expoente2[], int i, int mmc){
    if (i == 100) return mmc;

    if (expoente1[i] > expoente2[i])
        mmc = mmc * pow(lista_primos[i], expoente1[i]);
    else
        mmc = mmc * pow(lista_primos[i], expoente2[i]);

    mmcCalculator(lista_primos, expoente1, expoente2, i+1, mmc);
}

void printar (int lista[], int index, int n){
   if (index == n) return;

    printf("%d\n", lista[index]);
    printar(lista, index+1, n);
}

void zerar (int lista[], int index, int n){
    if (index == n) return;

    lista[index] = 0;
    zerar(lista, index+1, n);
}

int main (){
    int num1, num2, mdc = 1, mmc = 1;
        printf("Insira dois numero: ");
        scanf("%d %d", &num1, &num2);

    int lista_primos[100] = {2};
    int expoentes_num1[100];
    int expoentes_num2[100];

    listar_Primo(lista_primos, 1, 3, 3);

    zerar(expoentes_num1, 0, 100);
    decompor(num1, lista_primos, 0, expoentes_num1);

    zerar(expoentes_num2, 0, 100);
    decompor(num2, lista_primos, 0, expoentes_num2);

    mdc = mdcCalculator(lista_primos, expoentes_num1, expoentes_num2, 0, mdc);
    mmc = mmcCalculator(lista_primos, expoentes_num1, expoentes_num2, 0, mmc);
    
    printf("MDC = %d\n", mdc);
    printf("MMC = %d\n", mmc);

    return 0;
}