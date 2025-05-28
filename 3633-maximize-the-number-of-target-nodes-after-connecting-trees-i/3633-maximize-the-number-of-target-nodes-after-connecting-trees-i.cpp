class Solution {
    using vi = vector<int>;
    using vvi = vector<vector<int>>;

private:
    void adjList(vvi& adj, vvi& edges) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return;
    }

    int getNodes(vvi& graph, int dist, int node, int p) {
        int ans = 1;
        if (dist > 0) {
            for (int i : graph[node]) {
                if (i == p)
                    continue;
                ans += getNodes(graph, dist - 1, i, node);
            }
        }
        return ans;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vvi adj1(n);
        vvi adj2(m);

        adjList(adj1, edges1);
        adjList(adj2, edges2);

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
            ans[i] = getNodes(adj1, k, i, -1);

        int maxx = 0;
        for (int i = 0; i < m and k; i++)
            maxx = fmax(maxx, getNodes(adj2, k - 1, i, -1));

        for (int i = 0; i < n; i++)
            ans[i] += maxx;

        return ans;
    }
};