#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int index;
  int maxIndex;
  int* data;
} stack_t;

void initStack(stack_t* stk, int maximumIndex) {
  stk->maxIndex = maximumIndex;
  stk->index = 0;
  stk->data = malloc(stk->maxIndex * sizeof(int));
}

void pushStack(stack_t* stk, int item){
  stk->data[stk->index++] = item;
}

int popStack(stack_t* stk) {
  return (stk->data[--stk->index]);
}

int stackCount(stack_t* stk) {
  return stk->index;
}

void destroyStack(stack_t* stk) {
  free(stk->data);
  stk = NULL;
}

//===================main program================
void main() {
  stack_t stk;
  int i,n;

  printf("Number of stack elements: "); scanf("%d",&n);
  initStack(&stk, n);
  //push
  for (i=1;i<=n;i++) {
    printf("Element %d: ",i);
    int item;
    scanf("%d",&item);
    pushStack(&stk, item);
  }

  //Number of elements
  printf("Stack has %d items \n", stackCount(&stk));
  //pop
  printf("Pop stack now: %d", popStack(&stk));
  for (i=1;i<n;i++) {
    printf(", %d", popStack(&stk));
  }
  printf("\n");
}
