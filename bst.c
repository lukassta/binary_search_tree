// Lukas Stavaris LSP 2414004
// Program: PS, Course: 1, Group: 4
// Binary search tree library for c programming language
//----------------------------

#include "bst.h"


static char ANSI_COLOR_RESET[] = "\x1b[0m";
static char ANSI_COLOR_GREEN[] = "\x1b[32m"; static char ANSI_COLOR_RED[] = "\x1b[31m";


//== Edit here ================================
//-- Settings ---------------------------------
// 0 - disabled
// 1 - enabled
static int ALLOW_DUPLICATES = 1;
static int AUTO_BALANCE = 1;


// 0 - disabled
// 0< - max allowed nodes
static int MAX_NODE_VIEW = 64;


// 0 - disabled
// 0< - max allowed levels
static int MAX_GRAPH_VIEW = 5;
//---------------------------------------------


//-- Custom value struct adaptation -----------
// Edit these two functions if you define a
// custom value struct. These are the only
// two functions that interface with the
// value struct.

int bst_compare(BstValue a, BstValue b)
{
    // O(1)
    // Precondition:
    // * This function is adapdted
    // if custom value struct is used

    // Postcondition:
    // * Compared two values and:
    //   + returns -1 if a is prefered over b
    //   + returns 0 if values are equal
    //   + returns 1 if b is prefered over a

    if(a.number > b.number)
    {
        return -1;
    }
    else if(a.number == b.number)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


void bst_print_value(BstValue value)
{
    // O(1)
    // Precondition:
    // * This function is adapdted
    // if custom value struct is used

    // Postcondition:
    // * Prints node value in desired way

    printf("%d", value.number);

    return;
}
//=============================================


// Data getting functions
BstValue bst_get_most_right(BstNode *root)
{
    // O(log(n))
    // Precondition:

    // Postcondition:
    // * Returns 0 if node is null
    // * Returns most right value if node is not null

    BstValue none;

    if(root == NULL)
    {
        none.number = 0;

        return none;
    }

    while(root->right != NULL)
    {
        root = root->right;
    }

    return root->value;
}


int bst_get_height(BstNode *node)
{
    // O(1)
    // Precondition:

    // Postcondition:
    // * Returns 0 if node is null
    // * Returns node height if node is not null

    if(node == NULL)
    {
        return 0;
    }
    else
    {
        return node->height;
    }
}


int bst_get_node_balance(BstNode *node)
{
    // O(1)
    // Precondition:

    // Postcondition:
    // * Returns 0 if node is null
    // * Returns balance of node

    if(node == NULL)
    {
        return 0;
    }

    return bst_get_height(node->left) - bst_get_height(node->right);
}


int bst_get_node_count(BstNode *root)
{
    // O(n)
    // Precondition:

    // Postcondition:
    // * Tree node count must be a non negative number

    int left_count, right_count;

    if(root == NULL)
    {
        return 0;
    }

    left_count = bst_get_node_count(root->left);
    right_count = bst_get_node_count(root->right);

    return left_count + right_count + 1;
}


int bst_get_tree_balance(BstNode *root)
{
    // O(n)
    // Precondition:

    // Postcondition:
    // * Returns tree height if balanced
    // * Returns -1 if tree is unbalanced

    int left, right;

    if(root == NULL)
    {
        return 0;
    }

    left = bst_get_tree_balance(root->left);
    right = bst_get_tree_balance(root->right);

    if(left == -1 || right == -1)
    {
        return -1;
    }

    if(1 < abs(left - right))
    {
        return -1;
    }

    if(left > right) 
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}


int max(int a, int b)
{
    // O(1)
    // Precondition:

    // Postcondition:
    // * Returns a value if a is larger than b
    // * Returns b value if a is larger than a

    if(b < a)
    {
        return a;
    }
    else
    {
        return b;
    }
}


// Data altering functions functions
void bst_array_to_tree(BstNode **root, BstValue *value_array, int left_p, int right_p)
{
    // O(n)

    // Precondition:
    // Value array is sorted

    // Postcondition:
    // Binary search tree is balanced

    int middle;

    if(left_p < 0)
    {
        return;
    }

    if(left_p > right_p)
    {
        return;
    }

    middle = left_p + (right_p - left_p) / 2;

    bst_insert(root, value_array[middle]);

    bst_array_to_tree(root, value_array, left_p, middle - 1);

    bst_array_to_tree(root, value_array, middle + 1, right_p);

    return;
}


void bst_balance_tree(BstNode **root)
{
    // NOTE: if AUTO_BLANCING is enabled
    // complexity is O(n * n), thus
    // one should not use this fucntion
    // if AUTO_BALNACING is enabled

    // O(n)
    // Precondition:
    // Input tree is a binary search tree

    // Postcondition:
    // Root pointer is changed
    // Binary search tree is balanced

    int tree_node_count, left_p;
    BstValue *value_array;

    tree_node_count = bst_get_node_count(*root);

    if(tree_node_count == 0)
    {
        return;
    }

    left_p = 0;
    value_array = (BstValue *) malloc(sizeof(BstValue) * (unsigned int)tree_node_count);

    bst_tree_to_array(*root, value_array, &left_p);

    bst_destroy_tree(root);

    for(int i = 0; i < tree_node_count; i++)
    {
        printf("%d ", value_array[i].number);
    }

    bst_array_to_tree(root, value_array, 0, tree_node_count - 1);

    free(value_array);

    return;
}


void bst_balance_node(BstNode **node)
{
    // O(1)
    // Precondition:

    // Postcondition:
    // * Node is balanced if tree balance was off by one node

    int balance;

    balance = bst_get_node_balance(*node);

    if(1 < balance)
    {
        if(bst_get_node_balance((*node)->left) <= -1)
        {
            bst_rotate_left(&(*node)->left);
        }

        bst_rotate_right(node);
    }
    else if(balance < -1)
    {
        if(1 <= bst_get_node_balance((*node)->right))
        {
            bst_rotate_right(&(*node)->right);
        }

        bst_rotate_left(node);
    }

    return;
}


int bst_delete_value(BstNode **root, BstValue value)
{
    // O(log(n))
    // Precondition:

    // Postcondition:
    // * Returns 0 if success
    // * Returns 1 if value is not found
    // * Returns 2 if comparison has failed
    // * If duplicated values exist only one value is deleted

    BstNode *temp;
    int error, compare;

    if(*root == NULL)
    {
        return 1;
    }

    compare = bst_compare((*root)->value, value);

    if(compare == -1)
    {
        error = bst_delete_value(&(*root)->left, value);
    }
    else if(compare == 0)
    {
        if((*root)->left == NULL)
        {
            temp = *root;
            *root = (*root)->right;
            bst_destroy_node(&temp);

            return 0;
        }
        else if((*root)->right == NULL)
        {
            temp = *root;
            *root = (*root)->left;
            bst_destroy_node(&temp);

            return 0;
        }

        (*root)->value = bst_get_most_right((*root)->left);

        error = bst_delete_value(&(*root)->left, (*root)->value);
    }
    else if(compare == 1)
    {
        error = bst_delete_value(&(*root)->right, value);
    }
    else
    {
        error = 2;
    }

    if(error)
    {
        return error;
    }

    (*root)->height = max(bst_get_height((*root)->left), bst_get_height((*root)->right)) + 1;

    if(AUTO_BALANCE)
    {
        bst_balance_node(root);
    }

    return 0;
}


void bst_destroy_node(BstNode **node)
{
    // O(1)
    // Precondition:

    // Postcondition:
    // * Node memory is freed
    // * Node pointer is set to NULL

    free(*node);

    *node = NULL;

    return;
}


void bst_destroy_tree(BstNode **root)
{
    // O(n)
    // Precondition:

    // Postcondition:
    // * Tree memory is freed
    // * Root pointer is set to NULL

    if(*root == NULL)
    {
        return;
    }

    bst_destroy_tree(&(*root)->left);
    bst_destroy_tree(&(*root)->right);

    bst_destroy_node(root);

    return;
}


int bst_insert(BstNode **root, BstValue value)
{
    // O(log(n))
    // Precondition:
    // * Binary tree is balanced

    // Postcondition:
    // * Binary tree is balanced
    // * Returns 0 if success
    // * Returns 1 if no space left in memory
    // * Returns 2 comparison has failed
    // * Returns 3 if value already exists (if duplictes are not enabled)

    BstNode *new_node;
    int error, compare;

    if(*root == NULL)
    {
       new_node = (BstNode *) malloc(sizeof(BstNode));

        if(new_node == NULL)
        {
            return 1;
        }

        new_node->value = value;
        new_node->height = 1;
        new_node->left = NULL;
        new_node->right = NULL;

        *root = new_node;

        return 0;
    }

    compare = bst_compare((*root)->value, value);

    if(compare == -1)
    {
        error = bst_insert(&(*root)->left, value);
    }
    else if(compare == 0)
    {
        if(ALLOW_DUPLICATES)
        {
            error = bst_insert(&(*root)->left, value);
        }
        else
        {
            return 3;
        }
    }
    else if(compare == 1)
    {
        error = bst_insert(&(*root)->right, value);
    }
    else
    {
        error = 2;
    }

    if(error)
    {
        return error;
    }

    (*root)->height = max(bst_get_height((*root)->left), bst_get_height((*root)->right)) + 1;

    if(AUTO_BALANCE)
    {
        bst_balance_node(root);
    }

    return 0;
}


void bst_rotate_left(BstNode **node)
{
    // O(1)

    // Precondition:
    // * Root node of binary tree is not NULL
    // * Binary tree has a right branch of 
    // min. lenght 1

    // Postcondition:

    BstNode *temp;

    if(*node == NULL || (*node)->right == NULL)
    {
        return;
    }

    temp = *node;
    *node= (*node)->right;
    temp->right = (*node)->left;
    (*node)->left = temp;

    (*node)->left->height = max(bst_get_height((*node)->left->left), bst_get_height((*node)->left->right)) + 1;
    (*node)->height = max(bst_get_height((*node)->left), bst_get_height((*node)->right)) + 1;

    return;
}


void bst_rotate_right(BstNode **node)
{
    // O(1)

    // Precondition:
    // * Root node of binary tree is not NULL
    // * Binary tree has a left branch of 
    // min. lenght 1

    // Postcondition:

    BstNode *temp;

    if(*node == NULL || (*node)->left == NULL)
    {
        return;
    }

    temp = *node;
    *node = (*node)->left;
    temp->left = (*node)->right;
    (*node)->right = temp;

    (*node)->right->height = max(bst_get_height((*node)->right->left), bst_get_height((*node)->right->right)) + 1;
    (*node)->height = max(bst_get_height((*node)->left), bst_get_height((*node)->right)) + 1;

    return;
}


void bst_tree_to_array(BstNode *root, BstValue *value_array, int *left_p)
{
    // O(n)
    // Precondition:
    // Value array size is not smaller than tree node count

    // Postcondition:
    // Tree node values are writen to value_array in the 
    // order that they were originally in the tree

    if(root == NULL)
    {
        return;
    }

    bst_tree_to_array(root->left, value_array, left_p);

    value_array[*left_p] = root->value;
    ++*left_p;

    bst_tree_to_array(root->right, value_array, left_p);

    return;
}


// Outputing to console functions
void bst_print(BstNode *root)
{
    // O(n)

    // Precondition:
    // * Root node of binary tree is not NULL
    // * Binary tree has a left branch of 
    // min. lenght 1

    // Postcondition:

    printf("==============================\n");


    printf("Node count: %d\n", bst_get_node_count(root));
    printf("Height: %d\n", bst_get_height(root));

    if(bst_get_tree_balance(root) == -1)
    {
        printf("Balanced: %sNo%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    }
    else
    {
        printf("Balanced: %sYES%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
    }

    if(MAX_NODE_VIEW)
    {
        bst_print_node(root);
    }

    if(MAX_GRAPH_VIEW)
    {
        bst_print_graphical(root);
    }

    printf("==============================\n\n");

    return;
}


void bst_print_graphical(BstNode *root)
{
    // O(n log(n))

    // Precondition:
    // * Max. binary tree height of 6

    // Postcondition:
    // * Null if binary tree has no nodes
    // * Binary tree graph if more than one element

    int height;

    if(root == NULL)
    {
        printf("Graph view: null\n");
        return;
    }

    height = bst_get_height(root);

    if(MAX_GRAPH_VIEW < height)
    {
        printf("Graph view: tree is too big to display\n");

        return;
    }

    printf("Graph view:\n");

    bst_print_graphical_rec(root, height, 0, 0);

    for(int i = 0; i < height + 1; ++i)
    {
        printf("\n");
    }

    return;
}


void bst_print_graphical_rec(BstNode *root, int max_height, int level, int indent)
{
    // O(n log(n))

    // Precondition:
    // * Max. binary tree height of 6

    // Postcondition:
    // * Print nothing if null
    // * If existing node, then navigate cursor to place
    // printing place, print, then return to start

    int height, distance;

    if(root == NULL)
    {
        return;
    }

    height = max_height - level;

    distance = 0;

    for(int i = 0; i < height; ++i)
    {
        distance*= 2;
        ++distance;
    }

    for(int i = 0; i < level; ++i)
    {
        printf("\n");
    }

    for(int i = 0; i < indent; ++i)
    {
        printf(" ");
    }

    for(int i = 0; i < distance; ++i)
    {
        printf(" ");
    }

    if(root->left != NULL)
    {
        printf(".");
        for(int i = 0; i < distance; ++i)
        {
            printf("_");
        }
    }
    else
    {
        for(int i = 0; i < distance + 1; ++i)
        {
            printf(" ");
        }
    }

    bst_print_value(root->value);

    if(root->right != NULL)
    {
        for(int i = 0; i < distance; ++i)
        {
            printf("_");
        }
        printf(".");
    }

    for(int i = 0; i < level; ++i)
    {
        printf("\x1b[A");
    }

    bst_print_graphical_rec(root->right, max_height, level + 1, indent + (distance + 1)*2);
    bst_print_graphical_rec(root->left, max_height, level + 1, indent);

    return;
}


void bst_print_node(BstNode *root)
{
    // O(n)

    // Precondition:

    // Postcondition:
    // * Null if binary tree has no nodes
    // * Binary tree nodes print if more than one element

    int node_count;

    if(root == NULL)
    {
        printf("Node view: null\n");

        return;
    }

    node_count = bst_get_node_count(root);

    if(MAX_NODE_VIEW < node_count)
    {
        printf("Graph view: tree is too big to display\n");

        return;
    }

    printf("Node view:\n");

    bst_print_node_rec(root, 1);

    return;
}


void bst_print_node_rec(BstNode *root, int level)
{
    // O(n)

    // Precondition:

    // Postcondition:
    // * Print nothing if null
    // * If existing node, print node value
    // and child nodes if they exist


    if(root == NULL)
    {
        return;
    }

    printf("Lvl: %-3d height: %-3d", level, bst_get_height(root));

    if(root->left != NULL)
    {
        bst_print_value(root->left->value);
        printf("<-");
    }
    else
    {
        printf("   ");
    }

    bst_print_value(root->value);

    if(root->right != NULL)
    {
        printf("->");
        bst_print_value(root->right->value);
    }

    printf("\n");

    bst_print_node_rec(root->left, level + 1);
    bst_print_node_rec(root->right, level + 1);

    return;
}
