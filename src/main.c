/**
 * ============================================================================
 * Assignment: Binary Search Tree (BST) vs. Linear Search for Bookstore ISBNs
 * ============================================================================
 * Description:
 *   a) Construct a Binary Search Tree (BST) by inserting the given ISBN keys:
 *      [45, 20, 60, 10, 30, 50, 70, 25, 55]
 *      Display the tree using Inorder, Preorder, and Postorder traversals.
 *   b) Search for keys 25, 55, and 90 using:
 *      - BST Search
 *      - Linear Search
 *      Record and compare the number of comparisons required for each search.
 *   c) Performance comparison and theoretical complexity evaluation.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT 5

/* Structure for a Binary Search Tree node */
typedef struct BSTNode {
    int isbn;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

/* Function to create a new BST node */
BSTNode* createNode(int isbn) {
    BSTNode *newNode = (BSTNode*)malloc(sizeof(BSTNode));
    if (!newNode) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->isbn = isbn;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Function to insert a key into the BST */
BSTNode* insertBST(BSTNode *root, int isbn) {
    if (root == NULL) {
        return createNode(isbn);
    }
    if (isbn < root->isbn) {
        root->left = insertBST(root->left, isbn);
    } else if (isbn > root->isbn) {
        root->right = insertBST(root->right, isbn);
    } else {
        /* Duplicate keys are ignored in standard BST */
        printf("Note: ISBN %d already exists in the tree.\n", isbn);
    }
    return root;
}

/* Traversal: Inorder (Left -> Root -> Right) */
void inorderTraversal(BSTNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->isbn);
        inorderTraversal(root->right);
    }
}

/* Traversal: Preorder (Root -> Left -> Right) */
void preorderTraversal(BSTNode *root) {
    if (root != NULL) {
        printf("%d ", root->isbn);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

/* Traversal: Postorder (Left -> Right -> Root) */
void postorderTraversal(BSTNode *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->isbn);
    }
}

/* Function to compute the height of the BST (in edges) */
int getTreeHeight(BSTNode *root) {
    if (root == NULL) {
        return -1; // Empty tree height is -1 (or 0 nodes)
    }
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

/* Function to print a 2D representation of the BST */
void print2DUtil(BSTNode *root, int space) {
    if (root == NULL) return;

    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space count
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("[%d]\n", root->isbn);

    // Process left child
    print2DUtil(root->left, space);
}

void printTreeStructure(BSTNode *root) {
    printf("Visual Tree Representation (Rotated 90 degrees counter-clockwise):\n");
    printf("-----------------------------------------------------------------\n");
    print2DUtil(root, 0);
    printf("-----------------------------------------------------------------\n");
}

/* Search an ISBN key in BST while recording comparisons and search path */
bool searchBST(BSTNode *root, int key, int *comparisons, int path[], int *pathLen) {
    BSTNode *curr = root;
    *comparisons = 0;
    *pathLen = 0;

    while (curr != NULL) {
        (*comparisons)++;
        path[(*pathLen)++] = curr->isbn;

        if (key == curr->isbn) {
            return true; // Key found
        } else if (key < curr->isbn) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return false; // Key not found
}

/* Linear Search for an ISBN key in array while recording comparisons */
int searchLinear(const int arr[], int size, int key, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < size; i++) {
        (*comparisons)++;
        if (arr[i] == key) {
            return i; // Found at index i
        }
    }
    return -1; // Not found
}

/* Free allocated memory for BST */
void freeBST(BSTNode *root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main(void) {
    const int isbns[] = {45, 20, 60, 10, 30, 50, 70, 25, 55};
    const int numISBNs = sizeof(isbns) / sizeof(isbns[0]);

    printf("=========================================================================\n");
    printf("       ONLINE BOOKSTORE ISBN MANAGEMENT SYSTEM: BST vs LINEAR SEARCH     \n");
    printf("=========================================================================\n\n");

    /* ---------------------------------------------------------
     * PART A: Binary Search Tree Construction and Traversals
     * --------------------------------------------------------- */
    printf("-------------------------------------------------------------------------\n");
    printf("PART A: BST Construction and Traversals\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Input ISBN sequence for insertion:\n  ");
    for (int i = 0; i < numISBNs; i++) {
        printf("%d%s", isbns[i], (i == numISBNs - 1) ? "\n\n" : ", ");
    }

    BSTNode *root = NULL;
    for (int i = 0; i < numISBNs; i++) {
        root = insertBST(root, isbns[i]);
    }
    printf("BST successfully constructed.\n\n");

    // Display Traversals
    printf("Traversals of the Constructed BST:\n");
    printf("  1. Inorder Traversal   (L, Root, R): ");
    inorderTraversal(root);
    printf("\n     (Note: Inorder yields strictly sorted ISBNs in ascending order)\n\n");

    printf("  2. Preorder Traversal  (Root, L, R): ");
    preorderTraversal(root);
    printf("\n\n");

    printf("  3. Postorder Traversal (L, R, Root): ");
    postorderTraversal(root);
    printf("\n\n");

    int height = getTreeHeight(root);
    printf("Tree Properties:\n");
    printf("  - Total Nodes: %d\n", numISBNs);
    printf("  - Tree Height (edges from root): %d\n", height);
    printf("  - Maximum Levels: %d\n\n", height + 1);

    printTreeStructure(root);
    printf("\n");

    /* ---------------------------------------------------------
     * PART B: Searching using BST and Linear Search
     * --------------------------------------------------------- */
    printf("-------------------------------------------------------------------------\n");
    printf("PART B: Searching Keys [25, 55, 90]\n");
    printf("-------------------------------------------------------------------------\n");

    const int searchKeys[] = {25, 55, 90};
    const int numQueries = sizeof(searchKeys) / sizeof(searchKeys[0]);

    int bstComparisons[3];
    int linearComparisons[3];
    bool bstFound[3];
    int linearIndex[3];

    for (int q = 0; q < numQueries; q++) {
        int key = searchKeys[q];
        int bstComp = 0;
        int path[32];
        int pathLen = 0;

        bool foundBST = searchBST(root, key, &bstComp, path, &pathLen);
        bstComparisons[q] = bstComp;
        bstFound[q] = foundBST;

        int linComp = 0;
        int idx = searchLinear(isbns, numISBNs, key, &linComp);
        linearComparisons[q] = linComp;
        linearIndex[q] = idx;

        printf("Searching for ISBN Key: %d\n", key);
        printf("  [BST Search]:\n");
        printf("    Path Traversed: ");
        for (int p = 0; p < pathLen; p++) {
            printf("%d%s", path[p], (p == pathLen - 1) ? "" : " -> ");
        }
        printf("\n    Result: %s | Comparisons: %d\n", foundBST ? "FOUND" : "NOT FOUND", bstComp);

        printf("  [Linear Search]:\n");
        printf("    Array Inspection: Checked indices 0 to %d\n", linComp - 1);
        printf("    Result: %s | Comparisons: %d\n\n", (idx != -1) ? "FOUND" : "NOT FOUND", linComp);
    }

    /* ---------------------------------------------------------
     * Summary Table of Comparisons
     * --------------------------------------------------------- */
    printf("-------------------------------------------------------------------------\n");
    printf("COMPARISON SUMMARY TABLE\n");
    printf("-------------------------------------------------------------------------\n");
    printf("+------------+----------------+-------------------+----------------------+\n");
    printf("| Search Key | Search Status  | BST Comparisons   | Linear Comparisons   |\n");
    printf("+------------+----------------+-------------------+----------------------+\n");
    for (int q = 0; q < numQueries; q++) {
        printf("| %-10d | %-14s | %-17d | %-20d |\n",
               searchKeys[q],
               bstFound[q] ? "FOUND" : "NOT FOUND",
               bstComparisons[q],
               linearComparisons[q]);
    }
    printf("+------------+----------------+-------------------+----------------------+\n\n");

    /* ---------------------------------------------------------
     * PART C: Brief Observations & Analysis
     * --------------------------------------------------------- */
    printf("-------------------------------------------------------------------------\n");
    printf("PART C: Analytical Observations\n");
    printf("-------------------------------------------------------------------------\n");
    printf("1. Tree Shape & Height Influence:\n");
    printf("   - The constructed BST is balanced with height = %d (4 levels).\n", height);
    printf("   - At each step, BST discards approximately half of the remaining keys.\n");
    printf("   - Therefore, BST search requires at most %d comparisons.\n\n", height + 1);

    printf("2. Comparison with Linear Search:\n");
    printf("   - For key 25: BST required 4 comparisons vs 8 in Linear Search (50%% reduction).\n");
    printf("   - For key 55: BST required 4 comparisons vs 9 in Linear Search (55.5%% reduction).\n");
    printf("   - For key 90 (Not Found): BST detected absence in 3 comparisons vs 9 in Linear Search (66.7%% reduction).\n\n");

    printf("3. Conclusion:\n");
    printf("   - BST Search is significantly superior to Linear Search for this dataset and\n");
    printf("     for online bookstore catalogs where searches are frequent.\n\n");

    // Clean up memory
    freeBST(root);

    printf("=========================================================================\n");
    printf("Execution Completed Successfully.\n");
    printf("=========================================================================\n");

    return 0;
}
