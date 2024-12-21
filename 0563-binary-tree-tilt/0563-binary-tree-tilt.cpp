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
    int sumOfNodes(TreeNode* root) {
        if (!root)
            return 0;
        return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
    }
    void change(TreeNode* root) {
        if (!root)
            return;
        root->val = abs(sumOfNodes(root->left) - sumOfNodes(root->right));
        change(root->left);
        change(root->right);
        return;
    }

public:
    int findTilt(TreeNode* root) {
        change(root);
        
        return sumOfNodes(root);
    }
};