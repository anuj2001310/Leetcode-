class Solution {
    void dfs(int node, HashMap<Integer, ArrayList<Integer>> map, boolean[] vis) {
        vis[node] = true;
        for (Integer neigh : map.get(node)) {
            if (!vis[neigh])
                dfs(neigh, map, vis);
        }
    }

    public int findCircleNum(int[][] mat) {
        int n = mat.length;
        boolean[] vis = new boolean[n];
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        for (int i = 0; i <= n; ++i)
            map.put(i, new ArrayList<>());

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && i != j) {
                    map.get(i).add(j);
                    map.get(j).add(i);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                cnt++;
                dfs(i, map, vis);
            }
        }
        return cnt;
    }
}