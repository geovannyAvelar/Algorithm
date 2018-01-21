#include <stdio.h>
#include "linked_list.h"

void main() {
  linked_list* list = malloc(sizeof(linked_list));
  list->type = INT;

  append((int*) 1, list);
  append((int*) 2, list);

  print_list(list);
  destroy(list);

}