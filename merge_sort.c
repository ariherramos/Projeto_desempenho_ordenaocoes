#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

void merge_sort(int *vetor, int inicio, int fim, int TAM)
{
    if (vetor == NULL) {
        fprintf(stderr, "merge_sort: ponteiro inavalido");
        exit(EXIT_FAILURE);
    }
    int meio;

    if ( inicio < fim ) {

        meio = ( inicio + fim ) / 2;

        merge_sort ( vetor, inicio, meio, TAM);
        merge_sort ( vetor, meio + 1, fim, TAM);

        int *temp=(int*)malloc(TAM*sizeof(int));

        if (temp == NULL){
            perror("Malloc funde_sort: ");
            exit(EXIT_FAILURE);
        }

        funde_sort ( vetor, temp, inicio, meio, fim, TAM);

    }
}

void funde_sort(int *vetor, int *temp, int esq, int meio, int dir, int TAM)
{
    if (vetor == NULL) {
        fprintf(stderr, "merge_sort->funde_sort: ponteiro inavalido");
        exit(EXIT_FAILURE);
    }

    if (temp == NULL){
        perror("Malloc funde_sort: ");
        exit(EXIT_FAILURE);
    }

    int i=esq;
    int j=esq;
    int k=meio+1;

    while(j <= meio && k <= dir ) {
        if ( vetor[j] < vetor[ k ]) {
            temp[i++] = vetor [j ++];
        } else {
            temp[i ++] = vetor [k ++];
        }
    }
    while (j <= meio ) {
        temp [ i ++] = vetor [j ++];
    }
    for (i = esq ; i < k; i ++) {
        vetor [i] = temp [ i ];

    }
    free(temp);
}
