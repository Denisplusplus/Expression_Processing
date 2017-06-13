#include <stdlib.h>
#include <stdio.h>
#include "task.h"

void task(Node* node) {
  if (!node) {
    return;
  }

  task(node->right);
  task(node->left);

  if (node->token.operation == '*' && 
      node->right->token.operation == '-' &&
      node->right->token.category == UNARY && 
      node->left->token.operation == '-' &&
      node->left->token.category == UNARY) {
    Node* tmp = tree_copy(node->right->right);
    tmp->token.category = BINARY;
    tree_destroy(node->right);
    node->right = tmp;
    tmp = tree_copy(node->left->right);
    tmp->token.category = BINARY;
    tree_destroy(node->left);
    node->left = tmp;
  }
  if (node->token.operation == '*' && 
      node->right->token.operation == '-' && 
      node->right->token.category == UNARY) {
    Token token = node->right->token;
    node->right->token = node->token;
    node->token = token;
    node->right->token.category = BRACKET;
    node->right->left = tree_copy(node->left);
    tree_destroy(node->left);
    node->left = NULL;
  }
  if (node->token.operation == '*' &&
     node->left->token.operation == '-' &&
     node->left->token.category == UNARY) {
    Node* tmp = node_create(&node->token);
    tmp->right = tree_copy(node->right);
    tmp->left = tree_copy(node->left->right);
    node->token = node->left->token;
    tree_destroy(node->left);
    node->left = NULL;
    tree_destroy(node->right);
    node->right = tmp;
  }
  if (node->token.operation == '-' &&
      node->token.category == UNARY &&
      node->right->token.operation == '-' &&
      node->right->token.category == UNARY) {
    node->token = node->right->right->token;
    Node* right = tree_copy(node->right->right->right);
    node->left = tree_copy(node->right->right->left);
    tree_destroy(node->right);
    node->right = right;
  }

}
