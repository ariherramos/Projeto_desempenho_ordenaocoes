#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct heap heap_t;

heap_t *cria_heap(int *vetor, int tam);

void heap_sort(heap_t*heap);
void max_heapify(heap_t *heap, int i);

#endif // HEAP_H_INCLUDED
