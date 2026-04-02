class Solution {
    public int maximumAmount(int[][] coins) {
        int n = coins.length;
        int m = coins[0].length;
        int[][][] dp = new int[n][m][3];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                for (int k = 0; k < 3; k++){
                    dp[i][j][k] = -1000000000;
                }
            }
        }
        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = Integer.max(0, coins[0][0]);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (j - 1 >= 0){
                    for (int k = 0; k < 3; k++) {
                        dp[i][j][k] = Integer.max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                    }
                    dp[i][j][1] = Integer.max(dp[i][j][1], dp[i][j - 1][0] + Integer.max(0, coins[i][j]));
                    dp[i][j][2] = Integer.max(dp[i][j][2], dp[i][j - 1][1] + Integer.max(0, coins[i][j]));
                }
                if (i - 1 >= 0){
                    for (int k = 0; k < 3; k++) {
                        dp[i][j][k] = Integer.max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                    }
                    dp[i][j][1] = Integer.max(dp[i][j][1], dp[i - 1][j][0] + Integer.max(0, coins[i][j]));
                    dp[i][j][2] = Integer.max(dp[i][j][2], dp[i - 1][j][1] + Integer.max(0, coins[i][j]));
                }
            }
        }

        return Integer.max(dp[n - 1][m - 1][0], Integer.max(dp[n - 1][m - 1][1], dp[n - 1][m - 1][2]));
    }
}