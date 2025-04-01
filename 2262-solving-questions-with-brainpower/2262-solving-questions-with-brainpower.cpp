#define ll long long
using vll = vector<ll>;
class Solution {
private:
    ll memo(vector<vector<int>>& questions, vector<long long>& dp, int idx) {
        if (idx >= questions.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        ll take = questions[idx][0];
        int newidx = idx + questions[idx][1] + 1;

        if (newidx < questions.size())
            take += memo(questions, dp, newidx);

        ll skip = memo(questions, dp, idx + 1);

        return dp[idx] = fmax(take, skip);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vll dp(n + 1, -1);

        return memo(questions, dp, 0);
    }
};