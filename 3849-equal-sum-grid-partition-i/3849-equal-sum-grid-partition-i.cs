public class Solution {
    public bool CanPartitionGrid(int[][] grid) {
        int n = grid.Length, m = grid[0].Length;
        var rowSum = new long[n];
        var colSum = new long[m];
        long tot = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tot += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        if ((tot & 1) != 0)
            return false;
        
        long pref = 0L;

        for (int i = 0; i < n - 1; ++i) {
            pref += rowSum[i];
            if ((pref << 1) == tot)
                return true;
        }

        pref = 0L;
        for (int i = 0; i < m - 1; ++i) {
            pref += colSum[i];
            if ((pref << 1) == tot)
                return true;
        }
        
        return false;
    }
}