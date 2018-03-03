#include <stdio.h>

void swap(int *array, int index, int other_index) {
    int temp = array[index];
    array[index] = array[other_index];
    array[other_index] = temp;
}

int get_min_value_index(int *array, int start, int end) {
    int value = array[start];
    int value_index = start;

    for(int i = start; i < end; i++) {
        if(array[i] < value) {
            value = array[i];
            value_index = i;
        }
    }

    return value_index;

}

int* selection_sort(int *array, int size) {
    for(int i = 0; i < size; i++) {
        int min_index = get_min_value_index(array, i, size);
        swap(array, i, min_index);
    }

    return array;

}

void print_array(int *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}