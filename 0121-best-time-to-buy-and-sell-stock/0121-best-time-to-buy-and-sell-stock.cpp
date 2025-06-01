class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        
        int f = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] < f)
                f = prices[i];
            else
                if (prices[i] - f > ans) {
                    ans = fmax(ans, prices[i] - f);
                }
        }
        return ans;               
    }
};