#include <stdio.h>
#include <stdlib.h>

// Tree Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node in memory
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// INSERT FUNCTION (Recursive) - Time Complexity: O(log n) average
struct Node* insert(struct Node* root, int value) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the (unchanged) node pointer
    return root;
}

// INORDER TRAVERSAL (Left, Root, Right)
// This will print the BST elements in sorted ascending order
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d -> ", root->data);
        inorderTraversal(root->right);
    }
}

// MEMORY MANAGEMENT: Free all nodes to prevent memory leaks (Postorder traversal approach)
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;

    printf("--- Binary Search Tree (BST) Operations ---\n");
    
    // Inserting elements
    printf("Inserting elements: 50, 30, 20, 40, 70, 60, 80\n");
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the tree
    printf("\nInorder Traversal (Should be sorted): \n");
    inorderTraversal(root);
    printf("NULL\n");

    // Clean up memory
    freeTree(root);
    printf("\nMemory successfully freed.\n");

    return 0;
}
