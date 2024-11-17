public class Solution {
    public int[] FindMissingAndRepeatedValues(int[][] grid) {
        int[] ans = new int[2];
        int n = grid.Length;
        int reqSize = n * n + 1;
        int[] square = new int[reqSize];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                square[grid[i][j]]++;
        }

        for (int i = 0; i < reqSize; ++i) {
            if (square[i] == 2)
                ans[0] = i;
            if (square[i] == 0)
                ans[1] = i;
        }

        return ans;
    }
}