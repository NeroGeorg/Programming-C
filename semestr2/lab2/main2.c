#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node node_t;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

node_t *newNode(int data){
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void appendNode(node_t **head, node_t **head2, int data){
    node_t *new_node = newNode(data);
    if (data % 2 != 0){  
        if (*head == NULL){
            *head = new_node;
        }
        else {
            node_t *cur = *head;
            while (cur->next){
                cur = cur->next;
            }
            cur->next = new_node;
        }
    }
    else {
        if (*head2 == NULL){
            *head2 = new_node;
        }
        else {
            new_node->next = *head2;
            (*head2)->prev = new_node;
            *head2 = new_node;
        }
    }
}

void reverseList(node_t **head) {
    node_t *prev_node = NULL;
    node_t *current = *head;
    node_t *next_node = NULL;
    while (current != NULL) {
        next_node = current->next;
        current->next = prev_node;
        prev_node = current;
        current = next_node;
    }
    *head = prev_node;
    node_t *temp = *head;
    node_t *prev_temp = NULL;
    while (temp != NULL) {
        temp->prev = prev_temp;
        prev_temp = temp;
        temp = temp->next;
    }
}

void linkNode(node_t *head, node_t *head2){
    node_t *cur1 = head->next;
    node_t *cur2 = head2->next;
    node_t *el1 = head;
    node_t *el2 = head2;
    el2->next = el1;
    el2 = el2->next;
    while (cur1 && cur2)
    {
        cur1->prev = cur2;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
}

void printList(node_t *head){
    node_t* cur1 = head;
    while(cur1){
        printf(" %d ->", cur1->data);
        cur1 = cur1->next;
    }
    printf("NULL\n");
}

void printLink(node_t *head, node_t *head2){
    node_t* cur1 = head;
    node_t* cur2 = head2;
    while(cur1 && cur2){
        printf("%d => %d\n", cur1->data, cur2->data);
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    printf("NULL\n");
}

void navigateList(node_t *start) {
    node_t *current = start;
    char input;
    while (1) {
        printf("Current value: %d\n", current->data);        
        printf("Enter (W/D/Q): ");
        scanf(" %c", &input);
        switch (input) {
            case 'D':
            case 'd':
                if (current->next) current = current->next;
                else printf("No next element!\n");
                break;
            case 'W':
            case 'w':
                if (current->prev) current = current->prev;
                else printf("No prev element!\n");
                break;
            case 'q':
            case 'Q':
                return;
            default:
                printf("Unknown commad. Use W/D/Q.\n");
        }
    }
}

int main(){
    int n = 1;
    node_t* head = NULL;
    node_t* head2 = NULL;
    while(n != 0){
        printf("Input n:");
        scanf("%d", &n);
        if (n != 0){
            appendNode(&head, &head2, n);
        }
    }
    reverseList(&head2);
    printList(head);
    printList(head2);
    linkNode(head, head2);
    navigateList(head);
}
