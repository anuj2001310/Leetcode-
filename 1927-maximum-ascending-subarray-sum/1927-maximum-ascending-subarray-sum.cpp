class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int m = 0, t = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                t += nums[i];
            else {
                m = fmax(m, t);
                t = nums[i];
            }
        }
        return fmax(t, m);
    }
};