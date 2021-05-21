#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head, *curr, *prev, *after;

void print(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *create_list(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;

    struct Node *ptr = head;
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
    }
    else
    {
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
    return head;
}

struct Node *rev(struct Node *hd) {
    curr = hd;
    while(curr != NULL) {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return prev;
}

int length(struct Node *ptr) {

    int count = 0;
    while(ptr != NULL) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

int palind() {
    
    struct Node *sp = head, *fp = head, *ptr = head, *n_hd;
    int len = length(ptr);

    while(fp != NULL && fp->next != NULL) {
        sp = sp->next;
        fp = fp->next->next;
    }
    if((len % 2) == 0) 
        n_hd = rev(sp);
    else
        n_hd = rev(sp->next);
    while(n_hd != NULL) {
        if(ptr->data == n_hd->data) {
            ptr = ptr->next;
            n_hd = n_hd->next;
        }
        else return 0;
    }
    return 1;
}

int main() {
    
    print(head);
    struct Node *hd = rev(hd);
    printf("Reversed list is\n");
    print(hd);
    // head = create_list(head, 1);
    // head = create_list(head, 2);
    // head = create_list(head, 3);
    // head = create_list(head, 4);
    // head = create_list(head, 3);
    // head = create_list(head, 2);
    // head = create_list(head, 1);
    // palind() ? printf("List is palindrome\n") : printf("List is not palindrome\n");
}
