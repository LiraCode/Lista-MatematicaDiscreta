#include<stdio.h>
#include<math.h>
#include<time.h>

int primo(int n, int d){
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
    int seconds = 60, i=3;
    time_t endwait = time(NULL)+seconds;
    printf("2\n");
    while(time(NULL)<endwait){
        if(primo(i,(int)sqrt(i)+1)){
            printf("%d\n", i);
        }
        i+=2;
    }
}
