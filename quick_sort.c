#include <stdio.h>
#include <stdlib.h>

#include "quick_sort.h"


void trocar(int * a, int * b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return;
}

int mediana_de_tres(int * vetor, int esq, int dir)
{
    int med;

    med = (esq + dir) / 2;

    if(vetor[dir] < vetor[esq]) {
        trocar(vetor + dir, vetor + esq);
    }

    if(vetor[med] < vetor[esq]) {
        trocar(vetor + med, vetor + esq);
    }

    if(vetor[dir] < vetor[med]) {
        trocar(vetor + dir, vetor + med);
    }

    return med;
}

int particao(int * vetor, int inicio, int fim)
{
    if (vetor == NULL)
    {
        fprintf(stderr, "quick_sort->particao: ponteiro invalido");
        exit(EXIT_FAILURE);
    }
    int med;
    int pivo;
    int i, j;

    med = mediana_de_tres(vetor, inicio, fim);
    pivo = vetor[med];
    i = inicio - 1;
    j = fim + 1;

    while(1) {
        do {
            i++;
        } while(vetor[i] < pivo);

        do {
            j--;
        } while(vetor[j] > pivo);

        if(i >= j) {
            return j;
        }

        trocar(vetor + i, vetor + j);
    }
}

void quick_sort(int * vetor, int inicio, int fim)
{
    if (vetor == NULL)
    {
        fprintf(stderr, "quick_sort: ponteiro inavalido");
        exit(EXIT_FAILURE);
    }
    int p;

    if(inicio < fim) {
        p = particao(vetor, inicio, fim);
        quick_sort(vetor, inicio, p);
        quick_sort(vetor, p + 1, fim);
    }
}
