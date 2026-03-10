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
    bool helper(int idx, int n, TreeNode* root, vector<int>& arr) {
        if (!root || root->val != arr[idx])
            return false;

        if (idx == n - 1)
            return root->left == nullptr && root->right == nullptr;
            
        if (arr[idx] != root->val)
            return false;

        return helper(idx + 1, n, root->left, arr) ||
               helper(idx + 1, n, root->right, arr);
    }

public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        int n = arr.size();
        return helper(0, n, root, arr);
    }
};