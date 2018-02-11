#include <stdlib.h>
#include <stdbool.h>

enum types {
  INT = 0,
  FLOAT = 1,
  STRING = 2
}types;

typedef struct node {
  void* value;
  struct node* previous;
  struct node* next;
}node;

typedef struct linked_list {
  node* first;
  node* last;
  int type;
  int size;
}linked_list;

void add(void* value, linked_list* list);
void append(void* value, linked_list* list);
node* get_node(int index, linked_list* list);
void* get(int index, linked_list* list);
void print_list(linked_list* list);
bool is_empty(linked_list* list);
bool check_index_in_bounds(int index, linked_list* list);
void destroy(linked_list* list);

void add(void* value, linked_list* list) {
  node* new_node = malloc(sizeof(node));
  new_node->value = value;

  if(is_empty(list)) {
    list->size = 0;
    list->first = new_node;
    list->last = new_node;
  } else {
    new_node->next = list->first;
    new_node->previous = NULL;
    list->first->previous = new_node;
    list->first = new_node;
  }

  list->size++;

}

void append(void* value, linked_list* list) {
  if(is_empty(list)) {
    add(value, list);
  } else {
    node* new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->previous = list->last;
    new_node->next = NULL;
    list->last->next = new_node;
    list->last = new_node;
    list->size = list->size + 1;
  }
}

node* get_node(int index, linked_list* list) {
  if(check_index_in_bounds(index, list)) {
    node* next = list->first;
    int count = 0;

    while(next != NULL) {
      if(count == index) {
        return next;
      }

      next = next->next;
      count++;
    }
  }

  return NULL;
}

void* get(int index, linked_list* list) {
  node* node = get_node(index, list);

  if(node != NULL) {
    return node->value;
  }

  return NULL;

}

void remove_first(linked_list* list) {
  if(!is_empty(list)) {
    list->first = list->first->next;
    list->size = list->size - 1;

    if(list->size == 0) {
      list->last = NULL;
    }
  }
}

void print_list(linked_list* list) {
  printf("[ ");

  if(!is_empty(list)) {
    node* next = list->first;

    while(next != NULL) {
      switch(list->type) {
        case INT:
          printf("%d ", next->value);
          break;
        case FLOAT:
          printf("%f ", next->value);
          break;
        case STRING:
          printf("%s ", next->value);
          break;
      }

      next = next->next;
    }
  }

  printf("]\n");
}

bool is_empty(linked_list* list) {
  return list->size < 1;
}

bool check_index_in_bounds(int index, linked_list* list) {
  return !is_empty(list) && index <= (list->size - 1);
}

void destroy(linked_list* list) {
  if(!is_empty(list)) {
    node* next = list->first;

    while(next != NULL) {
      free(next);
      next = next->next;
    }
  }

  free(list);

}