public class Solution {
    public int FindCircleNum(int[][] isConnected) {
        int V = isConnected.Length;
        var pro = 0;
        bool[] vis = new bool[V];
        void dfs (int node) {
            vis[node] = true;
            for (var j = 0; j < V; ++j) {
                if (isConnected[node][j] == 1 && !vis[j])
                    dfs (j);
            }
        }

        for (var i = 0; i < V; ++i) {
            if (!vis[i]) {
                dfs (i);
                pro++;
            }
        }
        return pro;
    }
}