public class Solution  {
    public int CountCompleteComponents(int n, int[][] edges) {
        List<int>[] adj = new List<int>[n];
        for (int i = 0; i < n; i++)
            adj[i] = new List<int>();

        foreach (int[] edge in edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].Add(v);
            adj[v].Add(u);  
        }

        int count = 0;
        bool[] visited = new bool[n];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                List<int> component = new List<int>();
                Queue<int> queue = new Queue<int>();
                
                queue.Enqueue(i);
                visited[i] = true;

                while (queue.Count > 0) {
                    int node = queue.Dequeue();
                    component.Add(node);

                    foreach (int neighbor in adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            queue.Enqueue(neighbor);
                        }
                    }
                }

                bool flag = true;
                foreach (int node in component) {
                    if (adj[node].Count != component.Count - 1) {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                    count++;
            }
        }

        return count;
    }
}