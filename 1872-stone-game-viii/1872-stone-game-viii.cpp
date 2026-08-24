class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        /*
        [-1,2,-3,4,-5]

        Prefix sum [-1,1,-2,2,-3]
        Alice first choice -> 1
        [1,-3,4,-5]
        prefix [1,-2,2,-3]
        Bob first choice -> 2
        [2,-5] => -3
        -4
        */
        int n = stones.size();
        vector<int> prefix(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        /*
        dp[i] => maximum score difference when the game is starting from prefix
        i dp[i] = max(prefix[i]-dp[i+1],dp[i+1]);
        */

        vector<int> dp(n, 0);
        dp[n - 1] = prefix[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = max(prefix[i] - dp[i + 1], dp[i + 1]);
        }
        return dp[1];
    }
};