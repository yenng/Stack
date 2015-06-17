#include "Stack.h"
#include "unity.h"


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

  if ((((stack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)17);;};

}

void test_the_value_of_StackElement(void){

  StackElement *elem = malloc(sizeof(StackElement));

  elem = stackElementCreate(7);

  printf("%i", elem->data);

  printf("%i", elem->next);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((7)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

  if ((((elem->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)25);;};

}

void test_stackAdd_function(void){

  Stack* stack = malloc(sizeof(Stack*));

  StackElement *elem = malloc(sizeof(StackElement));

  stack = stackCreate();

  elem = stackElementCreate(7);

  stackAdd(stack, elem);

  if ((((stack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)33);;};

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((stack->tail->data)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((stack->head->data)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((stack->head->data)), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);

  printf("%i",stack->length);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((stack->tail->data)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((stack->head->data)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

  printf("%i",stack->length);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((stack->tail->data)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

}
