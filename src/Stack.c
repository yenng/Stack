#include "Stack.h"
#include <stdlib.h>

Stack *stackCreate(){
  Stack* stack = malloc(sizeof(Stack));
  stack->head = NULL;
  stack->tail = NULL;
  stack->length = 0;
  return stack;
}

StackElement *stackElementCreate(int data, StackElement *next){
  StackElement *elem = malloc(sizeof(StackElement));
  elem->data = data;
  elem->next = next;
  return elem;
}

void stackAdd(Stack *stack, StackElement *elem){
  int i = stack->length;
  StackElement* checkElement = stack->head;
  if (checkElement == NULL){
    stack->head = elem;
    stack->tail = elem;
  }
  else{
    stack->head = elem;
  }
  i++;
  stack->length = i;
}
StackElement *stackRemove(Stack *stack){
  if (stack->head == NULL){
    stack = stackCreate();
    stack->length --;
  }
  else{
    stack->head = stack->head->next;
    stack->length --;
    if (stack->head == NULL){
      stack->tail = NULL;
      stack->length = 0;
    }
  }
}










