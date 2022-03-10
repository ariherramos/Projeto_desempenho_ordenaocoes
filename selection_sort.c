#include <stdio.h>
#include <stdlib.h>

#include "selection_sort.h"

void selection_sort(int *vetor, int TAM)
{
    if (vetor == NULL) {
        fprintf(stderr, "selection_sort: ponteiro inavalido");
        exit(EXIT_FAILURE);
    }
   int i, j, max, aux;
   for(i=TAM; i>1; i--)
   {
       max=0;
       for(j=1; j<i; j++)
       {
           if(vetor[j]>vetor[max])
           {
             max=j;
           }
       }
        aux = vetor[max];
        vetor[max] = vetor[i-1];
        vetor[i-1] = aux;
   }
}
