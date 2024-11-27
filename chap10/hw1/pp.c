#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

int pop(struct node **top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    struct node *temp = *top;
    int popped_data = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped_data;
}

void print_stack(struct node *top) {
    struct node *temp = top;
    printf("Print Stack\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node *top = NULL;
    int data;

    while (1) {
        if (scanf("%d", &data) != 1 || data <= 0) {
            printf("Print Stack\n");
            print_stack(top);
            break;
        }
        push(&top, data);
    }

    while (top != NULL) {
        pop(&top);
    }

    return 0;
}
