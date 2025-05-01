class Solution {
    class Edge {
        int t;
        int r;
        Edge(int t, int r) {
            this.t = t;
            this.r = r;
        }
    }
    public int[] baseUnitConversions(int[][] conversions) {
        final int mod = 1_000_000_007;
        HashMap<Integer, List<Edge>> adj = new HashMap<>();
        for (int[] conversion : conversions) {
            int f = conversion[0];
            int t = conversion[1];
            int r = conversion[2];
            adj.computeIfAbsent(f, k -> new ArrayList<>()).add(new Edge(t, r));
        }
        int n = conversions.length;
        int[] ans = new int[n + 1];
        ans[0] = 1;
        
        Queue<Integer> q = new ArrayDeque<>();
        q.offer (0);
        while (!q.isEmpty()) {
            int top = q.poll();
            for (Edge eg : adj.getOrDefault(top, Collections.emptyList())) {
                if (ans[eg.t] == 0) {
                    ans[eg.t] = (int) (((long) ans[top] * eg.r) % mod);
                    q.offer (eg.t);
                }
            }
        }
        return ans;
        
    }
}