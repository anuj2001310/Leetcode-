class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;

public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < n; ++i)
            sum1 += s1[i];

        for (int i = 0; i < m; ++i)
            sum2 += s2[i];

        // dp[i][j] means max sum of common subsequence between s1[1..i],
        // s2[1..j]
        vvi dp(n + 1, vi(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1] * 2;
                else
                    dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return sum1 + sum2 - dp[n][m];
    }
};
/*
s1 = "sea", s2 = "eat"

    e a t
  0 0 0 0
s 0 0 0 0
e 0 1 1 1
a 0 1 2 2
*/
