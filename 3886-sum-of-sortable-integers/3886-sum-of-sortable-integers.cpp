class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        auto ok = [&](int k) -> bool {
            int prevMax = 0;
            for (int s = 0; s < n; s += k) {
                int d = -1;
                for (int j = s; j < s + k - 1; ++j) {
                    if (nums[j] > nums[j + 1]) {
                        if (d != -1)
                            return false;
                        d = j;
                    }
                }
                int lo, hi;
                if (d == -1) {
                    lo = nums[s];
                    hi = nums[s + k - 1];
                } else {
                    if (nums[s + k - 1] > nums[s])
                        return false;
                    lo = nums[d + 1];
                    hi = nums[d];
                }
                if (prevMax > lo)
                    return false;
                prevMax = hi;
            }
            return true;
        };

        int ans = 0;
        for (int k = 1; k <= n; ++k)
            if (n % k == 0 && ok(k))
                ans += k;
        return ans;
    }
};