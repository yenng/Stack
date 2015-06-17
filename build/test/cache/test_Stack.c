#include "Stack.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}

void test_make_sure_the_initial_stack_is_NULL(void){

 Stack* stack = malloc(sizeof(Stack*));

 stack = stackCreate();

  if ((((stack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)27);;};

}

void test_the_value_of_StackElement(void){

  StackElement *elem = malloc(sizeof(StackElement));

  elem = stackElementCreate(7,((void *)0));

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((elem->data)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

  if ((((elem->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)44);;};

}

void test_stackAdd_function(void){

  Stack* stack = malloc(sizeof(Stack*));

  StackElement *elem = malloc(sizeof(StackElement));

  stack = stackCreate();

  elem = stackElementCreate(7,((void *)0));

  stackAdd(stack, elem);

  if ((((stack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)63);;};

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((stack->tail->data)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((stack->head->data)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

}

void test_add_two_element(void){

  Stack* stack = malloc(sizeof(Stack*));

  StackElement *elem1 = malloc(sizeof(StackElement));

  StackElement *elem2 = malloc(sizeof(StackElement));

  stack = stackCreate();

  elem1 = stackElementCreate(7,((void *)0));

  elem2 = stackElementCreate(5,elem2);

  stackAdd(stack, elem1);

  stackAdd(stack, elem2);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((stack->head->data)), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((stack->tail->data)), (((void *)0)), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

}

void test_add_three_element(void){

  Stack* stack = malloc(sizeof(Stack*));

  StackElement *elem1 = malloc(sizeof(StackElement));

  StackElement *elem2 = malloc(sizeof(StackElement));

  StackElement *elem3 = malloc(sizeof(StackElement));

  stack = stackCreate();

  elem1 = stackElementCreate(7,((void *)0));

  elem2 = stackElementCreate(5,elem1);

  elem3 = stackElementCreate(3,elem2);

  stackAdd(stack, elem1);

  stackAdd(stack, elem2);

  stackAdd(stack, elem3);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((stack->head->data)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((stack->tail->data)), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

}

void test_removeStack_if_stackElement_is_NULL(void){

  Stack* stack = malloc(sizeof(Stack*));

  StackElement *elem1 = malloc(sizeof(StackElement));

  stack = stackCreate();

  elem1 = ((void *)0);

  stackAdd(stack, elem1);

  stackRemove(stack);

  if ((((stack->head)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)137);;};

  if ((((stack->tail)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)138);;};

}

void test_removeStack_if_stackElement_is_NOT_NULL(void){

  Stack* stack = malloc(sizeof(Stack*));

  StackElement *elem1 = malloc(sizeof(StackElement));

  stack = stackCreate();

  elem1 = stackElementCreate(7,((void *)0));

  stackAdd(stack, elem1);

  stackRemove(stack);

  if ((((stack->head)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)158);;};

  if ((((stack->tail)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)159);;};

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

}

void test_add_three_element_and_remove_one_element(void){

  Stack* stack = malloc(sizeof(Stack*));

  StackElement *elem1 = malloc(sizeof(StackElement));

  StackElement *elem2 = malloc(sizeof(StackElement));

  StackElement *elem3 = malloc(sizeof(StackElement));

  stack = stackCreate();

  elem1 = stackElementCreate(7,((void *)0));

  elem2 = stackElementCreate(5,elem1);

  elem3 = stackElementCreate(3,elem2);

  stackAdd(stack, elem1);

  stackAdd(stack, elem2);

  stackAdd(stack, elem3);

  stackRemove(stack);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((stack->head->data)), (((void *)0)), (_U_UINT)186, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((stack->tail->data)), (((void *)0)), (_U_UINT)187, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_INT);

}

void test_add_three_element_and_remove_two_element(void){

  Stack* stack = malloc(sizeof(Stack*));

  StackElement *elem1 = malloc(sizeof(StackElement));

  StackElement *elem2 = malloc(sizeof(StackElement));

  StackElement *elem3 = malloc(sizeof(StackElement));

  stack = stackCreate();

  elem1 = stackElementCreate(7,((void *)0));

  elem2 = stackElementCreate(5,elem1);

  elem3 = stackElementCreate(3,elem2);

  stackAdd(stack, elem1);

  stackAdd(stack, elem2);

  stackAdd(stack, elem3);

  stackRemove(stack);

  stackRemove(stack);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((stack->head->data)), (((void *)0)), (_U_UINT)215, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((stack->tail->data)), (((void *)0)), (_U_UINT)216, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)217, UNITY_DISPLAY_STYLE_INT);

}

void test_add_two_element_and_remove_two_element(void){

  Stack* stack = malloc(sizeof(Stack*));

  StackElement *elem1 = malloc(sizeof(StackElement));

  StackElement *elem2 = malloc(sizeof(StackElement));

  StackElement *elem3 = malloc(sizeof(StackElement));

  stack = stackCreate();

  elem1 = stackElementCreate(7,((void *)0));

  elem2 = stackElementCreate(5,elem1);

  stackAdd(stack, elem1);

  stackAdd(stack, elem2);

  stackRemove(stack);

  stackRemove(stack);

  if ((((stack->head)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)242);;};

  if ((((stack->tail)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)243);;};

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)244, UNITY_DISPLAY_STYLE_INT);

}
