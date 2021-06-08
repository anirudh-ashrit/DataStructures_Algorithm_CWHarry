#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

void inOrder(struct Node *root) {
    if(root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

bool isBST(struct Node *root) {
    static struct Node *prev = NULL;
    if(root != NULL) {
        if(!isBST(root->left))
            return 0;
        if(prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return (isBST(root->right));
    }
    else 
        return 1;
}

struct Node *search(struct Node *root, int key) {
    if(root == NULL)
        return NULL;
    if(root->data == key)
        return root;
    else if(root->data > key)
        return search(root->left, key);
    else 
        return search(root->right, key);
}

struct Node *searchIteration(struct Node *root, int key) {
    while(root != NULL) {
        if(root->data == key)
            return root;
        else if(root->data > key)
            root = root->left;
        else 
            root = root->right;
    }
    return NULL;
}

void insert(struct Node *root, int key) {
    struct Node *prev = NULL;
    while(root != NULL) {
        prev = root;
        if(key == root->data)
            return;
        else if(key < root->data)
            root = root->left;
        else 
            root = root->right;
    }
    struct Node *new = createNode(key);
    if(key < prev->data)
        prev->left = new;
    else
        prev->right = new;
}

int main() {
    struct Node *p, *p1, *p2, *p3, *p4, *key;
    int res;
    p = createNode(5);
    p1 = createNode(3);
    p2 = createNode(6);
    p3 = createNode(1);
    p4 = createNode(4);
    connectNode(p, p1, p2);
    connectNode(p1, p3, p4);
    inOrder(p);
    printf("\n");
    res = isBST(p);
    res ? printf("Tree is BST\n") : printf("Tree is not BST\n");
    // key = search(p, 1);
    key = searchIteration(p, 10);
    if(key != NULL)
        printf("The element found is %d\n", key->data);
    else
        printf("Element not found\n");
    insert(p, 7);
    printf("%d\n", p->right->right);
    return 0;
}