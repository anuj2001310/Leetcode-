class Solution {
    int cnt = 0;

    void dfs(vector<vector<pair<int, int>>>& adj, int node, int parent) {
        for (auto& i : adj[node]) {
            if (i.first != parent) {
                cnt += i.second;
                dfs(adj, i.first, node);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[v].push_back({u, 0});
            adj[u].push_back({v, 1});
        }
        dfs(adj, 0, -1);
        return cnt;
    }
};