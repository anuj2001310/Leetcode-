class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        array<int, 101> map;
        for (int i = n - 1; i >= 0; --i) {
            if (++map[nums[i]] > 1)
                return ceil((double)(i + 1) / 3);
        }
        return 0;
    }
};