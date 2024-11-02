// Ana Clara Guarizi de Souza - UVV 2024/2 CC4N - Matrícula 202309136

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// função selection sort
void selectionSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int *min_ptr = arr + i;
        for (int j = i + 1; j < size; j++) {
            if (*(arr + j) < *min_ptr) {
                min_ptr = arr + j;
            }
        }
        int temp = *min_ptr;
        *min_ptr = *(arr + i);
        *(arr + i) = temp;
    }
}

// função pra printar o vetor
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
}

// main pra rodar o programa
int main() {
    int arr[SIZE];
    srand(time(NULL));

    // preenchendo o vetor com 50 valores
    for (int i = 0; i < SIZE; i++) {
        *(arr + i) = rand() % 100; // valores aleatórios de 0 a 99
    }

    printf("Vetor original:\n");
    printArray(arr, SIZE);

    selectionSort(arr, SIZE);

    printf("\n\nVetor ordenado com Selection Sort:\n");
    printArray(arr, SIZE);

    return 0;
}
