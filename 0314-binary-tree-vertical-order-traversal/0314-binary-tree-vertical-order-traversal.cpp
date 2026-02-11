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
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root)  
            return {};
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                int dis = q.front().second;
                q.pop();

                m[dis].push_back(node->val);

                if (node->left)
                    q.push({node->left, dis - 1});
                
                if (node->right)
                    q.push({node->right, dis + 1});
            }
        }

        vector<vector<int>> ans;

        for (auto& [k, vec] : m)
            ans.push_back(vec);
        
        return ans;
    }
};