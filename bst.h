#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct value {
    int number;
} value;

typedef struct node {
    value value;
    int height;
    struct node *left;
    struct node *right;
} node;

// vvv Edit these functions if cutom value struct
int bst_compare(value a, value b);
void bst_print_value(value value);
// ^^^

int max(int a, int b);

value bst_get_biggest(node *root);
int bst_get_height(node *root);
int bst_get_node_balance(node *node);
int bst_get_node_count(node *root);
int bst_get_tree_balanced(node *root);

void bst_balance_node(node **node);
int bst_delete_val(node **root, value value);
void bst_destroy_node(node **node);
void bst_destroy_tree(node **root);
int bst_insert(node **root, value value);
void bst_rotate_left(node **root);
void bst_rotate_right(node **root);

void bst_print(node *root);
void bst_print_graphical(node *root);
void bst_print_graphical_rec(node *root, int max_height, int level, int indent);
void bst_print_node(node *root);
void bst_print_node_rec(node *root, int level);
