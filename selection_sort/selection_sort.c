#include "selection_sort.h"

void main() {
    int array[] = {8,2,5,1,3};

    int *a = selection_sort(array, 5);

    print_array(a, 5);
}