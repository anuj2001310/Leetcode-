class Solution {
    using vvi = vector<vector<int>>;
private:
// {true, true, false, true}

    void dfs (int node, vector<bool>& vis, vvi& adj) {
        vis[node] = true;
        for (auto& neigh : adj[node]) {
            if (!vis[neigh])
                dfs (neigh, vis, adj);
        }
    } 
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = size(rooms);
        vector<bool> vis(n, false);
        int cnt = 0;

        dfs (0, vis, rooms);

        for (int i = 0; i < n; i++) {
            cout<<vis[i]<<" ";
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }
        return true;
    }
};