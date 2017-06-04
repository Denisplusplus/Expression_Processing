#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

void stack_create(Stack* stack) {
	stack->head = NULL;
}

int stack_is_empty(Stack* stack) {
	return !stack->head;
}

void stack_push(Stack* stack, Token* token) {
	Item* item = (Item *)malloc(sizeof(Item));

	item->token = *token;
	item->prev = stack->head;
	stack->head = item;
}

void stack_pop(Stack* stack) {
	Item *item = NULL;

	if ( stack_is_empty(stack)) {
		return;
	}

	item = stack->head;
	stack->head = stack->head->prev;

	free(item);
}

Token stack_top(Stack* stack) {
	return stack->head->token;
}

void stack_destroy(Stack* stack) {
	Item *item = NULL;

	while (stack->head) {
		item = stack->head;
		stack->head = stack->head->prev;
		free(item);
	}

	stack->head = NULL;
}
