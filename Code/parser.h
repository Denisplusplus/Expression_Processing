#ifndef PARSER_H
#define PARSER_H

#include "stack.h"

typedef enum Priority {
  ERR,
  ADD,
  MUL,
  POW
} Priority;

int is_letter(char value);
int is_number(char value);
int is_operation(char value);
Priority operation_priority(char operation);
void post_order(char* input, Stack* stack);


#endif
