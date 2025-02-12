#include "bst.h"

int main(int argc, char *argv[])
{
    node *root = NULL;

    printf("Unbalanced binary tree (if AUTO_BALANCING disabled)\n");
    insert(&root, 4);
    insert(&root, 2);
    insert(&root, 1);
    insert(&root, 3);
    print_tree(root);

    printf("Balanced binary tree\n");
    destroy_tree(&root);
    insert(&root, 8);
    insert(&root, 4);
    insert(&root, 12);
    insert(&root, 2);
    insert(&root, 6);
    insert(&root, 10);
    insert(&root, 14);
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 5);
    insert(&root, 7);
    insert(&root, 9);
    insert(&root, 11);
    insert(&root, 13);
    insert(&root, 15);
    print_tree(root);

    printf("Balanced binary tree, with larger numbers \n");
    destroy_tree(&root);
    insert(&root, 104);
    insert(&root, 102);
    insert(&root, 106);
    insert(&root, 101);
    insert(&root, 103);
    insert(&root, 105);
    insert(&root, 107);
    print_tree(root);

    printf("Large binary tree (if AUTO_BALANCING enabled)\n");
    destroy_tree(&root);
    for(int i = 1; i < 64; ++i)
    {
        insert(&root, i);
    }
    if(is_tree_balanced(root) != -1)
    {
        print_tree(root);
    }

    printf("Binary tree with duplicated (if ALLOW_DUPLICATES enabled)\n");
    destroy_tree(&root);
    for(int i = 9; i > 0; --i)
    {
        insert(&root, i);
        if(i == 5)
        {
            insert(&root, i);
            insert(&root, i);
            insert(&root, i);
            insert(&root, i);
            insert(&root, i);
        }
    }
    print_tree(root);

    return 0;
}
