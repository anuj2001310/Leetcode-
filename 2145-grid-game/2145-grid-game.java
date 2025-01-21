class Solution {
    public long gridGame(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length; 
        long res = Long.MAX_VALUE;
        long top_sum = 0;
        for (int i = 0; i < grid[0].length; i++)
            top_sum += grid[0][i];
        long bottom_sum = 0;
        for (int i = 0; i < m; ++i) {
            top_sum -= grid[0][i];
            res = Math.min(res, Math.max(top_sum, bottom_sum));
            bottom_sum += grid[1][i];
        }
        return res;
    }
}