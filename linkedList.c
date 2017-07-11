#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int index;
  int maxIndex;
} linked_list_type;

void initList(linked_list_type* list, int maxIndex) {
  list->index = 0;
  list->maxIndex = maxIndex;
  list->data = malloc(maxIndex * sizeof(int));
}

int listIsFull(linked_list_type* list) {
  return (list->index == list->maxIndex);
}

int listIsEmpty(linked_list_type* list) {
  return (list->index == 0);
}

int insertElement(linked_list_type* list, int element, int position) {
  if (listIsFull(list)) {
    printf("Can't insert, list is full!\n");
    return 0;
  }

  if ((position < 0) || (position > list->index)) {
    printf("Invalid position");
    return 0;
  }

  int i;
  for (i = list->index; i >= position; i--) {
    list->data[i] = list->data[i-1];
  }
  list->data[position-1] = element;
  list->index++;
  return 1;
}

int pushElement(linked_list_type* list, int element) {
  if (listIsFull(list)) {
    printf("Can't insert, list is full!\n");
    return 0;
  }

  list->data[list->index++] = element;
  return 1;
}

int deleteElement(linked_list_type* list, int position) {
  if (listIsEmpty(list)) {
    printf("Can't delete, list is empty!\n");
    return 0;
  }

  if ((position <= 0) || (position > list->index)) {
    printf("Invalid position");
    return 0;
  }

  for (int i = position-1; i < list->index; i++) {
    list->data[i] = list->data[i+1];
  }
  list->index--;
  return 1;
}

int listSearch(linked_list_type* list, int element) {
  int i;
  for (i = 0; i < list->index; i++) {
    if (list->data[i] == element) return (i+1);
  }
  return 0;
}

void destroyList(linked_list_type* list) {
  free(list->data);
  list->index = -1;
  list->maxIndex = -1;
  list = NULL;
}

void listShow(linked_list_type* list) {
  printf("List has %d elements, they are: ", list->index);
  for (int i = 0; i < list->index; i++) {
    printf("%d", list->data[i]);
    if (i == list->index-1){ printf(".\n");}
    else printf(", ");
  }
}
//================main program===================

void main () {
  //init list
  linked_list_type list;
  int index, maxIndex, element, position;
  printf("Input index and maxIndex : ");
  scanf("%d %d", &index, &maxIndex);
  initList(&list, maxIndex);
  listShow(&list);

  //push elements
  printf("Input element: \n");
  for (int i = 1; i<=index; i++) {
    printf("Element %d: ", i);
    scanf("%d", &element);
    pushElement(&list, element);
  }
  listShow(&list);

  //insert element
  printf("Input element and position to insert: ");
  scanf("%d %d", &element, &position);
  insertElement(&list, element, position);
  listShow(&list);

  //delete element
  printf("Input position to delete: ");
  scanf("%d", &position);
  deleteElement(&list, position);
  listShow(&list);

  //search for specific element
  printf("Input element value: ");
  scanf("%d", &element);
  printf("Element with value %d is at %d", element, listSearch(&list, element));

  //destroy list
  destroyList(&list);
  printf("\nFree memory done!");
}
