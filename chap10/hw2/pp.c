#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node *head, struct node *tail, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head->next == NULL) {
        head->next = new_node;
        tail->next = new_node;
    } else {
        tail->next->next = new_node;
        tail->next = new_node;
    }
}

int delete(struct node *head, struct node *tail) {
    if (head->next == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    struct node *temp = head->next;
    int deleted_data = temp->data;
    head->next = temp->next;
    free(temp);

    return deleted_data;
}

void printQueue(struct node *head) {
    struct node *current = head->next;
    if (current == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *tail = (struct node *)malloc(sizeof(struct node));

    head->next = NULL;
    tail->next = NULL;

    char input[100];
    while (1) {
        fgets(input, sizeof(input), stdin);

        if (isdigit(input[0])) {
            int data = atoi(input);
            addq(head, tail, data);
        } else {
            printf("Print queue\n");
            printQueue(head);
        }
    }

    free(head);
    free(tail);
    return 0;
}

