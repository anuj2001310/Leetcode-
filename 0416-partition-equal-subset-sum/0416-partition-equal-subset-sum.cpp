class Solution {
private:
    bool memo(vector<int>& nums, vector<vector<int>>& dp, int sum, int idx) {
        if (sum == 0)
            return true;

        if (idx >= nums.size())
            return false;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        bool pick = false, non_pick = false;

        if (nums[idx] <= sum)
           pick = memo(nums, dp, sum - nums[idx], idx + 1);

        non_pick = memo(nums, dp, sum, idx + 1);

        return dp[idx][sum] = (pick or non_pick);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1)
            return false;

        vector<vector<int>> dp (n, vector<int> ((sum >> 1) + 1,  -1));
        
        return memo(nums, dp, sum / 2, 0);  
    }
};