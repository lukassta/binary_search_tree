# Binary search tree **(BST)** c library
```
                               ._______________________________32_______________________________.
               ._______________16_______________.                              ._______________48_______________.
       ._______8_______.               ._______24_______.              ._______40_______.              ._______56_______.
   .___4___.       .___12___.      .___20___.      .___28___.      .___36___.      .___44___.      .___52___.      .___60___.
 ._2_.   ._6_.   ._10_.  ._14_.  ._18_.  ._22_.  ._26_.  ._30_.  ._34_.  ._38_.  ._42_.  ._46_.  ._50_.  ._54_.  ._58_.  ._62_.
 1   3   5   7   9   11  13  15  17  19  21  23  25  27  29  31  33  35  37  39  41  43  45  47  49  51  53  55  57  59  61  63
```
This library provides functions for basic binary search tree functionality.

## Documentation
### Structs
typedef struct BstValue {
    int number;
} BstValue;
> Custom value struct for easy adaptation
for specific use cases

typedef struct BstNode {
    BstValue value;
    int height;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;
> A node of a binary search tree


### Functions
// vvv Edit these functions if cutom value struct
int bst_compare(BstValue a, value b);
> Compares two value structs
Returns -1 if first argument is prefered over the second
Returns 0 if arguments are equal
Returns 1 if second argument is prefered over the first

void bst_print_value(BstValue value);
> Defines how a value struct is printed

// ^^^

#### Data getting functions
BstValue bst_get_most_right(BstNode *root);
> Returns the value of the most right child node (also can return self value)

int bst_get_height(BstNode *node);
> Returns height of node

int bst_get_node_balance(BstNode *node);
> Returns 1 if node balanced, 0 otherwise

int bst_get_node_count(BstNode *root);
> Returns the count of tree nodes

int bst_get_tree_balanced(BstNode *root);
> Returns 1 if tree is balances, 0 otherwise

int max(int a, int b);
> Returns the bigger int

#### Data altering functions functions
void bst_array_to_tree(BstNode **root, BstValue *value_array, int left_p, int right_p);
> Convert binary tree to an array (preserving the order)

void bst_balance_tree(BstNode **root);
> Balances an unblanced binary search tree

void bst_balance_node(BstNode **node);
> Balances node if node balance is off by one node

int bst_delete_val(BstNode **root, BstValue value);
> Deletes tree node with given value,
returns 0 if success and 1 if given value does not exist

void bst_destroy_node(BstNode **node);
> Frees up node memory, and sets node pointer to NULL

void bst_destroy_tree(BstNode **root);
> Frees up tree memory, and sets root pointer to NULL

int bst_insert(BstNode **root, BstValue value);
> Inserts node with given value into tree,
returns 0 if success,
returns 1 if node could not be created because of lack of space,
returns 2 if value already exists and duplicates are disabled

void bst_rotate_left(BstNode **node);
> Rotates node left

void bst_rotate_right(BstNode **node);
> Rotates node right

void bst_tree_to_array(BstNode *root, BstValue *value_array, int *left_p);
> Converts sorted array to binary search tree (preserving order)

#### Outputing to console functions
void bst_print(BstNode *root);
> Prints data about binary tree

void bst_print_graphical(BstNode *root);
> Initiates printing of a binary tree in a graph manner

void bst_print_graphical_rec(BstNode *root, int max_height, int level, int indent);
> Prints binary tree in a graph manner

void bst_print_node(BstNode *root);
> Initiates printing of a binary tree node list

void bst_print_node_rec(BstNode *root, int level);
> Prints binary tree node list

Author: Lukas Stavaris
