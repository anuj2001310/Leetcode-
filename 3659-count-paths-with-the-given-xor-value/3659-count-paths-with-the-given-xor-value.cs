public class Solution {
    const int MOD = 1000000007;
    const int MAX_XOR_VALUE = 16;

    public int Solve(int[][] grid, int i, int j, int val, int k, List<List<List<int>>> dp) {
        if (i == 0 && j == 0)
            return (val ^ grid[0][0]) == k ? 1 : 0;

        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j][val] != -1)
            return dp[i][j][val];


        int up = Solve(grid, i - 1, j, val ^ grid[i][j], k, dp);  
        int left = Solve(grid, i, j - 1, val ^ grid[i][j], k, dp);  

        return dp[i][j][val] = (up + left) % MOD;
    }

    public int CountPathsWithXorValue(int[][] grid, int k) {
        int n = grid.Length;
        int m = grid[0].Length;

        List<List<List<int>>> dp = new List<List<List<int>>>();
        for (int i = 0; i < n; i++) {
            List<List<int>> row = new List<List<int>>();
            for (int j = 0; j < m; j++) {
                List<int> valList = new List<int>(new int[MAX_XOR_VALUE]);
                for (int l = 0; l < MAX_XOR_VALUE; l++) {
                    valList[l] = -1;
                }
                row.Add(valList);
            }
            dp.Add(row);
        }

        int ans = Solve(grid, n - 1, m - 1, 0, k, dp);

        return ans % MOD;
    }
}