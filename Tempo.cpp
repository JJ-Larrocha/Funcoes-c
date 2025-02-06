#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n, *v;
    double timedif, time1;

    scanf("%d%d%f", &n);

    v = (int*) malloc(sizeof(int) * n);

    // Inicio da contagem
    time1 = (double) clock();
    time1 = time1 / CLOCKS_PER_SEC; 
    
    for (int i=0; i<n; i++)
        v[i] = srand(time(NULL));

    for(int i=0; i<n; i++)
        n += n;

    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    printf("Tempo decorrido %lf segundos\n", timedif); // Fim da contagem e impressão do tempo
    printf("n: %d\n", n);

return 0;
}

void espera(float tempo) {
    clock_t start_time = clock();
    double duration = tempo; // Tempo de espera

    while (clock() - start_time < duration * CLOCKS_PER_SEC) {
		//espera
	}
};