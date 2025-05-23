class Solution {
    using ll = long long;
    typedef vector<ll> vll;

private:
    ll maxSumOfNodes(int index, int isEven, vector<int>& nums, int k,
                     vector<vector<long long>>& memo) {
        if (index == nums.size())
            return isEven == 1 ? 0 : INT_MIN;

        if (memo[index][isEven] != -1)
            return memo[index][isEven];

        ll noXorDone =
            nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);

        ll xorDone = (nums[index] ^ k) +
                     maxSumOfNodes(index + 1, isEven ^ 1, nums, k, memo);

        return memo[index][isEven] = fmax(xorDone, noXorDone);
    }

public:
    ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<vll> memo(nums.size(), vll(2, -1));
        return maxSumOfNodes(0, 1, nums, k, memo);
    }
};