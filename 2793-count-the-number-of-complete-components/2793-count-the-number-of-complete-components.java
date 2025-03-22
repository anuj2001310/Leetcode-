class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        for (int i = 0; i <= n; ++i)
            map.put(i, new ArrayList<Integer>());

        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            map.get(u).add(v);
            map.get(v).add(u);
        }
        // System.out.println(map);
        boolean[] vis = new boolean[n];
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                List<Integer> arr = new ArrayList<>();
                Queue<Integer> q = new ArrayDeque<>();

                q.offer(i);
                vis[i] = true;

                while (!q.isEmpty()) {
                    int node = q.poll();
                    arr.add(node);

                    for (Integer neigh : map.get(node)) {
                        if (!vis[neigh]) {
                            vis[neigh] = true;
                            q.offer(neigh);
                        }
                    }
                }
                boolean flag = true;
                for (Integer ele : arr) {
                    if (map.get(ele).size() != arr.size() - 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    c++;
            }
        }
        return c;
    }
}