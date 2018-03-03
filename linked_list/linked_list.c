#include <stdio.h>
#include "linked_list.h"

void main() {
  linked_list* list = malloc(sizeof(linked_list));
  list->type = INT;

  append((int*) 1, list);
  append((int*) 2, list);
  append((int*) 3, list);
  append((int*) 4, list);

  int* first = (int*) get(0, list);
  int* second = (int*) get(1, list);
  int* third = (int*) get(2, list);
  int* fourth = (int*) get(3, list);

  printf("First value is %d\n", first);
  printf("Second value is %d\n", second);
  printf("Third value is %d\n", third);
  printf("Fourth value is %d\n", fourth);

  remove_first(list);

  print_list(list);
  destroy(list);

}