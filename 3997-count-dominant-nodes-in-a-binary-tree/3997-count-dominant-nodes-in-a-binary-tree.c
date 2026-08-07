/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
int countDominantNodes(struct TreeNode* root) {
    int cnt = 0;
    int postOrder(TreeNode * root) {
        if (!root)
            return -1;

        int left = postOrder(root->left);
        int right = postOrder(root->right);

        int m = fmax(root->val, fmax(left, right));
        if (root->val == m)
            cnt++;

        return m;
    }
    postOrder(root);
    return cnt;
}