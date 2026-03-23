/*
Title: 1594. Maximum Non Negative Product in a Matrix
Solution:
Difficulty: Medium
Approach: Dynamic Programming with Min/Max Tracking
Tags: Array, Dynamic Programming, Matrix
1) Use DP to track both maximum and minimum products at each cell (since negatives can become positive).
2) Initialize the first cell with the grid value.
3) Fill the first row by multiplying each cell with the previous max/min from left.
4) Fill the first column by multiplying each cell with the previous max/min from above.
5) For remaining cells, consider paths from both up and left, calculating all possible products.
6) Store the maximum and minimum products at each position.
7) Return the maximum product at bottom-right cell modulo 10^9+7, or -1 if negative.

Time Complexity: O(m*n) where m = rows, n = columns
Space Complexity: O(m*n) for the DP table
Tip: Track both max and min products because multiplying two negative numbers yields a positive result. When current cell has a negative value, the previous minimum product might become the new maximum.
Similar Problems: 152. Maximum Product Subarray, 62. Unique Paths, 64. Minimum Path Sum, 931. Minimum Falling Path Sum
*/
public class Solution
{
    private const int MOD = 1000000007;                             // Modulo constant for final result

    public int MaxProductPath(int[][] grid)
    {
        int m = grid.Length;                                        // Number of rows in the grid
        int n = grid[0].Length;                                     // Number of columns in the grid

        // DP table storing (maxProduct, minProduct) till each cell
        (long max, long min)[,] dp = new (long, long)[m, n];        // Tuple array to track max and min products at each cell

        // Base case: starting cell
        dp[0, 0] = (grid[0][0], grid[0][0]);                        // Initialize first cell with its value as both max and min

        // Fill first row
        for (int j = 1; j < n; j++)                                 // Iterate through first row columns
        {
            long val = grid[0][j];                                  // Current cell value
            dp[0, j] = (                                            // Calculate products from left neighbor only
                dp[0, j - 1].max * val,                             // Max product path to current cell
                dp[0, j - 1].min * val                              // Min product path to current cell
            );
        }

        // Fill first column
        for (int i = 1; i < m; i++)                                 // Iterate through first column rows
        {
            long val = grid[i][0];                                  // Current cell value
            dp[i, 0] = (                                            // Calculate products from upper neighbor only
                dp[i - 1, 0].max * val,                             // Max product path to current cell
                dp[i - 1, 0].min * val                              // Min product path to current cell
            );
        }

        // Fill rest of the grid
        for (int i = 1; i < m; i++)                                 // Iterate through remaining rows
        {
            for (int j = 1; j < n; j++)                             // Iterate through remaining columns
            {
                long val = grid[i][j];                              // Current cell value

                long upMax = dp[i - 1, j].max;                      // Maximum product from cell above
                long upMin = dp[i - 1, j].min;                      // Minimum product from cell above

                long leftMax = dp[i, j - 1].max;                    // Maximum product from cell to the left
                long leftMin = dp[i, j - 1].min;                    // Minimum product from cell to the left

                // Compute all possible products
                long a = upMax * val;                               // Product from above using max path
                long b = upMin * val;                               // Product from above using min path (important for negatives)
                long c = leftMax * val;                             // Product from left using max path
                long d = leftMin * val;                             // Product from left using min path (important for negatives)

                dp[i, j] = (                                        // Store the overall max and min at this cell
                    Math.Max(Math.Max(a, b), Math.Max(c, d)),       // Maximum of all 4 possible products
                    Math.Min(Math.Min(a, b), Math.Min(c, d))        // Minimum of all 4 possible products
                );
            }
        }

        long result = dp[m - 1, n - 1].max;                         // Get maximum product at destination cell

        // If result is negative → return -1
        if (result < 0) return -1;                                  // Problem requires returning -1 for negative results

        return (int)(result % MOD);                                 // Return result modulo 10^9+7
    }
}