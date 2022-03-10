#include <stdio.h>
#include <stdlib.h>

#include "insertion_sort.h"

void insertion_sort(int *vetor, int TAM)
{
    if (vetor == NULL) {
        fprintf(stderr, "insertion_sort: ponteiro invalido");
        exit(EXIT_FAILURE);
    }
    int i, j;
    for(i=1; i<TAM; i++)
    {
            for(j=i; (j>0) &&(vetor[j-1]>vetor[j]); j--)
            {
                troca(&vetor[j], &vetor[j-1]);

            }
    }
}
void troca(int*a,int*b)
{
    int aux;

    aux=*a;
    *a=*b;
    *b=aux;
}
