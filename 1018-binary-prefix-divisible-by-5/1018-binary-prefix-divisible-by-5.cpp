class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n, false);
        int p = 0;

        for (int i = 0; i < n; i++) {
            p = ((p << 1) + nums[i]) % 5;
            ans[i] = (p == 0);
        }
        return ans;
    }
};