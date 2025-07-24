class Solution {
    int timer = 0;

    void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& a,
             vector<int>& x, vector<int>& start, vector<int>& end) {
        start[u] = timer++;
        x[u] = a[u];
        for (auto& v : adj[u]) {
            if (v == p)
                continue;
            dfs(v, u, adj, a, x, start, end);
            x[u] = x[u] ^ x[v];
        }
        end[u] = timer++;
    }

    bool is_descendant(int u, int v, vector<int>& start, vector<int>& end) {
        return start[u] < start[v] && end[v] < end[u];
    }

public:
    int minimumScore(vector<int>& a, vector<vector<int>>& edges) {
        int n = a.size();
        vector<vector<int>> adj(n);
        vector<int> x(n);
        vector<int> start(n), end(n);
        for (auto& x : edges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, adj, a, x, start, end);
        int total = x[0];
        int ans = INT_MAX;

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = 0, b = 0, c = 0;

                // Case A: j is a descendant of i (nested cut)
                if (is_descendant(i, j, start, end)) {
                    a = x[j];
                    b = x[i] ^ x[j];
                    c = total ^ x[i];
                }
                // Case B: i is a descendant of j (nested cut)
                else if (is_descendant(j, i, start, end)) {
                    a = x[i];
                    b = x[j] ^ x[i];
                    c = total ^ x[j];
                }
                // Case C: i and j are in different branches (disjoint cuts)
                else {
                    a = x[i];
                    b = x[j];
                    c = total ^ x[i] ^ x[j];
                }

                int cur = max({a, b, c}) - min({a, b, c});

                ans = min(ans, cur);
            }
        }
        return ans;
    }
};