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
private:
    void dfs (TreeNode* root, vector<int>& ans) {
        if (!root)
            return ;
        if (root->left && !root->right)
            ans.push_back(root->left->val);
        if (root->right && !root->left)
            ans.push_back(root->right->val);

        dfs (root->left, ans);
        dfs (root->right, ans);

        return ;
    }
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        if (!root)
            return {};
        
        vector<int> ans;
        dfs (root, ans);

        return ans;
    }
};