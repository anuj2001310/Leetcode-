public class Solution {
    public int Find(int[] dsu, int v) {
        if (dsu[v] == -1)
            return v;
        return dsu[v] = Find(dsu, dsu[v]);
    }

    public int[] FindRedundantConnection(int[][] edges) {
        int n = edges.Length;
        int[] dsu = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            dsu[i] = -1;
        }

        foreach (var edge in edges) {
            int parent_x = Find(dsu, edge[0]);
            int parent_y = Find(dsu, edge[1]);
            
            if (parent_x == parent_y) {
                return edge; // Found the redundant edge
            } else {
                dsu[parent_x] = parent_y; // Union operation
            }
        }

        return new int[] { 0, 0 }; // Fallback case (though not needed in valid inputs)
    }
}
