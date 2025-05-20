class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int n = mat.length, m = mat[0].length;

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0])
                return a[1] - b[1];
            return a[0] - b[0];
        }); // {sum, i} -> minimized sum first;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++)
                sum += mat[i][j];
            pq.offer(new int[] { sum, i });
        }

        int[] ans = new int[k];
        int idx = 0;
        
        while (k-- != 0 && !pq.isEmpty()) {
            int top = pq.peek()[1];
            pq.poll();
            ans[idx++] = top;
        }
        return ans;
    }
}