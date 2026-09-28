#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int bstSearch(struct Node* root, int key, int *comparisons) {
    while (root != NULL) {
        (*comparisons)++;

        if (key == root->data) {
            return 1;
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return 0;
}

int linearSearch(int arr[], int n, int key, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;

        if (arr[i] == key) {
            return 1;
        }
    }

    return 0;
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    int isbn[] = {45, 20, 60, 10, 30, 50, 70, 25, 55};
    int n = sizeof(isbn) / sizeof(isbn[0]);
    int searchKeys[] = {25, 55, 90};
    int searchCount = sizeof(searchKeys) / sizeof(searchKeys[0]);

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, isbn[i]);
    }

    printf("ONLINE BOOKSTORE - BST ASSIGNMENT\n");
    printf("=================================\n\n");

    printf("Input ISBNs: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", isbn[i]);
    }
    printf("\n\n");

    printf("Inorder Traversal   : ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal  : ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal : ");
    postorder(root);
    printf("\n\n");

    printf("Search Results\n");
    printf("---------------------------------------------------------------\n");
    printf("Key\tBST Result\tBST Comparisons\tLinear Comparisons\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < searchCount; i++) {
        int bstComparisons = 0;
        int linearComparisons = 0;

        int bstFound = bstSearch(root, searchKeys[i], &bstComparisons);
        int linearFound = linearSearch(isbn, n, searchKeys[i], &linearComparisons);
        (void)linearFound;

        printf("%d\t%s\t\t%d\t\t%d\n",
               searchKeys[i],
               bstFound ? "Found" : "Not Found",
               bstComparisons,
               linearComparisons);
    }

    printf("---------------------------------------------------------------\n");

    freeTree(root);
    return 0;
}
