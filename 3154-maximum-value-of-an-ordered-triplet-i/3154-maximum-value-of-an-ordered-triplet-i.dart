class Solution {
    int maximumTripletValue(List<int> nums) {
        int n = nums.length;
        int ans = 0, dmax = 0, imax = 0;
        for (int i = 0; i < n; ++i) {
            if (dmax * nums[i] > ans)
                ans = dmax * nums[i];
            if (imax - nums[i] > dmax)
                dmax = imax - nums[i];
            if (nums[i] > imax)
                imax = nums[i];
        }
        return ans;
    }
}