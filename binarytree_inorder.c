#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void traverse(struct TreeNode* root, int* arr, int* size) {
    if (!root) return;
    
    traverse(root->left, arr, size);   // Visit Left Subtree
    arr[(*size)++] = root->val;        // Visit Root Node
    traverse(root->right, arr, size);  // Visit Right Subtree
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Allocating space for 101 elements safely covers the nodes constraint (0 to 100)
    int* result = (int*)malloc(101 * sizeof(int));
    *returnSize = 0;
    
    traverse(root, result, returnSize);
    return result;
}

int main() {
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    int returnSize = 0;
    int* result = inorderTraversal(root, &returnSize);

    // Print the traversal results
    printf("Inorder Traversal Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(result);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}
