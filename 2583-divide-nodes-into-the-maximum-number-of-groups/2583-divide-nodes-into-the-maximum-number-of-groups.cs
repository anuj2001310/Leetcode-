public class Solution {
    public class DSU {
        int[] parent;

        public DSU(int n) {
            parent = new int[n];
            for (int i = 1; i < n; ++i)
                parent[i] = i;
        }

        public void Merge(int x, int y) {
            if (x > y)
                (x, y) = (y, x);
            parent[y] = x;
        }

        public int Find(int x) {
            if (parent[x] != x)
                parent[x] = Find(parent[x]);
            return parent[x];
        }
    }
    
    bool IsBipartite(DSU dsu, int n, Dictionary<int, List<int>> graph) {
        for (int i = 1; i <= n; ++i) {
            if (!graph.ContainsKey(i)) 
                continue;

            for (int j = 0; j < graph[i].Count; ++j) {
                if (dsu.Find(i) == dsu.Find(graph[i][0])) 
                    return false;

                dsu.Merge(dsu.Find(graph[i][0]), dsu.Find(graph[i][j]));
            }
        }
        return true;
    }

    public int MagnificentSets(int n, int[][] edges) {
        Dictionary<int, List<int>> graph = new();

        foreach (var edge in edges) {
            if (!graph.ContainsKey(edge[0]))
                graph[edge[0]] = new List<int>();
        
            if (!graph.ContainsKey(edge[1]))
                graph[edge[1]] = new List<int>();

            graph[edge[0]].Add(edge[1]);
            graph[edge[1]].Add(edge[0]);
        }

        DSU dsu = new(n + 1);
        if (!IsBipartite(dsu, n, graph))
            return -1;

        for (int j = 0; j < edges.Length; ++j)
            dsu.Merge(dsu.Find(edges[j][0]), dsu.Find(edges[j][1]));

        Dictionary<int, List<int>> components = new();

        for (int i = 1; i <= n; ++i) {
            int p = dsu.Find(i);

            if (!components.ContainsKey(p))
                components[p] = new List<int>();
            //Console.WriteLine(p);
            components[p].Add(i);
        }
        
        int ans = 0;
        
        foreach (var key in components.Keys) {
            int maxLevel = 0;
            foreach (var i in components[key]) {
                Span<bool> visit = stackalloc bool[n + 1];
                Queue<int> bfs = new();
                int levels = 0;
                bfs.Enqueue(i);
                visit[i] = true;

                while (bfs.Count > 0) {
                    var count = bfs.Count;
                    while (count-- > 0) {
                        var top = bfs.Dequeue();
                        if (!graph.ContainsKey(top)) 
                            continue;
                        foreach (var node in graph[top]) {
                            if (!visit[node]) {
                                visit[node] = true;
                                bfs.Enqueue(node);
                            }
                        }
                    }
                    levels++;
                }
                maxLevel = Math.Max(levels, maxLevel);
            }
            ans += maxLevel;
        }
        return ans;
    }
}