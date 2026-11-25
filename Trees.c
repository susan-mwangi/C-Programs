#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

// Node out of the function - Create new Node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for Inorder - Left, Root, Right
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// Function for Preorder - Root, Left, Right
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for Postorder - Left, Right, Root
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

// Function for Level Order - using Queue
void levelorder(struct Node* root) {
    if (root == NULL) return;
    struct Node* queue[20];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%c ", temp->data);
        if (temp->left != NULL) queue[rear++] = temp->left;
        if (temp->right != NULL) queue[rear++] = temp->right;
    }
}

int main() {
    // Build tree from your Exercise
    //        A
    //      /   \
    //     B     C
    //    /     / \
    //   D     E   F
    //        /   / \
    //       G   H   I
    struct Node* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->right->left = createNode('E');
    root->right->right = createNode('F');
    root->right->left->left = createNode('G');
    root->right->right->left = createNode('H');
    root->right->right->right = createNode('I');

    // Call all of them
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nLevel Order: ");
    levelorder(root);

    return 0;
}
