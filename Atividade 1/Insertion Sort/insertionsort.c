// Ana Clara Guarizi de Souza - UVV 2024/2 CC4N - Matrícula 202309136

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// função insertion sort
void insertionSort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// função pra printar o vetor
void printArray(int *arr, int size) {
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

    insertionSort(arrPtr, SIZE);

    printf("\n\nVetor ordenado com Insertion Sort:\n");
    printArray(arrPtr, SIZE);

    return 0;
}
