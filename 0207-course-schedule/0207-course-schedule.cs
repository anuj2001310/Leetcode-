public class Solution {
    public bool CanFinish(int numCourses, int[][] prerequisites) {
        int V = numCourses;
        List<int>[] adj = new List<int>[V];
        for (int i = 0; i < V; i++)
            adj[i] = new List<int>();

        var indegree = new int[V];

        foreach (int[] pre in prerequisites) {
            int u = pre[0], v = pre[1];
            adj[u].Add(v);
            indegree[v]++;
        }

        var q = new Queue<int>();
        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.Enqueue(i);
        }

        while (q.Count > 0) {
            int node = q.Dequeue();
            cnt++;
            foreach (int neigh in adj[node]) {
                if (--indegree[neigh] == 0)
                    q.Enqueue(neigh);
            }
        }

        return cnt == V;
    }
}