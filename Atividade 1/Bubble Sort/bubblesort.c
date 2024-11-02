// Ana Clara Guarizi de Souza - UVV 2024/2 CC4N - Matrícula 202309136

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// função bubbble sort
void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

// função pra printar o array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
}

// função main pra rodar o programa
int main() {
    int arr[SIZE];
    srand(time(NULL));

    // preenchendo o vetor com 50 valores
    for (int i = 0; i < SIZE; i++) {
        *(arr + i) = rand() % 100; // valores aleatórios de 0 a 99
    }

    printf("Vetor original:\n");
    printArray(arr, SIZE);

    bubbleSort(arr, SIZE);

    printf("\n\nVetor após Bubble Sort:\n");
    printArray(arr, SIZE);

    return 0;
}
