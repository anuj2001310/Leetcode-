#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cstdint>

class Solution {
public:
    long long maximumProfit(std::vector<int>& prices, int k) {
        int n = static_cast<int>(prices.size());

        // dp[j][i][trade]: best value at day i, after j actions (open/close), with trade=0(long),1(short)
        std::vector<std::vector<std::array<long long, 2>>> dp(
            2 * k, std::vector<std::array<long long, 2>>(n, {0LL, 0LL})
        );

        // pf_max[j][i][trade]: prefix max of dp[j][0..i][trade]
        const long long NEG_INF = std::numeric_limits<long long>::lowest();
        std::vector<std::vector<std::array<long long, 2>>> pf_max(
            2 * k, std::vector<std::array<long long, 2>>(n, {NEG_INF, NEG_INF})
        );

        long long ans = NEG_INF;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2 * k; ++j) {

                // Only 1 action per day; by day i, you can do at most i actions.
                if (j > i) break;

                for (int trade = 0; trade <= 1; ++trade) {
                    
                    long long prevMaxLong = 0, prevMaxShort = 0;
                    if (j - 1 >= 0 && i - 1 >= 0) {
                        prevMaxLong  = pf_max[j - 1][i - 1][0];
                        prevMaxShort = pf_max[j - 1][i - 1][1];
                    }

                    if ((j % 2) == 0) {
                        // Open new position (long or short)
                        long long base = std::max(prevMaxLong, prevMaxShort);
                        long long priceAdj = (trade == 0 ? -(long long)prices[i] : (long long)prices[i]);
                        dp[j][i][trade] = base + priceAdj;

                    } else {
                        // Close position (long or short)
                        if (trade == 0) {
                            dp[j][i][trade] = prevMaxLong + (long long)prices[i];
                        } else {
                            dp[j][i][trade] = prevMaxShort - (long long)prices[i];
                        }

                        ans = std::max(ans, dp[j][i][trade]);
                    }

                    long long prevPf = (i - 1 >= 0) ? pf_max[j][i - 1][trade] : NEG_INF;
                    pf_max[j][i][trade] = std::max(prevPf, dp[j][i][trade]);
                }
            }
               }

        return ans;
    }

};