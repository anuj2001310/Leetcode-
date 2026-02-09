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
    void inorder(TreeNode* root, vector<TreeNode*>& tree, int& size) {
        if (!root)
            return;
        // LNR
        inorder(root->left, tree, size);
        size++;
        tree.emplace_back(root);
        inorder(root->right, tree, size);
        return;
    }
    TreeNode* convertToBST(vector<TreeNode*>& tree, int start, int end) {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = tree[mid];
        root->left = convertToBST(tree, start, mid - 1);
        root->right = convertToBST(tree, mid + 1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> tree;
        int size = 0;
        inorder(root, tree, size);
        return convertToBST(tree, 0, size - 1);
    }
};