#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// função do merge sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    // preenche os subarrays temporários L[] e R[]
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    // mescla os subarrays de volta no array original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    
    // copia os elementos restantes de L[], se houver
    while (i < n1) arr[k++] = L[i++];
    
    // copia os elementos restantes de R[], se houver
    while (j < n2) arr[k++] = R[j++];
}

// função recursiva para ordenar o array
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);  // ordena a primeira metade
        mergeSort(arr, mid + 1, right);  // ordena a segunda metade
        merge(arr, left, mid, right);  // mescla as duas metades
    }
}

// função para gerar um array aleatório
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
    sortFunc(arr, 0, n-1);  // ordena o array com a função inserida ao chamar essa função
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  
    printf("%s: Tempo de execução: %f segundos\n", label, time_taken);
}

int main() {
    int n = 100;
    int arr[n];
    srand(time(NULL));
  
    generateRandomArray(arr, n);
    
    printf("Array original:\n");
    printArray(arr, n);

    measureTime(mergeSort, arr, n, "Mergesort com array aleatório");

    printf("\nArray ordenado:\n");
    printArray(arr, n);
    
    return 0;
}
