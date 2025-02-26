class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPrefixSum = 0, maxPrefixSum = 0;

        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            minPrefixSum = fmin(minPrefixSum, prefixSum);
            maxPrefixSum = fmax(maxPrefixSum, prefixSum);
        }

        return maxPrefixSum - minPrefixSum;
    }
};