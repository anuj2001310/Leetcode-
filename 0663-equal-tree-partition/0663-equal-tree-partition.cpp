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
    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& map) {
        if (!root)
            return 0;
        
        int s = root->val + dfs(root->left, map) + dfs(root->right, map);
        return map[root] = s;
    }
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<TreeNode*, int> map;

        int tot = dfs(root, map);

        for (auto& [k, v] : map) {
            if (k != root && tot == 2 * v)
                return true;
        }
        return false;
    }
};