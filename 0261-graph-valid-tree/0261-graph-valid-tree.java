import java.util.HashMap;

class Solution {

    private boolean dfs(int node, int parent, Map<Integer, List<Integer>> adj, boolean[] vis) {
        vis[node] = true;

        for (int neigh : adj.getOrDefault(node, new ArrayList<>())) {
            if (!vis[neigh]) {
                if (dfs(neigh, node, adj, vis))
                    return true;
            } 
            else if (neigh != parent) 
                return true;
        }

        return false;
    }

    public boolean validTree(int n, int[][] edges) {
        int m = edges.length;
        if (m != n - 1)
            return false;

        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        boolean[] vis = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis))
                    return false;
            }
        }

        return true;
    }
}