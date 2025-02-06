#include <stdio.h>

int leia_opcao(const char* txt);

/*Imprime um texto e faz leitura de um inteiro*/
int leia_opcao(const char* txt){
    int a;
    printf("%s", txt);
    scanf("%d", &a);
    return a;
}