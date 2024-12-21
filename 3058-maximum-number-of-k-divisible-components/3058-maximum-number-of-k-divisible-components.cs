using System;
using System.Collections.Generic;

public class Solution {
    private int ans = 0;

    private long Helper(int node, int[] values, List<int>[] adj, bool[] vis, int k) {
        if (vis[node])
            return 0;

        vis[node] = true;
        long sum = values[node];

        foreach (var neigh in adj[node]) {
            sum += Helper(neigh, values, adj, vis, k);
        }

        if (sum % k == 0) {
            ans++;
            return 0;
        }
        return sum;
    }

    public int MaxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        List<int>[] adj = new List<int>[n];
        for (int i = 0; i < n; i++)
            adj[i] = new List<int>();

        foreach (var edge in edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].Add(v);
            adj[v].Add(u);
        }

        bool[] vis = new bool[n];
        Helper(0, values, adj, vis, k);
        
        return ans;
    }
}
