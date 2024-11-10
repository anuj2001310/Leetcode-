class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 1e9;
        int l = 0, r = 0;
        vector<int> mark(32, 0);
        int x = 0;
        int bit;
        while (r < n) {
            x |= nums[r];
            if (nums[r] == 0)
                bit = 0;
            else
                bit = 31 - __builtin_clz(nums[r]);
            for (int i = 0; i <= bit && i < 32; i++) {
                if ((nums[r] >> i) & 1) {
                    mark[i]++;
                }
            }
            while (l <= r && x >= k) {
                res = min(res, r - l + 1);
                if (nums[l] == 0)
                    bit = 0;
                else
                    bit = 31 - __builtin_clz(nums[l]);
                for (int i = 0; i <= bit && i < 32; i++) {
                    if ((nums[l] >> i) & 1) {
                        mark[i]--;
                        if (mark[i] == 0) {
                            x ^= (1 << i);
                        }
                    }
                }
                l++;
            }
            r++;
        }

        return res == 1e9 ? -1 : res;
    }
};