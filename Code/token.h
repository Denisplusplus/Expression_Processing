#ifndef TOKEN_H
#define TOKEN_H

typedef enum operation_category {
  UNARY,
  BINARY,
  BRACKET
} operation_category;

typedef struct Token {
  char operation;
  int number;
  operation_category category;
} Token;

#endif
