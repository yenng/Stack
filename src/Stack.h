#ifndef Stack_H
#define Stack_H

typedef struct StackElement StackElement;
struct StackElement{
  StackElement *next;
  int data;
};

typedef struct{
  StackElement *head;
  StackElement *tail;
  int length;
}Stack;

Stack *stackCreate();
StackElement *stackElementCreate(int data, StackElement *next);
void stackAdd(Stack *stack, StackElement *elem);
StackElement *stackRemove(Stack *stack);

#endif // Stack_H
