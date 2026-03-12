class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int n = size(nums);
        vector<int> freq(1001, 0);
        for (int i = 0; i < n; ++i)
            freq[nums[i]]++;
        int ans = -1;
        for (int i = 0; i < 1001; ++i) {
            if (freq[i] == 0)
                continue;
            ans = max(ans, ((freq[i] == 1) ? i : -1));
        }
        return ans;
    }
};