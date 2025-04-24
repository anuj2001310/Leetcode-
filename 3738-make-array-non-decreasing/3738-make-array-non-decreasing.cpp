class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int num = nums.front();
        int cnt = 1;
        int n = nums.size();
        for (uint i = 1; i < n; ++i)
            if (nums[i] >= num) {
                num = nums[i];
                ++cnt;
            }
        return cnt;
    }
};