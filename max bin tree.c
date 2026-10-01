struct TreeNode* buildTree(int* nums, int left, int right) {
    if (left > right) return NULL;
    
    // Find the index of the maximum value in the current subarray range
    int maxIdx = left;
    for (int i = left + 1; i <= right; i++) {
        if (nums[i] > nums[maxIdx]) {
            maxIdx = i;
        }
    }
    
    // Allocate memory for the root node
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[maxIdx];
    
    // Recursively build left and right subtrees
    root->left = buildTree(nums, left, maxIdx - 1);
    root->right = buildTree(nums, maxIdx + 1, right);
    
    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    return buildTree(nums, 0, numsSize - 1);
}
