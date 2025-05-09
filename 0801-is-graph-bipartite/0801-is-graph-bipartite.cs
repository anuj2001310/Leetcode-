public class Solution {
    public bool IsBipartite(int[][] graph) {
        var n = graph.Length;
        var color = new int[n];
        Array.Fill(color, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!(bfs(i, graph, color)))
                    return false;
            }
        }
        return true;
    }
    
    private bool bfs(int node, int[][] adj, int[] color) {
        var q = new Queue<int>();
        q.Enqueue(node);
        color[node] = 0;

        while (q.Count != 0) {
            int parent = q.Dequeue();
            foreach (var son in adj[parent]) {
                if (color[son] == -1) {
                    color[son] = 1 - color[parent];
                    q.Enqueue(son);
                }
                else if (color[son] == color[parent])
                    return false;
            } 
        }
        return true;
    }
}