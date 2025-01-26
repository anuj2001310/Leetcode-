class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto& num : nums)
            sum += num;
        int cnt = 0, leftSum = 0;
        for (int i = 0; i < n - 1; i++) {
            leftSum += nums[i];
            int rem = sum - leftSum;
            int val = abs(rem - leftSum);
            if ((val & 1) == 0)
                cnt++;
        }
        return cnt;
    }
};