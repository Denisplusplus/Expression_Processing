#include "parser.h"

int is_letter(char value) {
  return (value >= 'a' && value <= 'z') ||
         (value >= 'A' && value <= 'Z');
}

int is_number(char value) {
  return value >= '0' && value <= '9';
}

int is_operation(char value) {
  return (value == '+' || value == '-' || value == '*' ||
          value == '/' || value == '^');
}

int is_opening_bracket(char value) {
  return value == '(';
}

int is_closing_bracket(char value) {
  return value == ')';
}

Priority operation_priority(char operation) {
  if (operation == '^') {
    return POW;
  } else if (operation == '*' || operation == '/') {
    return MUL;
  } else if (operation == '+' || operation == '-') {
    return ADD;
  }
  return ERR;
}

void post_order( char* input, Stack* stack) {
  int i = 0;
  Token token = {
    '\0',
    0,
    BINARY
  };
  Stack operation_stack;
  stack_create(&operation_stack);
  while (input[i] != '\0') {
    if ( is_letter(input[i]) ) {
      token.operation = input[i];
      token.number = 0;
      stack_push(stack, &token);
    } else if ( is_number(input[i]) ) {
      token.operation = '\0';
      token.number = token.number * 10 + input[i] - '0';
      if ( !is_number(input[i + 1]) ) {
        stack_push(stack, &token);
      }
    } else if ( is_operation(input[i]) ) {
      while ( !stack_is_empty(&operation_stack) && 
              operation_priority(input[i]) <
              operation_priority( stack_top(&operation_stack).operation ) ) {
        token = stack_top(&operation_stack);
        stack_pop(&operation_stack);
        stack_push(stack, &token);
      }
      token.operation = input[i];
      token.number = 0;
      if ( is_opening_bracket(input[i-1]) ) {
        token.category = UNARY;
      } else {
        token.category = BINARY;
      }
      stack_push(&operation_stack, &token);
    } else if ( is_opening_bracket(input[i]) ) {
      token.operation = input[i];
      token.number = 0;
      stackPush(&operation_stack, &token);
    } else if ( is_closing_bracket(input[i]) ) {
      while ( !stack_is_empty(&operation_stack) && 
              stack_top(&operation_stack).operation != '(') {
        token = stack_top(&operation_stack);
        stack_pop(&operation_stack);
        stack_push(stack, &token);
      }
      if ( !stack_is_empty(&operation_stack) ) {
        stack_pop(&operation_stack);
      }
    }
    i++;
  }

  while ( !stack_is_empty(&operation_stack) ) {
    token = stack_top(&operation_stack);
    stack_pop(&operation_stack);
    stack_push(stack, &token);
  }

  stack_destroy(&operation_stack);
}

