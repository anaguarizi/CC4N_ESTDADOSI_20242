#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// função pra trocar elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// função pra partir o array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // pivô é o último elemento
    int i = (low - 1);  // pega o indice do menor elemento

    // reorganizando os elmentos de acordo com seu valor comparado ao pivô
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[++i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  // coloca o pivô na posição correta
    return i + 1;  // retorna a posição do pivô
}

// função do QuickSort (recursiva)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  // ordena à esquerda
        quickSort(arr, pi + 1, high);  // ordena à direita
    }
}

// função de gerar array aleatório até 1000
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

// função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// função para medir o tempo de execução do algoritmo
void measureTime(void (*sortFunc)(int[], int, int), int arr[], int n, const char *label) {
    clock_t start = clock();
    sortFunc(arr, 0, n-1);  // usa a função inserida ao chamar essa função
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("\n%s: Tempo de execução: %f segundos\n", label, time_taken);
}

int main() {
    int n = 100;
    srand(time(NULL));
    int arr[n];

    generateRandomArray(arr, n);

    printf("Array original:\n");
    printArray(arr, n);

    measureTime(quickSort, arr, n, "Quicksort com array aleatório");

    printf("\nArray ordenado:\n");
    printArray(arr, n);
    
    return 0;
}
