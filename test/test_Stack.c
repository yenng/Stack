#include "unity.h"
#include "Stack.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_make_sure_the_initial_stack_is_NULL(void)
{
	Stack* stack = malloc(sizeof(Stack*));
	stack = stackCreate();
  TEST_ASSERT_NOT_NULL(stack);
}
void test_the_value_of_StackElement(void){
  StackElement *elem = malloc(sizeof(StackElement));
  elem = stackElementCreate(7);
  printf("%i", elem->data);
  printf("%i", elem->next);
	TEST_ASSERT_EQUAL(7,7);
  TEST_ASSERT_NULL(elem->next);
}
void test_stackAdd_function(void){
  Stack* stack = malloc(sizeof(Stack*));
  StackElement *elem = malloc(sizeof(StackElement));
  stack = stackCreate();
  elem = stackElementCreate(7);
  stackAdd(stack, elem);
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_EQUAL(7,stack->tail->data);
  TEST_ASSERT_EQUAL(7,stack->head->data);
	TEST_ASSERT_EQUAL(1,stack->length);  
}
void test_add_two_element(void){
  Stack* stack = malloc(sizeof(Stack*));
  StackElement *elem1 = malloc(sizeof(StackElement));
  StackElement *elem2 = malloc(sizeof(StackElement));
  stack = stackCreate();
  elem1 = stackElementCreate(7);
  elem2 = stackElementCreate(5);
  stackAdd(stack, elem1);
  stackAdd(stack, elem2);
  TEST_ASSERT_EQUAL(7,stack->head->data);
  printf("%i",stack->length);
  TEST_ASSERT_EQUAL(5,stack->tail->data);
}


void test_add_three_element(void){
  Stack* stack = malloc(sizeof(Stack*));
  StackElement *elem1 = malloc(sizeof(StackElement));
  StackElement *elem2 = malloc(sizeof(StackElement));
  StackElement *elem3 = malloc(sizeof(StackElement));
  stack = stackCreate();
  elem1 = stackElementCreate(7);
  elem2 = stackElementCreate(5);
  elem3 = stackElementCreate(3);
  stackAdd(stack, elem1);
  stackAdd(stack, elem2);
  stackAdd(stack, elem3);
  TEST_ASSERT_EQUAL(7,stack->head->data);
  printf("%i",stack->length);
  TEST_ASSERT_EQUAL(3,stack->tail->data);  
}
  
  
  
  
  
  