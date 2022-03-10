#include <stdio.h>
#include <stdlib.h>

#include "insertion_sort_bin.h"

void insertion_sort_bin(int *vetor, int TAM)
{
    if (vetor == NULL) {
        fprintf(stderr, "insertion_sort_bin: ponteiro inavalido");
        exit(EXIT_FAILURE);
    }
    int i, j, tmp, meio, esq, dir, aux;

    for (i = 1; i < TAM; i++)
    {
        tmp = vetor[i];
        esq = 0;
        dir = i;

        while (esq < dir)
        {
            meio=(esq + dir)/2;

            if (tmp >= vetor[meio])
            {
                esq = meio + 1;
            }
            else
            {
                dir = meio;
            }
        }

        for (j=i; j>esq; j--)
        {
            aux = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = aux;
        }
    }
}
