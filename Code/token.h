#ifndef TOKEN_H
#define TOKEN_H

typedef enum Operation_category {
  UNARY,
  BINARY,
  BRACKET
} Operation_category;

typedef struct Token {
  char operation;
  int number;
  Operation_category category;
} Token;

#endif
