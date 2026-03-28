#include <bits/stdc++.h>
using namespace std;

using li = list<int>;
using vi = vector<int>;
using pii = pair<int, int>;

#define Rep(a, b, c, d) for (int a = b; a < c; a += d)

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        // Code here
        vector<vi> adj(n);
        vi indegree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            indegree[u]++;
            adj[v].push_back(u);
        }

        vi ans;
        queue<int> q;
        int cnt = 0;

        Rep(i, 0, n, 1) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            cnt++;
            ans.push_back(node);

            for (auto& neigh : adj[node]) {
                if (--indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        if (cnt == n)
            return ans;
            
        return {};

        // return (cnt != n) ? {} : ans;
    }
};
