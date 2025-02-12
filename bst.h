#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} node;

int is_tree_balanced(node *root);
int tree_height(node *root);
int tree_node_count(node *root);

void balance_tree(node **root);
void destroy_node(node **node);
void destroy_tree(node **root);
void insert(node **root, int value);
void rotate_tree_left(node **root);
void rotate_tree_right(node **root);

void print_tree(node *root);
void print_tree_graphical(node *root);
void print_tree_graphical_rec(node *root, int max_height,int level, int indent);
void print_tree_node_rec(node *root, int level);
