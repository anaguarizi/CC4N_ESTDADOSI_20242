// Ana Clara Guarizi de Souza - UVV 2024/2 CC4N - Matrícula 202309136

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// função selection sort
void selectionSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// função pra printar o vetor
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

// main pra rodar o programa
int main() {
    int arr[SIZE];
    int *arrPtr = arr;
    srand(time(NULL));

    // preenchendo o vetor com 50 valores
    for (int i = 0; i < SIZE; i++) {
        arrPtr[i] = rand() % 100; // valores aleatórios de 0 a 99
    }

    printf("Vetor original:\n");
    printArray(arrPtr, SIZE);

    selectionSort(arrPtr, SIZE);

    printf("\n\nVetor ordenado com Selection Sort:\n");
    printArray(arrPtr, SIZE);

    return 0;
}
