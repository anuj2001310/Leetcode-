class Solution {
private:
    int f(vector<int>& nums, int k, int i) {
        if (i == nums.size() - 1) {
            if (k == 0 && nums[i] == 0) {
                return 2;
            }
            if (k == 0 || nums[i] == k) {
                return 1;
            }
            return 0;
        }
        int nt = f(nums, k, i + 1);
        int t = 0;
        if (k >= nums[i]) {
            t = f(nums, k - nums[i], i + 1);
        }
        return t + nt;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int k = -1 * target;
        for (int i = 0; i < n; i++) {
            k += nums[i];
        }
        if (k < 0 || k & 1) {
            return 0;
        }
        k = k / 2;
        return f(nums, k, 0);
    }
};