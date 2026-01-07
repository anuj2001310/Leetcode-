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
    long long ans = 0;
    long long mod = 1e9 + 7;
    long long totalsum = 0;

    void totsum(TreeNode* root) {
        if (!root)
            return;

        totalsum += root->val;
        if (root->left)
            totsum(root->left);
        if (root->right)
            totsum(root->right);
    }

    long long help(TreeNode* root) {
        // base case
        if (!root)
            return 0;

        long long sum = 0;
        sum += root->val + help(root->left) + help(root->right);

        ans = max(ans, sum * (totalsum - sum));

        return sum;
    }

    int maxProduct(TreeNode* root) {
        totsum(root);
        help(root);

        return ans % mod;
    }
};