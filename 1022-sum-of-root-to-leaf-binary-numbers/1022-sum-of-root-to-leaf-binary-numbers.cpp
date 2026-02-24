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
    void trav(TreeNode* root, int* i, int* sum) {
        if (!root)
            return;
        *i = (*i << 1) | root->val;
        !root->left && !root->right ? *sum += *i : 0;
        trav(root->left, i, sum);
        trav(root->right, i, sum);

        *i = (*i >> 1);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        int num = 0, i = 0;
        trav(root, &i, &num);

        return num;
    }
};