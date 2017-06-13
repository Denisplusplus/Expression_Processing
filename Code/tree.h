#ifndef TREE_H
#define TREE_H

#include "token.h"
#include "stack.h"
#include "parser.h"

typedef struct Node {
  struct Node* right;
  struct Node* left;
  Token token;
} Node;

typedef struct Tree {
  Node* root;
} Tree;

Node* node_create(Token* token);

void tree_create(Tree* tree);
Node* tree_build(Node* node, Stack* stack);
void tree_destroy(Node* node);
Node* tree_copy(Node* node);

void print_tree(Node* node,  int level);
void print_text(Node* node, Priority priority);


#endif
