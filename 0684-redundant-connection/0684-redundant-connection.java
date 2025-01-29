class Solution {
    static int find (int[] dsu, int v) {
        if (dsu[v] == -1)
            return v;
        return dsu[v] = find (dsu, dsu[v]);
    }
    
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] dsu = new int[n + 1];
        Arrays.fill(dsu, -1);

        for (int[] edge : edges) {
            int parent_x = find (dsu, edge[0]);
            int parent_y = find (dsu, edge[1]);
            if (parent_x == parent_y)
                return edge;
            else
                dsu[parent_x] = parent_y;
        }
        return new int[] {0, 0};
    }
}