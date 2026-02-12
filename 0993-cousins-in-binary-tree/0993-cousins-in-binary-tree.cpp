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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, pair<int, int>> adj; // {node ->  [level, parent]}

        queue<pair<TreeNode*, pair<int, int>>> q; //{Node -> [level, parent]}

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto node = q.front().first;
            auto level = q.front().second.first;
            auto parent = q.front().second.second;

            q.pop();

            adj[node->val] = {level, parent};

            if (node->left)
                q.push({node->left, {level + 1, node->val}});
            if (node->right)
                q.push({node->right, {level + 1, node->val}});
        }

        auto parentOfA = adj.find(x) != nullptr ? adj[x].second : -1;
        auto parentOfB = adj.find(y) != nullptr ? adj[y].second : -1;

        auto levelOfA = adj.find(x) != nullptr ? adj[x].first : -1;
        auto levelOfB = adj.find(y) != nullptr ? adj[y].first : -1;

        return (levelOfA == levelOfB) && (parentOfA != parentOfB);
    }
};