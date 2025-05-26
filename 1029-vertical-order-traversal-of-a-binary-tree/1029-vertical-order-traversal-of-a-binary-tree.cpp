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

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<pair<pii, TreeNode*>> q;
        q.push({{0, 0}, root});    // {{vertical_distance, level}, Node};
        map<int, vector<pii>> map; // [dis] -> {level, val}

        while (!q.empty()) {
            int n = q.size();
            auto dis = q.front().first.first;
            auto level = q.front().first.second;
            auto node = q.front().second;
            q.pop();

            map[dis].push_back({level, node->val});

            if (node->left)
                q.push({{dis - 1, level + 1}, node->left});
            if (node->right)
                q.push({{dis + 1, level + 1}, node->right});
        }

        for (auto it = map.begin(); it != map.end(); it++) {

            sort(it->second.begin(), it->second.end(), [&](const pii& a, const pii& b) {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first < b.first;
            });

            vector<int> temp;
            // sort(it->second.begin(), it->second.end());
            //cout << it->first << " -> ";
            for (auto& pr : it->second) {
                temp.push_back(pr.second);
                //cout << "[" << pr.second << ", " << pr.first << "], ";
            }
            //cout << endl;

            ans.push_back(temp);
        }

        return ans;
    }
};