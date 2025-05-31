public class Solution {
    public IList<IList<int>> AllPathsSourceTarget(int[][] graph) {
        var ans = new List<IList<int>>();
        var path = new List<int>();
        int n = graph.Length;
        var vis = new bool[n];

        void dfs (int node) {
            vis[node] = true;
            path.Add(node);
            if (node == n - 1)
                ans.Add(new List<int>(path));
            
            foreach (var neigh in graph[node]) {
                if (!vis[neigh])
                    dfs (neigh);
            }

            vis[node] = false;
            path.RemoveAt(path.Count - 1);
        }

        dfs (0);

        return ans;
    }
}