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
    int sum = 0;
private:
    void dfs (TreeNode* root, int t) {
        if (!root) 
            return ;
        
        t = (t * 10 + root->val);
        if (!root->left && !root->right) {
            sum += t;
            return;
        }
        dfs (root->left, t);
        dfs (root->right, t);
    }
public:
    int sumNumbers(TreeNode* root) {
        dfs (root, 0);
        return sum;
    }
};