public class Solution {
    public long MostPoints(int[][] questions) {
        int n = questions.Length;
        var dp = new long[n + 1];
        Array.Fill(dp, -1);

        long function(int idx) {
            if (idx >= n)
                return 0;
            if (dp[idx] != -1)
                return dp[idx];
            
            long take = questions[idx][0];
            int nidx = idx + questions[idx][1] + 1;
            if (nidx < n)
                take += function (nidx);
            long skip = function (idx + 1);

            return dp[idx] = Math.Max(take, skip);
        }
        return function(0);
    }
}