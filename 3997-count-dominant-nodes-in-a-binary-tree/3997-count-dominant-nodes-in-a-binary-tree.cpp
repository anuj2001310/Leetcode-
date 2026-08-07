/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int cnt = 0;
    int postOrder(TreeNode* root) {
        if(!root)
            return INT_MIN;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        int mx = max({root->val, left, right});
        if (mx == root->val)
            cnt++;
        
        return mx;
    }
public:
    int countDominantNodes(TreeNode* root) {
        postOrder(root);
        return cnt;
    }
};