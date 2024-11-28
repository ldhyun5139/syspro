#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
void addq(struct node **head, struct node **tail, int data) {
    struct node *n_node = (struct node *)malloc(sizeof(struct node));
    

	n_node->data = data;
    n_node->next = NULL;
    if (*tail == NULL) {
        *head = n_node;
        *tail = n_node;
    } 



	else {

        (*tail)->next = n_node;
        *tail = n_node;
    }
}




int delete(struct node **head, struct node **tail) {
    if (*head == NULL) {



        printf("Queue is empty.\n");
        return -1;
    }
    struct node *temp = *head;
    int deleted_data = temp->data;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    free(temp);
    return deleted_data;
}

void print_queue(struct node *head) {
    struct node *temp = head;
	printf("Print Queue\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    int data;

    while (1) {

        if (scanf("%d", &data) != 1 || data <= 0) {
            print_queue(head);
            break;
        }
        addq(&head, &tail, data);
    }

    while (head != NULL) {
        delete(&head, &tail);
    }

    return 0;
}
