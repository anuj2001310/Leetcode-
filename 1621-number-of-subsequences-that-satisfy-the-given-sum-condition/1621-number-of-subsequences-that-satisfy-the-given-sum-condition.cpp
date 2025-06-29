class Solution {
    const int mod = 1e9 + 7;

public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long ans = 0;
        vector<int> power(n);

        power[0] = 1;

        for (int i = 1; i < n; i++)
            power[i] = (power[i - 1] << 1) % mod;

        int l = 0, r = n - 1;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + power[r - l]) % mod;
                l++;
            } else
                r--;
        }

        return ans;
    }
};