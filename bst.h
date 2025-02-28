#include <stdio.h>
#include <stdlib.h>

typedef struct BstValue {
    int number;
} BstValue;

typedef struct BstNode {
    BstValue value;
    int height;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

// vvv Edit these functions if cutom value struct
int bst_compare(BstValue a, BstValue b);
BstValue get_value(int input);
void bst_print_value(BstValue value);
// ^^^


// Data getting functions
BstValue bst_get_most_right(BstNode *root);
int bst_get_height(BstNode *node);
int bst_get_node_balance(BstNode *node);
int bst_get_node_count(BstNode *root);
int bst_get_tree_balanced(BstNode *root);
int max(int a, int b);

// Data altering functions functions
void bst_array_to_tree(BstNode **root, BstValue *value_array, int left_p, int right_p);
void bst_balance_tree(BstNode **root);
void bst_balance_node(BstNode **node);
int bst_delete_value(BstNode **root, BstValue value);
void bst_destroy_node(BstNode **node);
void bst_destroy_tree(BstNode **root);
int bst_insert(BstNode **root, BstValue value);
void bst_rotate_left(BstNode **node);
void bst_rotate_right(BstNode **node);
void bst_tree_to_array(BstNode *root, BstValue *value_array, int *left_p);

// Outputing to console functions
void bst_print(BstNode *root);
void bst_print_graphical(BstNode *root);
void bst_print_graphical_rec(BstNode *root, int max_height, int level, int indent);
void bst_print_node(BstNode *root);
void bst_print_node_rec(BstNode *root, int level);
