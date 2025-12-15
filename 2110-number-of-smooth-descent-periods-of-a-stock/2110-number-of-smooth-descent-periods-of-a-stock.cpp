class Solution {
    using ll = long long;

public:
    long long getDescentPeriods(vector<int>& prices) {
        ll ans = 1;
        int n = size(prices), p = 1;
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1)
                ++p;
            else
                p = 1;
            ans += p;
        }
        return ans;
    }
};