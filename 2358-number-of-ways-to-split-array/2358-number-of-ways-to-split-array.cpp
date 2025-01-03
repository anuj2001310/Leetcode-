class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long l = 0, r = 0;

        for (auto& num : nums)
            r += num;

        int cnt = 0;

        for (int i = 0; i < n - 1; i++) {
            l += nums[i];
            r -= nums[i];

            if (l >= r)
                cnt++;
        }

        return cnt;
    }
};