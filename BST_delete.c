#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node *right;
    Node *left;
    Node *parent;
};
Node *create_node(int item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Error could not create node");
        exit(1);
    }
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    return new_node;
}
void add_left(Node *parent_node, Node *child)
{
    parent_node->left = child;
    if (child != NULL)
    {
        child->parent = parent_node;
    }
}
void add_right(Node *parent_node, Node *child)
{
    parent_node->right = child;
    if (child != NULL)
    {
        child->parent = parent_node;
    }
}
Node *insert_tree(Node *root, Node *node)
{
    if (root == NULL)
    {
        root = node;
        return root;
    }
    Node *current_node, *parent_node;
    current_node = root;
    while (current_node != NULL)
    {
        parent_node = current_node;
        if (node->data < current_node->data)
        {
            current_node = current_node->left;
        }
        else
        {
            current_node = current_node->right;
        }
    }
    if (node->data < parent_node->data)
    {
        add_left(parent_node, node);
    }
    else
    {
        add_right(parent_node, node);
    }
    return root;
}
Node *create_bst()
{
    int ara[] = {5, 17, 3, 7, 12, 19, 1, 4};
    int i;
    Node *root, *node;
    root = create_node(10);
    for (i = 0; i < 8; i++)
    {
        node = create_node(ara[i]);
        insert_tree(root, node);
    }
    return root;
}
void in_order(Node *root)
{

    if (root->left != NULL)
    {
        in_order(root->left);
    }
    printf("%d -> ", root->data);
    if (root->right != NULL)
    {
        in_order(root->right);
    }
}
Node *search_bst(Node *root, int item)
{
    Node *node;
    node = root;
    while (node != NULL)
    {
        if (node->data == item)
        {
            return node;
        }
        if (item > node->data)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }
    return node;
}
Node *bst_minimum(Node *root)
{
    Node *node;
    node = root;
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
Node *bst_transplant(Node *root, Node *current_node, Node *new_node)
{
    if (current_node == root)
    {
        root = new_node;
    }
    else if (current_node == current_node->parent->right)
    {
        add_right(current_node->parent, new_node);
    }
    else
    {
        add_left(current_node->parent, new_node);
    }
    return root;
}
Node *delete(Node *root, Node *node)
{
    Node *smallest_node;
    if (node->left == NULL)
    {
        root = bst_transplant(root, node, node->right);
    }
    if (node->right == NULL)
    {
        root = bst_transplant(root, node, node->left);
    }
    else
    {
        smallest_node = bst_minimum(node->right);
        if (smallest_node->parent != node)
        {
            root = bst_transplant(root, smallest_node, smallest_node->right);
            add_right(smallest_node, node->right);
        }
        root = bst_transplant(root, node, smallest_node);
        add_left(smallest_node, node->left);
    }
    free(node);
    return root;
}
int main()
{
    Node *root = create_bst();
    Node *node;
    printf("BST:\n");
    in_order(root);
    printf("\n");
    node = search_bst(root, 1);
    if (node != NULL)
    {
        printf("will delete:%d\n", node->data);
        root = delete (root, node);
        printf("BST:\n");
        in_order(root);
        printf("\n");
    }
    else
    {
        printf("node not found!\n");
    }
    return 0;
}