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
    int dfs (TreeNode* root, map<int, vector<int>>& map) {
        if (!root)
            return 0;
        
        int l = dfs(root->left, map) + 1;
        int r = dfs(root->right, map) + 1;
        int level = fmax(l, r);
        map[level].push_back(root->val);

        return level;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root)
            return {};
        
        map<int, vector<int>> map;
        vector<vector<int>> ans;

        dfs (root, map);
        for (auto& [k, v] : map) {
            /*cout<<k<<" -> { ";
            for (auto& c : v)
                cout<<c<<", ";
            cout<<" }"<<endl;*/
            ans.push_back(v);
        }

        return ans;
    }
};