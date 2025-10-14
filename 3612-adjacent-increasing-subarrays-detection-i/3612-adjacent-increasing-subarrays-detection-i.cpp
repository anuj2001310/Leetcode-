class Solution {
private:
    bool increasing(vector<int>& nums, int s, int e) {
        for (int i = s + 1; i < s + e; ++i) {
            if (nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }

public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i <= n - 2  * k; i++) {
            if (increasing(nums, i, k) && increasing(nums, i + k, k))
                return true;
        }
        return false;
    }
};