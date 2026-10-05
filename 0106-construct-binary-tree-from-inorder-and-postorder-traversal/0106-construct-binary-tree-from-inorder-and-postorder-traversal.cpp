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
    TreeNode* build(vector<int>& inorder, int is, int ie,
                    vector<int>& postorder, int ps, int pe,
                    unordered_map<int, int>& map) {
        if (ps > pe || is > ie)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inroot = map[postorder[pe]];
        int numsleft = inroot - is;

        root->left = build(inorder, is, inroot - 1, postorder, ps,
                           ps + numsleft - 1, map);
        root->right = build(inorder, inroot + 1, ie, postorder, ps + numsleft,
                            pe - 1, map);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // write your code here
        if (size(inorder) != size(postorder))
            return nullptr;
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;

        return build(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1, map);
    }
};
