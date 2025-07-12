class Solution {
private:
    void dfs (auto node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        for (auto& neigh : adj[node]) {
            if (!vis[neigh])
                dfs (neigh, adj, vis);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        
        int cnt = 0;
        /*
        for (auto& [u, v] : adj) {
            cout << u << " -> ";
            for (auto& k : v)
                cout << k << ", ";
            cout << endl;
        }*/
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, rooms, vis);
            }
        }
        return cnt == 1;
    }
};