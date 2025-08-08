#include <stdio.h>
#include <stdlib.h>

struct stack {
    int info;
    struct stack *next;
};

void push(struct stack **, int);
int pop(struct stack **);
void display(struct stack *);

int main(void) {
    struct stack *lastnode = NULL;
    int x, option;
    char ch = 'y';

    while (ch == 'y' || ch == 'Y') {
        printf("\nWhat do you want to do? enter....");
        printf("\n1. push");
        printf("\n2. pop");
        printf("\n3. display");
        printf("\nEnter the option: ");
        scanf(" %d", &option);

        switch (option) {
            case 1:
                printf("\nEnter the value to insert into the node: ");
                scanf(" %d", &x);
                push(&lastnode, x);
                break;
            case 2:
                x = pop(&lastnode);
                if (x != -1)
                    printf("\nThe value popped is %d", x);
                break;
            case 3:
                display(lastnode);
                break;
            default:
                printf("\nEnter the right number.");
        }

        printf("\nEnter the option (y/n): ");
        scanf(" %c", &ch);
    }

    return 0;
}

void push(struct stack **last, int x) {
    struct stack *node = (struct stack *)malloc(sizeof(struct stack));
    node->info = x;

    if (*last == NULL) {
        *last = node;
        node->next = node;  // Points to itself (only node)
    } else {
        node->next = (*last)->next;
        (*last)->next = node;
        *last = node;  // Update last to the new top
    }
}

int pop(struct stack **last) {
    if (*last == NULL) {
        printf("\nStack is empty.");
        return -1;
    }

    struct stack *temp, *ptr;
    int item;

    // Only one node
    if (*last == (*last)->next) {
        item = (*last)->info;
        free(*last);
        *last = NULL;
        return item;
    }

    // More than one node
    ptr = (*last)->next; // Start from top
    while (ptr->next != *last) {
        ptr = ptr->next;
    }

    temp = *last;
    item = temp->info;
    ptr->next = temp->next;
    *last = ptr;
    free(temp);

    return item;
}

void display(struct stack *last) {
    struct stack *temp;

    if (last == NULL) {
        printf("\nStack is empty.");
        return;
    }

    printf("Stack contents (Top to Bottom):\n");
    temp = last;
    do {
        printf("%d\n", temp->info);
        temp = temp->next;
    } while (temp != last);
}
