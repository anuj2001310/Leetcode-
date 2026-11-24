class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 2;
        int pro = 1, l = 0, r = 0;
        for (; r < n; r++) {
            while (gcd(pro, nums[r]) > 1)
                pro /= nums[l++];
            pro *= nums[r];
            res = fmax(res, r - l + 1);
        }
        return res;
    }
};