#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// função shell sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// função que gera array aleatório
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

// função pra imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// função para medir o tempo de execução do método de ordenação
void measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("\nArray ordenado: \n");
    printArray(arr, n);
    printf("Tempo de execução: %f segundos\n", time_taken);
}

int main() {
    int n = 100;
    int arr[n];
    
    srand(time(NULL));
    
    generateRandomArray(arr, n);

    printf("Array original: \n");
    printArray(arr, n);
    
    measureTime(shellSort, arr, n);
    
    return 0;
}
