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
private:
    void reverse(TreeNode* left, TreeNode* right, int curr) {
        if (!left or !right)
            return;
        if (curr & 1) {
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }
        reverse(left->left, right->right, curr + 1);
        reverse(left->right, right->left, curr + 1);
        return;
    }

public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left, root->right, 1);
        return root;
    }
};