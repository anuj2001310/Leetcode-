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
typedef pair<int, int> pii;
#define MAX numeric_limits<ll>::max()
typedef long long ll;

class Solution {
public:
    int minimumLevel(TreeNode* root) {
        int ans = 0;
        ll sum = MAX;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int n = q.size();
            ll currSum = 0;

            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                currSum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (currSum < sum) {
                sum = currSum;
                ans = level;
            }
            level++;
        }

        return ans;
    }
};