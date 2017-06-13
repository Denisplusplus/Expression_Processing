#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "tree.h"
#include "parser.h"
#include "task.h"

void menu(void);

int main(void) {
	char action[5];
	char expression[255];
	Tree tree, task_tree;
	tree.root=NULL;
	task_tree.root=NULL;

	Stack stack;
	stack.head=NULL;
	menu();

	while (1) {
		printf("Choose the action: ");
		scanf("%1s", action);

		if (!strcmp(action, "1")) {
			printf("Input the expression: ");
			scanf("%s", expression);

			tree_destroy(tree.root);
			tree_destroy(task_tree.root);
			stack_destroy(&stack);

			tree_create(&tree);
			stack_create(&stack);

			post_order(expression, &stack);
			tree.root = tree_build(tree.root, &stack);

			task_tree.root = tree_copy(tree.root);
			task(task_tree.root);
		} else if (!strcmp(action, "2")) {
			if (tree.root==NULL) {
				printf("You have to input the expression before printing of this\n");
			}else {
				printf("The initial expression:\n");
				printf("%s\n", expression);
			}	
		} else if (!strcmp(action, "3")) {
			printf("The transformed expression:\n");
			print_text(task_tree.root, 0);
			printf("\n");
		} else if (!strcmp(action, "4")) {
			if (tree.root) {
				printf("Tree of initial expression:\n");
				print_tree(tree.root, 0);
			} else {
				printf("Tree is empty\n");
			}
		} else if (!strcmp(action, "5")) {
			if (task_tree.root) {
				printf("Tree of transformed expression\n");
				print_tree(task_tree.root, 0);
			} else {
				printf("Tree is empty\n");
			}
		} else if (!strcmp(action, "6")) {
			menu();
		} else if (!strcmp(action, "0")) {
			tree_destroy(tree.root);
			tree_destroy(task_tree.root);
			stack_destroy(&stack);
			break;
		} else {
			tree_destroy(tree.root);
			tree_destroy(task_tree.root);
			stack_destroy(&stack);
			printf("Error. Type '6' to find the solution\n");
			break;
		}

	}

	return 0;
}

void menu(void)
{
	printf("Menu:\n");
	printf("1) Input the expression\n");
	printf("2) Print the initial expression\n");
	printf("3) Print the transformed expression\n");
	printf("4) Print the initial tree\n");
	printf("5) Print the transformed tree\n");
	printf("6) Print this menu\n");
	printf("0) Exit\n");
}
