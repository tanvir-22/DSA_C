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
        printf("error could not create node");
        exit(1);
    }
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    return new_node;
}

void add_left(Node *node, Node *child)
{
    node->left = child;
    if (child != NULL)
    {
        child->parent = node;
    }
}
void add_right(Node *node, Node *child)
{
    node->right = child;
    if (child != NULL)
    {
        child->parent = node;
    }
}
Node *insert_node(Node *root, Node *node)
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
        if (node->data > current_node->data)
        {
            current_node = current_node->right;
        }
        else
        {
            current_node = current_node->left;
        }
    }
    if (parent_node->data < node->data)
    {
        add_right(parent_node, node);
    }
    else
    {
        add_left(parent_node, node);
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
        insert_node(root, node);
    }
    return root;
}
void pre_order(Node *root)
{
    printf("%d-> ", root->data);
    if (root->left != NULL)
    {
        pre_order(root->left);
    }
    if (root->right != NULL)
    {
        pre_order(root->right);
    }
}
int main()
{
    Node *root;
    root = create_bst();
    pre_order(root);
    return (0);
}