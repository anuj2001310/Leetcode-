public class Solution {
    public long MaximumScore(int[][] grid) {
        int n = grid.Length;
        // Precompute the Neon Moss potential for each terrarium.
        long[][] moss = new long[n][];
        for (int j = 0; j < n; j++) {
            moss[j] = new long[n + 1];
            for (int i = 0; i < n; i++) {
                moss[j][i + 1] = moss[j][i] + grid[i][j];
            }
        }

        // dp[height][state]
        // State 0: RISING (h >= prevH). We add glow to the PREVIOUS column.
        // State 1: FALLING (h <= prevH). We add glow to the CURRENT column.
        // State 2: VALLEY FLOOR. We just finished falling and are waiting to rise.
        long[,] dp = new long[n + 1, 3];
        for (int h = 0; h <= n; h++) {
            dp[h, 0] = 0; // Everything starts at 0
            dp[h, 1] = dp[h, 2] = -1; 
        }

        for (int col = 1; col < n; col++) {
            long[,] next = new long[n + 1, 3];
            for (int h = 0; h <= n; h++) next[h, 0] = next[h, 1] = next[h, 2] = -1;

            // --- 1. RISING (h >= prevH) ---
            // We are building a wall. This activates moss in col-1.
            long bestRising = -1;
            for (int h = 0; h <= n; h++) {
                // We can rise from a previous Rising state or a Valley Floor.
                long prev = Math.Max(dp[h, 0], dp[h, 2]);
                if (prev != -1) bestRising = Math.Max(bestRising, prev - moss[col - 1][h]);
                if (bestRising != -1) next[h, 0] = bestRising + moss[col - 1][h];
            }

            // --- 2. FALLING (h <= prevH) ---
            // The wall in col-1 is taller than us. Our moss in "col" glows.
            long bestFalling = -1;
            for (int h = n; h >= 0; h--) {
                // We can start falling from ANY state (Peak, Slope, or Floor).
                long prev = Math.Max(dp[h, 0], Math.Max(dp[h, 1], dp[h, 2]));
                if (prev != -1) bestFalling = Math.Max(bestFalling, prev + moss[col][h]);
                if (bestFalling != -1) next[h, 1] = bestFalling - moss[col][h];
            }

            // --- 3. VALLEY FLOOR ---
            // We just finished a falling sequence. We don't add points to col-1
            // because those rows were already activated by col-2 when we were falling!
            long bestFloor = -1;
            for (int h = 0; h <= n; h++) {
                bestFloor = Math.Max(bestFloor, dp[h, 1]);
            }
            for (int h = 0; h <= n; h++) {
                next[h, 2] = bestFloor;
            }

            dp = next;
        }

        long ans = 0;
        for (int h = 0; h <= n; h++) {
            for (int s = 0; s < 3; s++) ans = Math.Max(ans, dp[h, s]);
        }
        return ans;
    }
}