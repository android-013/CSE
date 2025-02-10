#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to perform preorder traversal (Recursive)
void preorderRecursive(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);       // Print root
    preorderRecursive(root->left);  // Visit left subtree
    preorderRecursive(root->right); // Visit right subtree
}

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Example usage
int main() {
    // Creating tree: 
    //       1
    //        \
    //         2
    //        /
    //       3
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    printf("Recursive Preorder Traversal: ");
    preorderRecursive(root);  // Expected Output: 1 2 3
    printf("\n");

    return 0;
}
