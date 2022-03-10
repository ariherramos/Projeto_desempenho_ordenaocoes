#include <stdio.h>
#include <stdlib.h>
#include <time.h>       //para usar a função time()
#include <math.h>       //para a raiz quadrada (desvio padrão)

#ifdef __MINGW32__
#include <windows.h>        //para usar a função GetTickCount()
#include <process.h>       //para usar a função getpid()
#define SRAND(x) srand(x)
#define RAND() rand()
#else
#include <sys/time.h>       //para usar a função gettimeofday()
#include <unistd.h>         //para usar a função getpid()
#define SRAND(x) srand48(x)
#define RAND() lrand48()
#endif // __MINGW32__

#include "bubble_sort.h"
#include "quick_sort.h"
#include "insertion_sort.h"
#include "insertion_sort_bin.h"
#include "merge_sort.h"
#include "selection_sort.h"
#include "heap_sort.h"


#define TAM_VET 1000000  //tamanho do vetor
#define EXEC_NUM 20    //numero de execuções para cada ordenação

#define DEBUG

#ifdef DEBUG
#define ELEM_ARQ 100    //numero de elementos de cada vetor que se deseja salvar no arquivo DEBUG
#endif //DEBUG

int main()
{
    float media, desvio, diferenca_media, variancia;
    long long unsigned somatorio;
    int *vetor;
    int tempo[EXEC_NUM];
    int i, j, k;
    heap_t *heap=NULL;
#ifdef __MINGW32__
    int inicio[EXEC_NUM], fim[EXEC_NUM];                //cria as variáveis para calcular o tempo no windows
#else
    struct timeval inicio[EXEC_NUM], fim[EXEC_NUM];     //cria as variáveis para calcular o tempo no ANSII
#endif // __MINGW32__

#ifdef DEBUG
    printf("DEBUG ON!!!\n\nO numero de elementos definido por ELEM_ARQ, dos vetores, sera salvo no arquivo \"Vetores (DEBUG).txt\" antes e apos serem ordenados.\n\n" );

    FILE *arq_debug = fopen("Vetores (DEBUG).txt","w");         //Abre o arquivo que armazenará os vetores do DEBUG
    if (arq_debug == NULL) {
        perror("Fopen Vetores (DEBUG): ");
        exit(EXIT_FAILURE);
    }
#endif // DEBUG

    printf("Os valores exibidos na tela serao salvos no arquivo \"Resultado_Ordenacoes.txt\"\n");

    FILE *arq_result = fopen("Resultado_Ordenacoes.txt","w");       //Abre o arquivo que armazenará o resultado
    if (arq_result == NULL) {
        perror("Fopen Resultado_Ordenacoes: ");
        exit(EXIT_FAILURE);
    }

    enum ordenacoes {
        BUBBLE_SORT,
        QUICK_SORT,
        INSERTION_SORT,
        INSERTION_SORT_BIN,
        MERGE_SORT,
        SELECTION_SORT,
        HEAP_SORT
    };

    vetor = (int*)malloc(TAM_VET*sizeof(int));      //cria o vetor
    if (vetor == NULL) {
        perror("Malloc vetor: ");
        exit(EXIT_FAILURE);
    }

    SRAND(time(NULL)^getpid());         //inicializa os numeros aleatorios com a semente

    for (k = BUBBLE_SORT ; k <= HEAP_SORT ; k++) {
        switch(k) {         //imprime o nome da ordenação na tela e nos arquivos
        case BUBBLE_SORT:
            printf("\n\t\t>>BUBBLE SORT<<\n");
            fprintf(arq_result,"\n\t\t>>BUBBLE SORT<<\n");
#ifdef DEBUG
            fprintf(arq_debug,"\n\t\t>>BUBBLE SORT<<\n");
#endif // DEBUG
            break;
        case QUICK_SORT:
            printf("\n\t\t>>QUICK SORT<<\n");
            fprintf(arq_result,"\n\t\t>>QUICK SORT<<\n");
#ifdef DEBUG
            fprintf(arq_debug,"\n\t\t>>QUICK SORT<<\n");
#endif // DEBUG
            break;
        case INSERTION_SORT:
            printf("\n\t\t>>INSERTION SORT<<\n");
            fprintf(arq_result,"\n\t\t>>INSERTION SORT<<\n");
#ifdef DEBUG
            fprintf(arq_debug,"\n\t\t>>INSERTION SORT<<\n");
#endif // DEBUG
            break;
        case INSERTION_SORT_BIN:
            printf("\n\t\t>>INSERTION SORT BIN<<\n");
            fprintf(arq_result,"\n\t\t>>INSERTION SORT BIN<<\n");
#ifdef DEBUG
            fprintf(arq_debug,"\n\t\t>>INSERTION SORT BIN<<\n");
#endif // DEBUG
            break;
        case MERGE_SORT:
            printf("\n\t\t>>MERGE SORT<<\n");
            fprintf(arq_result,"\n\t\t>>MERGE SORT<<\n");
#ifdef DEBUG
            fprintf(arq_debug,"\n\t\t>>MERGE SORT<<\n");
#endif // DEBUG
            break;
        case SELECTION_SORT:
            printf("\n\t\t>>SELECTION SORT<<\n");
            fprintf(arq_result,"\n\t\t>>SELECTION SORT<<\n");
#ifdef DEBUG
            fprintf(arq_debug,"\n\t\t>>SELECTION SORT<<\n");
#endif // DEBUG
            break;
        case HEAP_SORT:
            printf("\n\t\t>>HEAP SORT<<\n");
            fprintf(arq_result,"\n\t\t>>HEAP SORT<<\n");
#ifdef DEBUG
            fprintf(arq_debug,"\n\t\t>>HEAP SORT<<\n");
#endif // DEBUG
        }

        somatorio = 0;   //zera o somatorio de tempos
        for (i=0 ; i < EXEC_NUM ; i++) {   //Executa cada ordenação no numero de execuções definido


            for (j=0 ; j < TAM_VET ; j++) {     //Inicializa o vetor com numeros aleatórios
                vetor[j] = RAND();
            }

            if(k == HEAP_SORT){
                heap = cria_heap(vetor, TAM_VET);
            }

#ifdef DEBUG
            fprintf(arq_debug,"\n\t\t>>Vetor_%d - ALEATORIO<<\n\n",(i+1));
            for (j=0 ; j < ELEM_ARQ ; j++) {
                fprintf(arq_debug,"Vetor_%d[%d]: %d\n",(i+1),j,vetor[j]);     //Salva os "ELEM_ARQ" elementos do vetor aleatorio no arquivo DEBUG
            }
#endif // DEBUG


#ifdef __MINGW32__
            inicio[i] = GetTickCount();     //Obtem o tempo atual em milissegundos
#else
            gettimeofday(&(inicio[i]), NULL);
#endif // __MINGW32__

            switch(k) {         //executa a ordenação
            case BUBBLE_SORT:
               /// bubble_sort(vetor,TAM_VET);
                break;
            case QUICK_SORT:
                ///quick_sort(vetor,0,(TAM_VET-1));
                break;
            case INSERTION_SORT:
               /// insertion_sort(vetor,TAM_VET);
                break;
            case INSERTION_SORT_BIN:
               /// insertion_sort_bin(vetor,TAM_VET);
                break;
            case MERGE_SORT:
                merge_sort(vetor,0,(TAM_VET-1),TAM_VET);
                break;
            case SELECTION_SORT:
                /// selection_sort(vetor, TAM_VET);
                break;
            case HEAP_SORT:
                heap_sort(heap);
            }


#ifdef __MINGW32__
            fim[i] = GetTickCount();
            tempo[i] = fim[i] - inicio[i];  //Calcula a variação de tempo em milissegundos
#else
            gettimeofday(&(fim[i]), NULL);
            tempo[i] = (int) (1000*((fim[i]).tv_sec - (inicio[i]).tv_sec) + ((fim[i]).tv_usec - (inicio[i]).tv_usec)/1000);     //Calcula a variação de tempo em milissegundos
#endif // __MINGW32__

#ifdef DEBUG
            fprintf(arq_debug,"\n\t\t>>Vetor_%d - ORDENADO<<\n\n",(i+1));     //Salva oS "ELEM_ARQ" elementos do vetor recém ordenado no arquivo DEBUG
            for (j=0 ; j < ELEM_ARQ ; j++) {
                fprintf(arq_debug,"Vetor_%d[%d]: %d\n",(i+1),j,vetor[j]);
            }
#endif // DEBUG

            somatorio += tempo[i];              //acumula o tempo no somatório
            printf("Tempo de Execucao %d: %d\n",(i+1),tempo[i]);
            fprintf(arq_result,"Tempo de Execucao %d: %d\n",(i+1),tempo[i]);
        }

        media = (float)somatorio/EXEC_NUM;      //calcula a media

        variancia = 0;
        for (i=0 ; i < EXEC_NUM ; i++) {        //calcula a variancia
            diferenca_media = (float)(tempo[i] - media);
            variancia += diferenca_media*diferenca_media;
        }
        variancia/= EXEC_NUM;
        desvio = sqrt(variancia);           //calcula o desvio padrão
#ifdef __MINGW32__
        printf("Somatorio: %I64u\nMedia: %.2f\nVariancia: %.2f\nDesvio Padrao: %.2f\n",somatorio,media,variancia,desvio);
        fprintf(arq_result,"Somatorio: %I64u\nMedia: %.2f\nVariancia: %.2f\nDesvio Padrao: %.2f\n",somatorio,media,variancia,desvio);
#else
        printf("Somatorio: %llu\nMedia: %.2f\nVariancia: %.2f\nDesvio Padrao: %.2f\n",somatorio,media,variancia,desvio);
        fprintf(arq_result,"Somatorio: %llu\nMedia: %.2f\nVariancia: %.2f\nDesvio Padrao: %.2f\n",somatorio,media,variancia,desvio);
#endif
    }

    fclose(arq_result);
#ifdef DEBUG
    fclose(arq_debug);
#endif // DEBUG
    free(vetor);
    free(heap);
    return 0;
}
