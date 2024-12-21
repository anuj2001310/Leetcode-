class Solution {
    int ans = 0;

private:
    long long int helper(int node, vector<int>& values, unordered_map<int, list<int>>& adj, vector<bool>& vis, int k) {
        if (vis[node])
            return 0;
        vis[node] = true;
        long long int sum = values[node];
        for (auto& neigh : adj[node])
            sum += helper(neigh, values, adj, vis, k);

        if (sum % k == 0) {
            ans++;
            return 0;
        }
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,  vector<int>& values, int k) {
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            // extract - edges from tree
            int u = edges[i][0];
            int v = edges[i][1];

            // create - adj list
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        helper(0, values, adj, vis, k);
        return ans;
    }
};