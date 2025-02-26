class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = 0, mini = 0;
        int n{(int)nums.size()};
        int temp {0};
        for (int i{0}; i < n; i++) {
            temp += nums[i];
            maxi = fmax(maxi, temp);
            mini = fmin(mini, temp);
        }
        return maxi - mini;
    }
};