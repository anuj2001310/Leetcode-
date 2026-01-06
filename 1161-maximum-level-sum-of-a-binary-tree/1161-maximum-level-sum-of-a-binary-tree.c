/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
int maxLevelSum(struct TreeNode* root) {
    TreeNode* q[10001];
    int r = 0, f = 0;
    long long ans = LONG_MIN;
    int res = 0;
    int level = 1;
    if (!root)
        return ans;
    q[r++] = root;

    while (f < r) {
        int n = r - f;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            TreeNode* node = q[f++];
            sum += node->val;
            if (node->left)
                q[r++] = node->left;

            if (node->right)
                q[r++] = node->right;
        }
        if (sum > ans) {
            ans = sum;
            res = level;
        }
        level++;
    }
    return res;
}