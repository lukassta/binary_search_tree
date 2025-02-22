#include "bst.h"

BstValue get_value(int input)
{
    BstValue value;

    value.number = input;

    return value;
}

int main(int argc, char *argv[])
{
    BstNode *root = NULL;

    printf("PREVIEW OF BINARY SEARCH TREE LIBRARY\n\n");

    printf("Empty binary search tree:\n");
    bst_print(root);

    printf("Unbalanced binary search tree (if AUTO_BALANCING disabled):\n");
    bst_insert(&root, get_value(8));
    bst_insert(&root, get_value(3));
    bst_insert(&root, get_value(2));
    bst_insert(&root, get_value(1));
    bst_insert(&root, get_value(0));
    bst_insert(&root, get_value(4));
    bst_insert(&root, get_value(5));
    bst_insert(&root, get_value(6));
    bst_print(root);

    printf("Unbalanced binary search tree after balancing:\n");
    bst_balance_tree(&root);
    bst_print(root);

    printf("Balanced binary search tree:\n");
    bst_destroy_tree(&root);
    bst_insert(&root, get_value(8));
    bst_insert(&root, get_value(4));
    bst_insert(&root, get_value(12));
    bst_insert(&root, get_value(2));
    bst_insert(&root, get_value(6));
    bst_insert(&root, get_value(10));
    bst_insert(&root, get_value(14));
    bst_insert(&root, get_value(1));
    bst_insert(&root, get_value(3));
    bst_insert(&root, get_value(5));
    bst_insert(&root, get_value(7));
    bst_insert(&root, get_value(9));
    bst_insert(&root, get_value(11));
    bst_insert(&root, get_value(13));
    bst_insert(&root, get_value(15));
    bst_print(root);

    printf("Balanced binary search tree, with larger numbers:\n");
    bst_destroy_tree(&root);
    bst_insert(&root, get_value(100004));
    bst_insert(&root, get_value(100002));
    bst_insert(&root, get_value(100006));
    bst_insert(&root, get_value(100001));
    bst_insert(&root, get_value(100003));
    bst_insert(&root, get_value(100005));
    bst_insert(&root, get_value(100007));
    bst_print(root);

    printf("Large binary search tree (if AUTO_BALANCING enabled):\n");
    bst_destroy_tree(&root);
    for(int i = 1; i < 32; ++i)
    {
        bst_insert(&root, get_value(i));
    }
    bst_print(root);

    printf("Binary search tree with duplicated values (if ALLOW_DUPLICATES enabled):\n");
    bst_destroy_tree(&root);
    /*for(int j = 0; j < 4; ++j)*/
    /*{*/
    /*    bst_insert(&root, get_value(5));*/
    /*}*/
    bst_insert(&root, get_value(8));
    bst_insert(&root, get_value(4));
    bst_insert(&root, get_value(8));
    bst_insert(&root, get_value(8));
    bst_insert(&root, get_value(2));
    bst_insert(&root, get_value(1));
    bst_insert(&root, get_value(3));
    bst_insert(&root, get_value(12));
    bst_insert(&root, get_value(10));
    bst_insert(&root, get_value(9));
    bst_insert(&root, get_value(11));
    bst_insert(&root, get_value(14));
    bst_insert(&root, get_value(13));
    bst_insert(&root, get_value(15));
    bst_print(root);

    return 0;
}
