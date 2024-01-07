#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_Node(int item, Node *next)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("ERROR!could not create Node");
        exit(1);
    }
    new_node->data = item;
    new_node->next = next;
    return new_node;
}

Node *prepend(int item, Node *head)
{
    Node *new_node = create_Node(item, head);
    return new_node;
}

Node *append(int item, Node *head)
{
    Node *new_node = create_Node(item, NULL);
    if (head == NULL)
    {
        return new_node;
    }
    Node *current_node = head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}
void insert(int item, Node *node)
{
    Node *new_node = create_Node(item, node->next);
    node->next = new_node;
}
void print_linked_list(Node *head)
{
    Node *current_node = head;
    while (current_node != NULL)
    {
        printf("%d-> ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n\n");
}

Node *remove_node(Node *head, Node *node)
{
    if (head == node)
    {
        head = node->next;
        free(node);
        return head;
    }
    Node *current_node = head;
    while (current_node != NULL)
    {
        if (current_node->next == node)
        {
            break;
        }
        current_node = current_node->next;
    }
    if (current_node == NULL)
    {

        return head;
    }
    current_node->next = node->next;
    free(node);
    return head;
}
int main()
{

    Node *head, *n1, *n2;
    n1 = create_Node(200, NULL);
    head = n1;
    print_linked_list(head);
    head = prepend(555, head);
    print_linked_list(head);
    head = append(111, head);
    print_linked_list(head);
    head = remove_node(head, n1);
    print_linked_list(head);
    return 0;
}
