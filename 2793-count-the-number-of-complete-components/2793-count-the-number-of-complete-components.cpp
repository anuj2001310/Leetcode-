class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                queue<int> q;

                q.push(i);
                vis[i] = true;

                while (!q.empty()) {
                    auto node = q.front();
                    q.pop();
                    comp.push_back(node);

                    for (auto& neigh : adj[node]) {
                        if (!vis[neigh]) {
                            vis[neigh] = true;
                            q.push(neigh);
                        }
                    }
                }
                bool flag = true;
                for (auto& ele : comp) {
                    if (adj[ele].size() != comp.size() - 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    cnt++;
            }
        }
        return cnt;
    }
};