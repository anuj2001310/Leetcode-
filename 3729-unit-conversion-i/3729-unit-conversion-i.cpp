class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        const int mod = 1e9 + 7;
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto& conversion : conversions) {
            int f = conversion[0];
            int t = conversion[1];
            int r = conversion[2];
            adj[f].push_back({t, r});
        }
        int n = conversions.size();
        vector<int> ans(n + 1, -1);
        ans[0] = 1;
        queue<int> q;
        q.push (0);
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            for (auto& neigh : adj[top]) {
                if (ans[neigh.first] == -1) {
                    ans[neigh.first] = (1LL * ans[top] * neigh.second) % mod;
                    q.push (neigh.first);
                }
            }
        }
        return ans;
    }
};