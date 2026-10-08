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
typedef vector<int> vi;
using vvi = vector<vi>;
using pii = pair<int, int>;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vvi ans;
        if (!root)
            return ans;

        map<int, map<int, multiset<int>>> adj; // {dis, {level, {list}}}
        queue<pair<TreeNode*, pii>> q;         // {root, {dis, level}}

        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto node = q.front().first;
            auto dis = q.front().second.first;
            auto lev = q.front().second.second;
            q.pop();

            adj[dis][lev].insert(node->val);

            if (node->left)
                q.push({node->left, {dis - 1, lev + 1}});
            if (node->right)
                q.push({node->right, {dis + 1, lev + 1}});
        }

        for (auto& [k, v] : adj) {
            vi temp;
            for (auto& [kk, vv] : v) {
                for (auto it = vv.begin(); it != vv.end(); it++)
                    temp.push_back(*it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};