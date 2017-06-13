#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "parser.h"

Node* node_create(Token* token) {
  Node* node = (Node*)malloc(sizeof(Node));

  node->token = *token;
  node->right = node->left = NULL;

  return node;
}

void tree_create(Tree* tree) {
  tree->root = NULL;
}

Node* tree_build(Node* node, Stack* stack) {
  if ( stack_is_empty(stack) ) {
    return NULL;
  }
  Token token = stack_top(stack);
  stack_pop(stack);

  node = node_create(&token);

  if ( is_operation(token.operation) && token.category == UNARY) {
    node->right = tree_build(node->right, stack);
  } else if ( is_operation(token.operation) ) {
    node->right = tree_build(node->right, stack);
    node->left = tree_build(node->left, stack);
  }
  return node;
}

void tree_destroy(Node* node) {
  if (!node) {
    return;
  }
  if (node->left) {
    tree_destroy(node->left);
  }
  if (node->right) {
    tree_destroy(node->right);
  }
  free(node);
  node = NULL;
}


Node* tree_copy(Node* node) {
  Node* tmp = NULL;

  if (!node) {
    return NULL;
  }

  tmp = node_create(&node->token);
  tmp->token = node->token;
  tmp->left = tree_copy(node->left);
  tmp->right = tree_copy(node->right);

  return tmp;
}

void print_tree(Node* node,  int level) {
  if (!node) {
    return;
  }

  print_tree(node->right, level + 1);
  if (node->token.operation != '\0') {
    printf("%*s%c\n", level * 3 + 1, "", node->token.operation);
  } else {
    printf("%*s%d\n", level * 3 + 1, "", node->token.number);
  }
  print_tree(node->left, level + 1);
}


void print_text(Node* node, Priority priority) {
  if (!node) {
    return;
  }

  if ( is_operation(node->token.operation) &&
       priority > operation_priority(node->token.operation)) {
    printf("(");
  } else if ( is_operation(node->token.operation) &&
              node->token.category == BRACKET) {
        printf("(");
  }
  print_text(node->left, operation_priority(node->token.operation));
  if (node->token.operation != '\0') {
    printf("%c", node->token.operation);
  } else {
    printf("%d", node->token.number);
  }
  print_text(node->right, operation_priority(node->token.operation));
  if ( is_operation(node->token.operation) && 
       priority > operation_priority(node->token.operation)) {
    printf(")");
  } else if ( is_operation(node->token.operation) &&
              node->token.category == BRACKET) {
        printf(")");
  }
}
