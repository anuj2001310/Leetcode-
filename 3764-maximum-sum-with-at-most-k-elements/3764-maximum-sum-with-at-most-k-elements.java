class Solution {
    public long maxSum(int[][] grid, int[] limits, int k) {
        long ans = 0;
        int n = grid.length, m = grid[0].length;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);

        for (int i = 0; i < n; ++i) {
            Arrays.sort(grid[i]);
            for (int j = m - 1; j >= 0 && limits[i] > 0; j--) {
                pq.offer(grid[i][j]);
                limits[i]--;
            }
        }
        while (k-- > 0 && !pq.isEmpty())
            ans += pq.poll();
        
        return ans;
    }
}