class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        auto check = [&](vector<int>& nums, int d, int n, int limit) -> bool {
            int s = 0;
            for (int i = 0; i < n; ++i)
                s += ceil(nums[i] / (double)d);
            return s <= limit;
        };
        int mx = -1;
        for (int i = 0; i < n; ++i)
            mx = fmax(mx, nums[i]);

        int l = 1, h = mx;
        while (l <= h) {
            int m = l + ((h - l) >> 1);
            if (check(nums, m, n, threshold))
                h = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};