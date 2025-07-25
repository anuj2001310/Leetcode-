class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        sum += nums[n - 1];
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > 0 && nums[i] != nums[i + 1]) {
                sum += nums[i];
            }
        }
        return sum;
    }
};