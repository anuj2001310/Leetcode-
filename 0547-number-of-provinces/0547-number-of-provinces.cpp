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
    int findCircleNum(vector<vector<int>>& mat) {
        int cnt = 0;
        int n = mat.size();
        vector<bool> vis(n, false);
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 and i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};