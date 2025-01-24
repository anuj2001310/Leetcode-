class Solution {
    boolean[] isSafe;
    int[] visited;

    public boolean dfs(int node, int[][] graph) {
        visited[node] = 2;
        boolean isPossible = true;
        for (int child : graph[node]) {
            if (visited[child] == 0)
                dfs(child, graph);
            
            if (visited[child] == 2)
                return false;
            
        }
        visited[node] = 1;
        return true;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        isSafe = new boolean[n];
        visited = new int[n];
        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0)
                dfs(i, graph);
            
            if (visited[i] == 1)
                ans.add(i);
        }
        return ans;
    }
}