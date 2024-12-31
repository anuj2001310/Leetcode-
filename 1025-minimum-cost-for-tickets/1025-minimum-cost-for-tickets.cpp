class Solution {
private:
    unordered_set<int> need;
    int helper(int curr, vector<int>& days, vector<int>& costs, vector<int>& dp, int n) {
        if (curr > days[n - 1])
            return 0;
        if (dp[curr] != -1)
            return dp[curr];

        if (need.find(curr) == need.end())
            return helper(curr + 1, days, costs, dp, n);

        int oneDay = costs[0] + helper(curr + 1, days, costs, dp, n);
        int sevenDay = costs[1] + helper(curr + 7, days, costs, dp, n);
        int thirtyDay = costs[2] + helper(curr + 30, days, costs, dp, n);

        return dp[curr] = min({oneDay, sevenDay, thirtyDay});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int l = days[n - 1];
        vector<int> dp(l + 1, -1);

        for (int day : days)
            need.insert(day);

        return helper(1, days, costs, dp, n);
    }
};