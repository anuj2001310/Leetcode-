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
    pair<bool, int> balanced(TreeNode* root) {
        if (!root)
            return {true, 0};

        auto left = balanced(root->left);
        auto right = balanced(root->right);

        bool balance = left.first && right.first && abs(left.second - right.second) <= 1;
        int height = 1 + max(left.second, right.second);

        return {balance, height};
    }

public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        return balanced(root).first;
    }
};