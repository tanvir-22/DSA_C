#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node *left;
    Node *right;
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
    return new_node;
}

void add_left(Node *node, Node *child)
{
    node->left = child;
}
void add_right(Node *node, Node *child)
{
    node->right = child;
}

Node *create_tree()
{
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left(two, seven);
    add_right(two, nine);
    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left(seven, one);
    add_right(seven, six);
    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left(six, five);
    add_right(six, ten);
    Node *eight = create_node(8);
    Node *three = create_node(3);
    Node *four = create_node(4);

    add_right(nine, eight);
    add_left(eight, three);
    add_right(eight, four);
    return two;
}

void pre_order(Node *node)
{
    printf("%d->", node->data);
    if (node->left != NULL)
    {
        pre_order(node->left);
    }
    if (node->right != NULL)
    {
        pre_order(node->right);
    }
}
int main()
{
    Node *root = create_tree();
    pre_order(root);
    return 0;
}