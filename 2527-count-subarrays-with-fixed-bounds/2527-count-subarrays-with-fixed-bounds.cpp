class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long cnt = 0;
        int left_bnd = -1, last_min = -1, last_max = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= minK and nums[i] <= maxK) {
                last_min = (nums[i] == minK) ? i : last_min;
                last_max = (nums[i] == maxK) ? i : last_max;
                cnt += max(0, min(last_min, last_max) - left_bnd);
            } else
                left_bnd = i, last_min = -1, last_max = -1;
        }
        return cnt;
    }
};