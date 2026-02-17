public class Solution {
    private void dfs (int node, List<int>[] adj, bool[] vis) {
        vis[node] = true;

        foreach (var neigh in adj[node]) {
            if (!vis[neigh])
                dfs(neigh, adj, vis);
        }
    }
    public int CountComponents(int n, int[][] edges) {
        var vis = new bool[n];
        List<int>[] adj = new List<int>[n];

        for (var i = 0; i < n; ++i)
            adj[i] = new List<int>();
        
        foreach (var edge in edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].Add(v);
            adj[v].Add(u);
        }
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                cnt++;
                dfs (i, adj, vis);
            }
        }

        return cnt;
    }
}