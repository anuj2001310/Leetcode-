class Solution {
public:
    long long pairswithsumlessthanval(vector<int> nums, int val) {
        long long ans = 0;
        int n = nums.size(), i = 0, j = n - 1;
        while (i < j) {
            if (nums[i] + nums[j] < val) {
                ans += (j - i);
                i++;
            } else
                j--;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return pairswithsumlessthanval(nums, upper + 1) -
               pairswithsumlessthanval(nums, lower);
    }
};