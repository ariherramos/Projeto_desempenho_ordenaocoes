#include <stdio.h>
#include <stdlib.h>

#include "heap_sort.h"

struct heap{
    int tamanho;
    int *dados;
};

heap_t *cria_heap(int *vetor, int tam){

    if(vetor == NULL){
        fprintf(stderr,"cria_heap: ponteiro invalido");
        exit(EXIT_FAILURE);
    }

    heap_t *heap = malloc(sizeof(heap_t));

    if(heap == NULL){
		perror("cria_heap:");
		exit(EXIT_FAILURE);
	}

    int i;

    heap->dados = vetor;
    heap->tamanho = tam;

    for(i = (tam/2 - 1); i >= 0; i--){
        max_heapify(heap, i);
    }

    return heap;
}

void max_heapify(heap_t *heap, int i){

    if (heap == NULL){
        fprintf(stderr,"max_heapify: ponteiro invalido");
    }

    int maior, temp;
    int e = 2*i + 1;
    int d = (2*i + 2);
    int *dados = heap->dados;

    if ((e < heap->tamanho) && (heap->dados[e] > heap->dados[i]))
        maior = e;
    else
        maior = i;

    if ((d < heap->tamanho) && (heap->dados[d] > heap->dados[maior]))
        maior = d;

    //Se houver algum filho da ´arvore maior que o pai, troca−se
    if (maior != i){
        temp = dados[maior];
        dados[maior] = dados[i];
        dados[i] = temp;
        max_heapify(heap, maior);
    }
}

void heap_sort(heap_t *heap){

    if(heap == NULL){
        fprintf(stderr,"heap_sort: ponteiro invalido");
    }

    int temp;
    int i;
    int *dados = heap->dados;
    int tam = heap->tamanho;

    for(i = tam-1; i >= 1; i--){
        temp = dados[0];
        dados[0] = dados[i];
        dados[i] = temp;
        heap->tamanho--;
        max_heapify(heap, 0);
    }
}
