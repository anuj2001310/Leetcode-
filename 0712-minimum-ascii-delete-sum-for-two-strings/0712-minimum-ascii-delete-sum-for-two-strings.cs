public class Solution {
    public int MinimumDeleteSum(string s1, string s2) {
        var dp = new int[s1.Length + 1, s2.Length + 1];
        for (int i = 0; i < s1.Length; i++) {
            dp[i + 1, 0] = dp[i, 0] + s1[i];
        }

        for (int i = 0; i < s2.Length; i++) {
            dp[0, i + 1] = dp[0, i] + s2[i];
        }

         for (int i = 1; i < s1.Length + 1; i++) {
            for (int j = 1; j < s2.Length + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i, j] = dp[i - 1, j - 1];
                }
                else {
                    dp[i, j] = Math.Min(
                        dp[i - 1, j] + s1[i - 1],
                        dp[i, j - 1] + s2[j - 1]);
                }
            }
         }

         return dp[s1.Length, s2.Length];
    }
}