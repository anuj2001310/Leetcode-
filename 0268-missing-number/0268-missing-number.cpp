class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> freq(n + 1, false);
        for (auto& x : nums)
            freq[x] = true;

        int ans = -1;
        for (int i = 0; i < freq.size(); ++i)
            if (!freq[i]) {
                ans = i;
                break;
            }
        return ans;
    }
};