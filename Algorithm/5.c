#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to convert sorted array to height-balanced BST
struct TreeNode* sortedArrayToBST(int* nums, int left, int right) {
    if (left > right) return NULL;  // Base case

    int mid = left + (right - left) / 2;  // Middle element
    struct TreeNode* root = createNode(nums[mid]);  // Create root node

    // Recursively build left and right subtrees
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);

    return root;
}

// Wrapper function to start conversion
struct TreeNode* sortedArrayToBSTWrapper(int* nums, int numsSize) {
    return sortedArrayToBST(nums, 0, numsSize - 1);
}

// Function to print the tree in in-order traversal (for verification)
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

// Example usage
int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int size = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode* root = sortedArrayToBSTWrapper(nums, size);

    printf("Inorder Traversal of BST: ");
    inorderTraversal(root);  // Expected output: -10 -3 0 5 9
    printf("\n");

    return 0;
}
