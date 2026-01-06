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
    int maxLevelSum(TreeNode* root) {
        int ans;
        int maxsum = INT_MIN;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            if (sum > maxsum) {
                ans = level;
                maxsum = max(sum, maxsum);
            }
            level++;
        }
        return ans;
    }
};