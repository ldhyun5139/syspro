#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};
// push stack
void push(struct node **top, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}
// delet stcak
int pop(struct node **top){  
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct node *temp = *top;
    int popped_data = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped_data;
}

void print_stack(struct node *top) {
    struct node *current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void process_input(struct node **top, char *input) {
    int is_valid_number = 1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            is_valid_number = 0;
            break;
        }
    }

    if (is_valid_number) {
        int num = atoi(input);
        push(top, num);
    }

	else {
		printf("Print stack\n");

        print_stack(*top);
    }
}

int main() {
    struct node *top = NULL;
    char input[100];

    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (input[0] == '\0') {
            break;
        }

        process_input(&top, input);
    }

    return 0;
}

