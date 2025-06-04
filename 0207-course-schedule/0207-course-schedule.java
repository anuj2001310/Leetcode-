class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int V = numCourses;
        List<Integer>[] adj = new ArrayList[V];
        for (int i = 0; i < V; i++)
            adj[i] = new ArrayList<>();

        var indegree = new int[V];

        for (int[] pre : prerequisites) {
            int u = pre[0], v = pre[1];
            adj[u].add(v);
            indegree[v]++;
        }

        Queue<Integer> q = new ArrayDeque<>();
        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.offer(i);
        }

        while (!q.isEmpty()) {
            int node = q.poll();
            cnt++;
            for (Integer neigh : adj[node]) {
                if (--indegree[neigh] == 0)
                    q.offer(neigh);
            }
        }

        return cnt == V;
    }
}