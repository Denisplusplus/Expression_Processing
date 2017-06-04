#ifndef STACK_H
#define STACK_H

#include "token.h"

typedef struct Item {
  Token token;
	struct Item* prev;
} Item;

typedef struct Stack {
  Item* head;
} Stack;

void stack_create(Stack* stack);
int stack_is_empty(Stack* stack);
void stack_push(Stack* stack, Token* token);
void stack_pop(Stack* stack);
Token stack_top(Stack* stack);
void stack_destroy(Stack* stack);
void stack_print(Stack* stack);

#endif
