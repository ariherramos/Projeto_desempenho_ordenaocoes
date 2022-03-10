#include <stdio.h>
#include <stdlib.h>

#include "bubble_sort.h"

void bubble_sort(int *vetor, int TAM)
{
    if (vetor == NULL) {
        fprintf(stderr, "bubble_sort: ponteiro invalido");
        exit(EXIT_FAILURE);
    }
    int k, w, aux;

    for (k = TAM; k > 1; k--) {
        for (w=0; w<k-1; w++) {
            if (vetor[w]>vetor[w+1]) {
                aux = vetor[w];
                vetor[w] = vetor[w+1];
                vetor[w+1] = aux;
            }
        }
    }
}
