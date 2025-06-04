class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preque) {
        int V = numCourses;
        vector<vector<int>> adj(V);

        for (auto& pr : preque) {
            int u = pr[0], v = pr[1];
            adj[u].push_back(v);
        }

        vector<int> indegree(V, 0);
        for (auto& it : adj) {
            for (auto v : it)
                indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int cnt = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            cnt++;
            for (auto& neigh : adj[node]) {
                if (--indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        return cnt == V;
    }
};