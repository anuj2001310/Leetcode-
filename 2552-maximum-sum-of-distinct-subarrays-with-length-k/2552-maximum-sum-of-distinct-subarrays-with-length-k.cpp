class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long curr = 0;
        long long ans = 0;
        int mp[100001] = {0};
        int l = 0, r = 0;

        for (; r < nums.size(); r++) {
            curr += nums[r];
            if (++mp[nums[r]] > 1) {
                while (mp[nums[r]] > 1) {
                    curr -= nums[l];
                    --mp[nums[l++]];
                }
            }
            if (r - l + 1 >= k) {
                if (r - l + 1 > k) {
                    curr -= nums[l];
                    --mp[nums[l++]];
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};