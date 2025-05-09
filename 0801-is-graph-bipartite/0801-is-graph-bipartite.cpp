class Solution {
    using vi = vector<int>;

private:
    bool check(int node, vector<vi>& adj, vi& color) {
        queue<int> q;
        q.push(node);

        color[node] = 0;
        while (!q.empty()) {
            auto parent = q.front();
            q.pop();
            for (auto& son : adj[parent]) {
                if (color[son] == -1) {
                    color[son] = 1 - color[parent];
                    q.push(son);
                } else if (color[son] == color[parent])
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vi color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1)
                if (!(check(i, graph, color)))
                    return false;
        }
        return true;
    }
};