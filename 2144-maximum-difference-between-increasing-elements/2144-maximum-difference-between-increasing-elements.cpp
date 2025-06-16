class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int rest = 0;
        int min_num = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            min_num = fmin(min_num, nums[i]);
            rest = fmax(rest, nums[i] - min_num);
        }
        return (rest == 0) ? -1 : rest;
    }
};