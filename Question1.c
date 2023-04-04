#include<stdio.h>
#include<math.h>


int primo(int n, int d){
    if(n==2) return 1;
    if(n<2){
        return 0;
    }
    if(d<2){
        return 1;
    }
    if (n%d==0)
    {
        return 0;
    }

    return primo(n, d-1);
    
}

int main(){
    int n;
    printf("Verificador de Números Primos\n");
    printf("Por favor digite um número:\n");
    scanf("%d", &n);

    if((primo(n,(int)sqrt(n)+1))==1){
        printf("O número digitado é Primo!\n");
    }
    else{
        printf("O número digitado não é Primo!\n");        
    }
}
