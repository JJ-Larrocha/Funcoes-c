#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen_random(char *s, const int len);

int main(){
    char nome[5];
    int i;

    scanf("%d", &i);
    gen_random(nome, i);

    printf("%s\n", nome);
    
    return 0;
}


void gen_random(char *s, const int len) {
	srand(time(NULL));
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
	int i;

    for (i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}