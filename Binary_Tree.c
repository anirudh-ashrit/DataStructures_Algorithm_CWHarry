#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
}

void connectNode(struct Node *node, struct Node *lft, struct Node* rht) {
    node->left = lft;
    node->right = rht;
}

void preOrder(struct Node *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root) {
    if(root != NULL) {
        preOrder(root->left);
        preOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct Node *root) {
    if(root != NULL) {
        preOrder(root->left);
        printf("%d ", root->data);
        preOrder(root->right);
    }
}

int main() {
    struct Node *p, *p1, *p2;
    p = createNode(2);
    p1 = createNode(1);
    p2 = createNode(4);
    connectNode(p, p1, p2);
    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
    return 0;
}