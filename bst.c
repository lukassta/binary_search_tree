// Lukas Stavaris
// LSP 2414004
// Program: PS, Course: 1, Group: 4
// Query 18
//----------------------------

#include "bst.h"

static int ALLOW_DUPLICATES = 1;
static int AUTO_BALANCE = 1;
static int NODE_VIEW = 1;
static int GRAPH_VIEW = 1;


int tree_height(node *root)
{
    // O(n)
    // Precondition:

    // Postcondition:
    // * Tree height must be a non engative number

    int left, right;

    if(root == NULL)
    {
        return 0;
    }

    left = tree_height(root->left);
    right = tree_height(root->right);
    if(left > right)
    {
        return left + 1;
    }

    return right + 1;
}


int tree_node_count(node *root)
{
    // O(n)
    // Precondition:

    // Postcondition:
    // * Tree node count must be a non negative number

    int left, right;

    if(root == NULL)
    {
        return 0;
    }

    left = tree_node_count(root->left);
    right = tree_node_count(root->right);

    return left + right + 1;
}


int is_tree_balanced(node *root)
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

    left = is_tree_balanced(root->left);
    right = is_tree_balanced(root->right);

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


void balance_tree(node **root)
{
    if(*root == NULL)
    {
        return;
    }


    while(1 < abs(tree_node_count((*root)->left) - tree_node_count((*root)->right)))
    {
        if(tree_height((*root)->left) < tree_height((*root)->right))
        {
            rotate_tree_left(root);
        }
        else
        {
            rotate_tree_right(root);
        }
    }

    balance_tree(&((*root)->left));
    balance_tree(&((*root)->right));

    return;
}


void destroy_node(node **node)
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


void destroy_tree(node **root)
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

    destroy_tree(&(*root)->left);
    destroy_tree(&(*root)->right);

    destroy_node(root);

    return;
}


void insert(node **root, int value)
{
    // O(log(n) * n)
    // Precondition:
    // * Binary tree is balanced

    // Postcondition:
    // * Binary tree is balanced

    node *temp_node, *new_node;
    int left_height, right_height;

    new_node = (node *) malloc(sizeof(node));
    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if(*root == NULL)
    {
        *root = new_node;
        return;
    }

    if((*root)->val > value)
    {
        insert(&(*root)->left, value);

        if(AUTO_BALANCE && is_tree_balanced(*root) == -1)
        {
            rotate_tree_right(root);
        }
    }
    else if((*root)->val < value)
    {
        insert(&(*root)->right, value);

        if(AUTO_BALANCE && is_tree_balanced(*root) == -1)
        {
            rotate_tree_left(root);
        }
    }
    else if(ALLOW_DUPLICATES)
    {
        insert(&(*root)->left, value);
        if(AUTO_BALANCE && is_tree_balanced(*root) == -1)
        {
            rotate_tree_right(root);
        }
    }

    return;
}


void rotate_tree_left(node **root)
{
    // O(1)

    // Precondition:
    // * Root node of binary tree is not NULL
    // * Binary tree has a right branch of 
    // min. lenght 1

    // Postcondition:

    node *temp;

    temp = *root;

    if(*root == NULL && (*root)->right == NULL)
    {
        return;
    }

    *root = (*root)->right;
    temp->right = (*root)->left;
    (*root)->left = temp;

    return;
}


void rotate_tree_right(node **root)
{
    // O(1)

    // Precondition:
    // * Root node of binary tree is not NULL
    // * Binary tree has a left branch of 
    // min. lenght 1

    // Postcondition:

    node *temp;

    temp = *root;

    if(*root == NULL && (*root)->left == NULL)
    {
        return;
    }

    *root = (*root)->left;
    temp->left = (*root)->right;
    (*root)->right = temp;

    return;
}


void print_tree(node *root)
{
    // O(n)

    // Precondition:
    // * Root node of binary tree is not NULL
    // * Binary tree has a left branch of 
    // min. lenght 1

    // Postcondition:

    printf("==============================\n");

    printf("Node count: %d\n", tree_node_count(root));
    printf("Height: %d\n", tree_height(root));

    if(is_tree_balanced(root) == -1)
    {
        printf("Balanced: No\n");
    }
    else
    {
        printf("Balanced: Yes\n");
    }

    if(NODE_VIEW)
    {
        printf("Node view:\n");
        print_tree_node_rec(root, 0);
    }

    if(GRAPH_VIEW)
    {
        print_tree_graphical(root);
    }

    printf("==============================\n\n");

    return;
}


void print_tree_graphical(node *root)
{
    // O(n)

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

    height = tree_height(root) - 1;

    printf("Graph view:\n");

    print_tree_graphical_rec(root, height, 0, 0);

    for(int i = 0; i < height + 1; ++i)
    {
        printf("\n");
    }

    return;
}


void print_tree_graphical_rec(node *root, int max_height,int level, int indent)
{
    // O(n)

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

    printf("%d", root->val);


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

    print_tree_graphical_rec(root->right, max_height, level + 1, indent + (distance + 1)*2);
    print_tree_graphical_rec(root->left, max_height, level + 1, indent);

    return;
}


void print_tree_node_rec(node *root, int level)
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

    printf("Lvl: %-3d", level);

    if(root->left != NULL)
    {
        printf("%3d<-", root->left->val);
    }
    else
    {
        printf("     ");
    }

    printf("%d", root->val);
    if(root->right != NULL)
    {
        printf("->%-3d\n", root->right->val);
    }
    else
    {
        printf("     \n");
    }

    print_tree_node_rec(root->left, level + 1);
    print_tree_node_rec(root->right, level + 1);

    return;
}
