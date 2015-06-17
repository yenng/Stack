#include "unity.h"
#include "Stack.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

/* 
  =========
  |  tail |-------->-
  |_______|         |
  |  head |-------->|
  |       |         |
  =========         |
                  -----
                   ---
                    -
*/
void test_make_sure_the_initial_stack_is_NULL(void){
	Stack* stack = malloc(sizeof(Stack*));
	stack = stackCreate();
  TEST_ASSERT_NOT_NULL(stack);
}
/*     element
       _______
      |  7   |---->-
      |______|     |      
                   |
                   |
                   |
                 -----
                  ---
                   -
*/
void test_the_value_of_StackElement(void){
  StackElement *elem = malloc(sizeof(StackElement));
  elem = stackElementCreate(7,NULL);
	TEST_ASSERT_EQUAL(7,elem->data);
  TEST_ASSERT_NULL(elem->next);
}
/*
  =========       _______
  |  tail |----->|  7   |---->-
  |_______|      |______|     |      length = 1
  |  head |----------^        |          
  |       |                   |
  =========                   |
                            -----
                             ---
                              -
*/
void test_stackAdd_function(void){
  Stack* stack = malloc(sizeof(Stack*));
  StackElement *elem = malloc(sizeof(StackElement));
  stack = stackCreate();
  elem = stackElementCreate(7,NULL);
  stackAdd(stack, elem);
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_EQUAL(7,stack->tail->data);
  TEST_ASSERT_EQUAL(7,stack->head->data);
	TEST_ASSERT_EQUAL(1,stack->length);  
}
/*
  =========                     _______
  |  tail |------------------->|  7   |---->-
  |_______|       _______      |______|     |   length = 2
  |  head |----->|  5   |---------^         |          
  |       |      |______|                   |
  =========                                 |
                                          -----
                                           ---
                                            -
*/
void test_add_two_element(void){
  Stack* stack = malloc(sizeof(Stack*));
  StackElement *elem1 = malloc(sizeof(StackElement));
  StackElement *elem2 = malloc(sizeof(StackElement));
  stack = stackCreate();
  elem1 = stackElementCreate(7,NULL);
  elem2 = stackElementCreate(5,elem2);
  stackAdd(stack, elem1);
  stackAdd(stack, elem2);
  TEST_ASSERT_EQUAL(5,stack->head->data);
  TEST_ASSERT_EQUAL(7,stack->tail->data);
  TEST_ASSERT_EQUAL(2,stack->length);
}
/*
  =========                                    _______
  |  tail |---------------------------------->|  7   |---->-
  |_______|       _______          _______    |______|     |   length = 3
  |  head |----->|  3   |---------|   5   |-------^        |          
  |       |      |______|         |_______|                |
  =========                                                |
                                                         -----
                                                          ---
                                                           -
*/
void test_add_three_element(void){
  Stack* stack = malloc(sizeof(Stack*));
  StackElement *elem1 = malloc(sizeof(StackElement));
  StackElement *elem2 = malloc(sizeof(StackElement));
  StackElement *elem3 = malloc(sizeof(StackElement));
  stack = stackCreate();
  elem1 = stackElementCreate(7,NULL);
  elem2 = stackElementCreate(5,elem1);
  elem3 = stackElementCreate(3,elem2);
  stackAdd(stack, elem1);
  stackAdd(stack, elem2);
  stackAdd(stack, elem3);
  TEST_ASSERT_EQUAL(3,stack->head->data);
  TEST_ASSERT_EQUAL(7,stack->tail->data);  
  TEST_ASSERT_EQUAL(3,stack->length);  
}
/* 
  =========                                     =========
  |  tail |-------->-                          |  tail  |-------->-
  |_______|         |           remove         |________|         |
  |  head |-------->|           =====>         |  head  |-------->|   length = 0
  |       |         |                          |        |         |
  =========         |                          =========          |
                  -----                                         -----
                   ---                                           ---   
                    -                                             -
*/
void test_removeStack_if_stackElement_is_NULL(void){
  Stack* stack = malloc(sizeof(Stack*));
  StackElement *elem1 = malloc(sizeof(StackElement));
  stack = stackCreate();
  elem1 = NULL;
  stackAdd(stack, elem1);
  stackRemove(stack);
  TEST_ASSERT_NULL(stack->head);
  TEST_ASSERT_NULL(stack->tail);
}
/*
  =========       _______                            =========
  |  tail |----->|  7   |---->-      remove         |  tail  |-------->-
  |_______|      |______|     |      ======>        |________|         |
  |  head |----------^        |                     |  head  |-------->|    length = 0
  |       |                   |                     |        |         |
  =========                   |                     =========          |
                            -----                                    -----
                             ---                                      ---
                              -                                        -
*/
void test_removeStack_if_stackElement_is_NOT_NULL(void){
  Stack* stack = malloc(sizeof(Stack*));
  StackElement *elem1 = malloc(sizeof(StackElement));
  stack = stackCreate();
  elem1 = stackElementCreate(7,NULL);
  stackAdd(stack, elem1);
  stackRemove(stack);
  TEST_ASSERT_NULL(stack->head);
  TEST_ASSERT_NULL(stack->tail);
  TEST_ASSERT_EQUAL(0,stack->length);
}
/*
  =========                                    _______                   =========                     _______
  |  tail |---------------------------------->|  7   |---->-             |  tail |------------------->|  7   |---->-
  |_______|       _______          _______    |______|     |     remove  |_______|       _______      |______|     |
  |  head |----->|  3   |---------|   5   |-------^        |     ======> |  head |----->|  5   |---------^         |     length = 2
  |       |      |______|         |_______|                |             |       |      |______|                   |
  =========                                                |             =========                                 |
                                                         -----                                                   -----
                                                          ---                                                     ---
                                                           -                                                       -
*/
void test_add_three_element_and_remove_one_element(void){
  Stack* stack = malloc(sizeof(Stack*));
  StackElement *elem1 = malloc(sizeof(StackElement));
  StackElement *elem2 = malloc(sizeof(StackElement));
  StackElement *elem3 = malloc(sizeof(StackElement));
  stack = stackCreate();
  elem1 = stackElementCreate(7,NULL);
  elem2 = stackElementCreate(5,elem1);
  elem3 = stackElementCreate(3,elem2);
  stackAdd(stack, elem1);
  stackAdd(stack, elem2);
  stackAdd(stack, elem3);
  stackRemove(stack);
  TEST_ASSERT_EQUAL(5,stack->head->data);
  TEST_ASSERT_EQUAL(7,stack->tail->data);   
  TEST_ASSERT_EQUAL(2,stack->length);   
}
/*
  =========                                    _______                   =========                     _______
  |  tail |---------------------------------->|  7   |---->-             |  tail |------------------->|  7   |---->-
  |_______|       _______          _______    |______|     |     remove  |_______|                    |______|     |
  |  head |----->|  3   |---------|   5   |-------^        |     ======> |  head |-----------------------^         |     length = 1
  |       |      |______|         |_______|                |             |       |                                 |
  =========                                                |             =========                                 |
                                                         -----                                                   -----
                                                          ---                                                     ---
                                                           -                                                       -
*/
void test_add_three_element_and_remove_two_element(void){
  Stack* stack = malloc(sizeof(Stack*));
  StackElement *elem1 = malloc(sizeof(StackElement));
  StackElement *elem2 = malloc(sizeof(StackElement));
  StackElement *elem3 = malloc(sizeof(StackElement));
  stack = stackCreate();
  elem1 = stackElementCreate(7,NULL);
  elem2 = stackElementCreate(5,elem1);
  elem3 = stackElementCreate(3,elem2);
  stackAdd(stack, elem1);
  stackAdd(stack, elem2);
  stackAdd(stack, elem3);
  stackRemove(stack);
  stackRemove(stack);
  TEST_ASSERT_EQUAL(7,stack->head->data);
  TEST_ASSERT_EQUAL(7,stack->tail->data); 
  TEST_ASSERT_EQUAL(1,stack->length); 
}
/*
  =========                    _______                            =========
  |  tail |------------------>|  7   |---->-      remove         |  tail  |-------->-
  |_______|       _______     |______|     |      ======>        |________|         |
  |  head |----->|   5   |--------^        |                     |  head  |-------->|    length=0
  |       |      |_______|                 |                     |        |         |
  =========                                |                     =========          |
                                         -----                                    -----
                                          ---                                      ---
                                           -                                        -
*/
void test_add_two_element_and_remove_two_element(void){
  Stack* stack = malloc(sizeof(Stack*));
  StackElement *elem1 = malloc(sizeof(StackElement));
  StackElement *elem2 = malloc(sizeof(StackElement));
  StackElement *elem3 = malloc(sizeof(StackElement));
  stack = stackCreate();
  elem1 = stackElementCreate(7,NULL);
  elem2 = stackElementCreate(5,elem1);
  stackAdd(stack, elem1);
  stackAdd(stack, elem2);
  stackRemove(stack);
  stackRemove(stack);
  TEST_ASSERT_NULL(stack->head);
  TEST_ASSERT_NULL(stack->tail);
  TEST_ASSERT_EQUAL(0,stack->length);
}
  
  
  
  
  