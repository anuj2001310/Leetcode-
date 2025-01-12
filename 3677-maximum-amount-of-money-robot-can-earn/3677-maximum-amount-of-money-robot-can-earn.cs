public class Solution {
    public int MaximumAmount(int[][] coins) {
        int n = coins.Length, m = coins[0].Length;
        var dp = new int[3][][];
        for (var i = 0; i < 3; i++) {
            dp[i] = new int[n][];
            for (var j = 0; j < n; j++) {
                dp[i][j] = new int[m];
                Array.Fill(dp[i][j], int.MinValue / 2);
            }
        }
        dp[0][0][0] = coins[0][0];
        dp[1][0][0] = 0;
        for (var i = 0; i < n; i++) {
            for (var j = 0; j < m; j++) {
                var v = coins[i][j];
                for (int k = 0; k < 3; k++) {
                    if (i > 0)
                        dp[k][i][j] = Math.Max(dp[k][i][j], dp[k][i - 1][j] + v);
                
                    if (j > 0)
                        dp[k][i][j] = Math.Max(dp[k][i][j], dp[k][i][j - 1] + v);
                }

                if (v < 0) {
                    for (int k = 1; k < 3; k++) {
                        if (i > 0)
                            dp[k][i][j] = Math.Max(dp[k][i][j], dp[k - 1][i - 1][j]);
                        
                        if (j > 0)
                            dp[k][i][j] = Math.Max(dp[k][i][j], dp[k - 1][i][j - 1]);
                    }
                }
            }
        }
        var ans = int.MinValue;
        for (var k = 0; k < 3; k++)
            ans = Math.Max(ans, dp[k][n - 1][m - 1]);
    
        return ans;
    }
}