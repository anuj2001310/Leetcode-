class Solution {
    int res = 0;

    private long helper(int node, int[] values, ArrayList<ArrayList<Integer>> adj, boolean[] vis, int k) {
        if (vis[node])
            return 0;
        vis[node] = true;
        long sum = values[node];
        for (Integer neigh : adj.get(node))
            sum += helper(neigh, values, adj, vis, k);

        if (sum % k == 0) {
            res++;
            return 0;
        }
        return sum;
    }

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        int m = edges.length;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= m; ++i)
            adj.add(new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        boolean[] vis = new boolean[n];
        helper(0, values, adj, vis, k);
        return res;
    }
}