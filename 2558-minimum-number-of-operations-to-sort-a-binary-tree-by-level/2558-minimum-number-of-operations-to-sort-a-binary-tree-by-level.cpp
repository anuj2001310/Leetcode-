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
    int minimumOperations(TreeNode* root) {
        int cnt = 0;

        auto minSwaps = [&](vector<int>& ans) -> int {
            if (ans.size() == 1)
                return 0;
            vector<int> temp = ans;
            sort(temp.begin(), temp.end());
            unordered_map<int, int> map;
            for (int i = 0; i < ans.size(); i++)
                map[ans[i]] = i;

            int cnt = 0;
            for (int i = 0; i < ans.size(); ++i) {
                if (ans[i] != temp[i]) {
                    int x = ans[i];
                    int idx = map[temp[i]];
                    ans[i] = temp[i];
                    ans[idx] = x;
                    map[ans[i]] = i;
                    map[x] = idx;
                    ++cnt;
                }
            }
            return cnt;
        };

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> ans;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();
                ans.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            cnt += minSwaps(ans);
        }

        return cnt;
    }
};