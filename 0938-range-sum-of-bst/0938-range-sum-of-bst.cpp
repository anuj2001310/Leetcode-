/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    void dfs(TreeNode* root, int low, int high) {
        if (!root)
            return;

        if (root->val >= low && root->val <= high)
            sum += root->val;

        dfs(root->left, low, high);
        dfs(root->right, low, high);

        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)
            return 0;

        dfs(root, low, high);
        return sum;
    }
};