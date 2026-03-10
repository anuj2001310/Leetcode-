class Solution {
private:
    bool dfs(int node, int parent, unordered_map<int, list<int>>& adj,
             vector<bool>& vis) {
        vis[node] = true;

        for (auto& neigh : adj[node]) {
            if (!vis[neigh]) {
                if (dfs(neigh, node, adj, vis))
                    return true;

            } else if (neigh != parent)
                return true;
        }
        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (size(edges) != n - 1)
            return false;

        unordered_map<int, list<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++)
            if (!vis[i])
                if (dfs(i, -1, adj, vis))
                    return false;

        return true;
    }
};