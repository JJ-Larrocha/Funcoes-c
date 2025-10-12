#include <stdio.h>
#include <stdlib.h>

int opcao(const char* txt);

int main(){
    int n, nl, i=0;
    FILE *fp = fopen("horizontal.txt", "w");
    
    if(fp == NULL)
        return 0;

    n = opcao("Qnt elnt:");
    nl = opcao("ltrl:");

    


fclose(fp);
return 0;
}

int opcao(const char* txt){
    int a;
    printf("%s", txt);
    scanf("%d", &a);
    return a;
}