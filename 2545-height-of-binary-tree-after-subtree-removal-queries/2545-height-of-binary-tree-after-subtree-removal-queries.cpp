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
    int dfn[100010];
    int sze[100010];
    int height[100010];
    int cnt = 1;

    void dfs(TreeNode* cur, int h) {
        dfn[cur->val] = cnt++;
        height[dfn[cur->val]] = h;
        sze[cur->val] = 1;
        if (cur->left)
            dfs(cur->left, h + 1), sze[cur->val] += sze[cur->left->val];
        if (cur->right)
            dfs(cur->right, h + 1), sze[cur->val] += sze[cur->right->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        memset(height, 0, sizeof(height));
        dfs(root, 0);
        int lmax[100010];
        int rmax[100010];
        lmax[0] = rmax[cnt + 1] = 0;
        for (int i = 1; i <= cnt; i++)
            lmax[i] = max(lmax[i - 1], height[i]),
            rmax[cnt - i + 1] = max(rmax[cnt - i + 2], height[cnt - i + 1]);

        vector<int> ans;

        for (int q : queries) {
            int l = dfn[q], r = dfn[q] + sze[q];
            ans.push_back(max(lmax[l - 1], rmax[r]));
        }
        return ans;
    }
};