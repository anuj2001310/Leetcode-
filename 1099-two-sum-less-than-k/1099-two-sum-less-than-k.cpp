class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int ans = -1;
        sort(begin(nums), end(nums));
        int n = size(nums);

        for (int i = 0; i < n && nums[i] < k; ++i) {
            auto j = lower_bound(begin(nums) + i + 1, end(nums), k - nums[i]) - nums.begin() - 1;
            if (j > i)
                ans = fmax(ans, nums[i] + nums[j]);
        }
        
        return ans;
    }
};