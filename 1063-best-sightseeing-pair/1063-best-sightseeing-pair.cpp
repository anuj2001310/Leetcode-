class Solution {
private:
    int score = 0;
    int memo(int idx, vector<int>& values, vector<int>& dp) {
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int j = values[idx], i = memo(idx - 1, values, dp);
        score = fmax(score, j + i - idx);
        return dp[idx] = fmax(i, j + idx);
    }

public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        vector<int> dp(n + 1, -1);
        memo(n - 1, values, dp);

        return score;
    }
};