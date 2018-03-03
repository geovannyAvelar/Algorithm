#include <stdio.h>

int* insertion_sort(int *array, int size) {
    for(int i = 1; i < size; i++) {
        int aux = array[i];
        int j = i;

        while((j >= 0) && (array[j - 1] > aux)) {
            array[j] = array[j - 1];
            j--;
        }

        array[j] = aux;

    }
}

void print_array(int *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}