class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;
    int LOG;

    void dfs(int u, int parent,
             vector<vector<int>>& graph) {

        up[u][0] = parent;

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : graph[u]) {
            if (v == parent) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u, graph);
        }
    }

    int lca(int a, int b) {

        if (depth[a] < depth[b])
            swap(a, b);

        int diff = depth[a] - depth[b];

        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j))
                a = up[a][j];
        }

        if (a == b)
            return a;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        LOG = 20;

        vector<vector<int>> graph(n + 1);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);

        dfs(1, 1, graph);

        pow2.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto& q : queries) {

            int u = q[0];
            int v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int ancestor = lca(u, v);

            int dist =
                depth[u] +
                depth[v] -
                2 * depth[ancestor];

            ans.push_back(pow2[dist - 1]);
        }

        return ans;
    }
};