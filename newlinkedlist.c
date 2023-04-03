#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

/*append function*/
void append(node **head, int element) {
    node *new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = element;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

/*delete function to delete all the elements with the same data element*/
void delete(node *head, int element) {
    node *temp = head;
    node *prev = NULL;
    node *nextnode;
    while (temp != NULL) {
        if (temp->data == element) {
            if (prev == NULL) { // element is the head node
                head = temp->next;
            } else {
                nextnode = temp->next;
                prev->next = nextnode;
                free(temp);
                temp = nextnode;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    node *head = NULL;
    append(&head, 0);
    append(&head, 4);
    append(&head, 4);
    append(&head,7);
    delete(head, 4);
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    return 0;
}
