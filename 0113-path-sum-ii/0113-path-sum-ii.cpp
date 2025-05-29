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
    using pii = pair<int, int>;
    using vi = vector<int>;

private:
    void func(TreeNode* root, vector<vi>& ans, vi& path, int sum, int target) {
        if (!root)
            return;

        path.push_back(root->val);
        sum += root->val;
        if (!root->left and !root->right and sum == target)
            ans.push_back(path);

        func(root->left, ans, path, sum, target);
        func(root->right, ans, path, sum, target);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vi> ans;
        vi path;
        func(root, ans, path, 0, targetSum);
        return ans;
    }
};