class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = size(nums);
        sort(begin(nums), end(nums));
        int mid = nums[n >> 1];
        int sum = 0;
        for (int i = 0; i < n; ++i) 
            sum += fabs(nums[i] - mid);
        return sum;
    }
};