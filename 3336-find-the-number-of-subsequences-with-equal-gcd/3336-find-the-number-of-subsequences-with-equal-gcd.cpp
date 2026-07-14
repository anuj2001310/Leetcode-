#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int subsequencePairCount(std::vector<int>& nums) {
        constexpr int MOD = 1'000'000'007;

        int max_val = 0;
        for (int num : nums)
            max_val = fmax(max_val, num);
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));

        dp[0][0] = 1;

        for (int num : nums) {
            vector<vector<int>> next_dp = dp;

            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0)
                        continue;

                    long long current_ways = dp[g1][g2];

                    int n1 = std::gcd(g1, num);
                    next_dp[n1][g2] = (next_dp[n1][g2] + current_ways) % MOD;

                    int n2 = std::gcd(g2, num);
                    next_dp[g1][n2] = (next_dp[g1][n2] + current_ways) % MOD;
                }
            }
            dp = std::move(next_dp);
        }

        long long total_pairs = 0;
        for (int g = 1; g <= max_val; ++g) 
            total_pairs = (total_pairs + dp[g][g]) % MOD;

        return total_pairs;
    }
};