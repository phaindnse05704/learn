#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int index;
  int maxIndex;
}linkedList;

void initList(linkedList* llist) {
  llist->index = 0;
}

int listIsFull(linkedList* llist) {
  return (llist->index == llist->maxIndex);
}

int listIsEmpty(linkedList* llist) {
  return (llist->index == 0);
}

int insertElement(linkedList* llist, int element, int position) {
  if (listIsFull(&llist)) {
    printf("Can't insert, list is full!\n");
    return 0;
  }

  if ((position < 0) || (position > index)) {
    printf("Invalid position");
    return 0;
  }

  int i;
  for (i = llist->index; i > position; i--) {
    llist->data[i] = llist->data[i-1];
  }
  llist->data[position] = element;
  llist->index++;
  return 1;
}

int pushElement(linkedList* llist, int element) {
  if (listIsFull(&llist)) {
    printf("Can't insert, list is full!\n");
    return 0;
  }

  llist->data[list->index++] = element;
  return 1;
}

int deleteElement(linkedList* llist, int position) {
  if (listIsEmpty(&llist)) {
    printf("Can't delete, list is empty!\n");
    return 0;
  }

  if ((position <= 0) || (position > index)) {
    printf("Invalid position");
    return 0;
  }

  for (int i = position; i <= --llist->index; i++) {
    llist->data[i] = llist->data[i+1];
  }
  return 1;
}

int listSearch(linkedList* llist, int element) {
  int i;
  for (i = 0; i < llist->index; i++) {
    if (llist->data[i] == element) return (i+1);
  }
  return 0;
}
