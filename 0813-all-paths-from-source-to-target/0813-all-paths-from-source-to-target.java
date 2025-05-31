class Solution {
    private void dfs(int node, int[][] adj, boolean[] vis, List<Integer> path, List<List<Integer>> ans) {
        vis[node] = true;
        path.add(node);

        if (node == adj.length - 1)
            ans.add(new ArrayList<>(path));

        for (int neigh : adj[node]) {
            if (!vis[neigh])
                dfs(neigh, adj, vis, path, ans);
        }
        vis[node] = false;
        path.remove(path.size() - 1);
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] adj) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = adj.length;
        var vis = new boolean[n];
        dfs(0, adj, vis, new ArrayList<Integer>(), ans);
        return ans;
    }
}