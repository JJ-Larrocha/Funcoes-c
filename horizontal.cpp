#include <stdio.h>
#include <stdlib.h>

int opcao(const char* txt);

int main(){
    int n, nl, x;
    
    n = opcao("Qnt elnt:");// qntd. de numeros
    nl = opcao(" ltrl:"); // n. lateral
    x =  n/nl;

    for(int i=0; i<=n; i++){
        if(i%nl== 0)
            puts("\n");
        else
            printf("|%d\n", (i*x)+1); 
    }


return 0;
}

int opcao(const char* txt){
    int a;
    printf("%s", txt);
    scanf("%d", &a);
    return a;
}