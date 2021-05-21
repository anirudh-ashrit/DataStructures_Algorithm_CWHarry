#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head_1 = NULL;
struct Node *head_2 = NULL;

void printFor(struct Node *head)
{
    printf("Ricemon\n");
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int length(struct Node *head) {
    struct Node *ptr = head;
    int count = 0;
    while(ptr != NULL) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

struct Node *findInter(struct Node *h1, struct Node *h2) {
    struct Node *ptr_1 = h1, *ptr_2 = h2;
    int len_1, len_2, len;
    len_1 = length(head_1);
    len_2 = length(head_2);
    if(len_1 < len_2) {
        len = len_2 - len_1;
        while(len != 0) {
            ptr_2 = ptr_2->next;
            len--;
        }     
    }
    else {
        len = len_1 - len_2;
        while(len != 0) {
            ptr_1 = ptr_1->next;
            len--;
        }
    }
    while(ptr_1 != ptr_2) {
        ptr_2 = ptr_2->next;
        ptr_1 = ptr_1->next;
    }
    return ptr_1;
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

int main()
{
    for (int i = 0; i < 7; i++)
        head_1 = create_list(head_1, i);

    for (int i = 0; i < 4; i++)
        head_2 = create_list(head_2, i);
    struct Node *pt = head_2;
    while(pt->next != NULL)
        pt = pt->next;
    pt->next = head_1->next->next;
    // printFor(head_1);
    // printFor(head_2);
    struct Node *pointer = findInter(head_1, head_2);
    printf("Inter: %d\n", pointer->data);
}