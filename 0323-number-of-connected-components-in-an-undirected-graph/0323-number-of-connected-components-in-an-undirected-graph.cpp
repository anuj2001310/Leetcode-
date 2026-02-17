class Solution {
private:
    void dfs(int node, unordered_map<int, list<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        for (auto& neigh : adj[node]) {
            if (!vis[neigh])
                dfs(neigh, adj, vis);
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt;
    }
};