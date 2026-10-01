int getH(struct TreeNode* r) { return r ? (getH(r->left) > getH(r->right) ? getH(r->left) : getH(r->right)) + 1 : -1; }

void fill(struct TreeNode* r, char*** mat, int row, int col, int h) {
    sprintf(mat[row][col] = malloc(12), "%d", r->val);
    // Only recurse and shift if the child exists, preventing (1 << -1)
    if (r->left)  fill(r->left,  mat, row + 1, col - (1 << (h - row - 1)), h);
    if (r->right) fill(r->right, mat, row + 1, col + (1 << (h - row - 1)), h);
}

char*** printTree(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int h = getH(root), m = h + 1, n = (1 << m) - 1;
    *returnSize = m; *returnColumnSizes = malloc(m * sizeof(int));
    char*** res = malloc(m * sizeof(char**));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n; res[i] = malloc(n * sizeof(char*));
        for (int j = 0; j < n; j++) res[i][j] = calloc(1, 1);
    }
    if (root) fill(root, res, 0, (n - 1) / 2, h); // Added null check for safety
    return res;
}
