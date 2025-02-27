class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 2; i < n; i++) {
            int l = 0;
            int r = i - 1;
            while (l < r) {
                if (arr[l] + arr[r] < arr[i])
                    l++;
                else if (arr[l] + arr[r] > arr[i])
                    r--;
                else {
                    dp[r][i] = dp[l][r] + 1;
                    maxi = max(maxi, dp[r][i]);
                    l++;
                    r--;
                }
            }
        }
        return maxi == 0 ? 0 : maxi + 2;
    }
};