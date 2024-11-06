class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, j; i < n;) {
            int c = __builtin_popcount(nums[i]);
            for (j = i++; i < n && c == __builtin_popcount(nums[i]); ++i)
                ;
            sort(nums.begin() + j, nums.begin() + i);
        }
        for (int i = 1; i < n; ++i)
            if (nums[i - 1] > nums[i])
                return 0;
        return 1;
    }
};